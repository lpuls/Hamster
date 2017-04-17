#include "../AST/ASTNode.h"
#include "ToFile.h"
#include "../Tool.h"
#include <fstream>

std::map<std::string, int> Hamster::ToFile::_messageID;

Hamster::ToFile::ToFile()
{
	_bodyCount = 0;
	_packageName = "";

	
}

Hamster::ToFile::~ToFile()
{
}

std::string Hamster::ToFile::toFile(ASTNode * node)
{
    std::string code = "";
	const ASTType nodeType = node->type;  // typeid(*node).name();
    if (IS_EQUAL(AST::ASTType::AST_TYPE_BODY, nodeType))
    {
        ASTBody * body = dynamic_cast<ASTBody*>(node);
        IS_NULL(body);
        code += toBody(body);
    }
	else if (IS_EQUAL(AST::ASTType::AST_TYPE_PACKAGE, nodeType))
    {
        ASTPackage * package = dynamic_cast<ASTPackage*>(node);
        IS_NULL(package);
        code = toPackage(package);
    }
	else if (IS_EQUAL(AST::ASTType::AST_TYPE_IMPORT, nodeType))
    {
        ASTImport * import = dynamic_cast<ASTImport*>(node);
        IS_NULL(import);
        code = toImport(import);
    }
	else if (IS_EQUAL(AST::ASTType::AST_TYPE_GUIDANCE, nodeType))
    {
        ASTGuidance * packageName = dynamic_cast<ASTGuidance*>(node);
        IS_NULL(packageName);
        code = toPackageName(packageName);
    }
	else if (IS_EQUAL(AST::ASTType::AST_TYPE_DEF, nodeType))
    {
        ASTDef * def = dynamic_cast<ASTDef*>(node);
        IS_NULL(def);
        code = toDef(def);
    }
	else if (IS_EQUAL(AST::ASTType::AST_TYPE_ENUM, nodeType))
    {
        ASTEnum * astEnum = dynamic_cast<ASTEnum*>(node);
        IS_NULL(astEnum);
        code = toEnum(astEnum);
    }
	else if (IS_EQUAL(AST::ASTType::AST_TYPE_VALUE, nodeType))
    {
        ASTValue * value = dynamic_cast<ASTValue*>(node);
        IS_NULL(value);
        code = toValue(value);
    }
	else if (IS_EQUAL(AST::ASTType::AST_TYPE_CLASS, nodeType))
    {
        ASTClass * astClass = dynamic_cast<ASTClass*>(node);
        IS_NULL(astClass);
        code = toClass(astClass);
    }
    return code;
}

std::string Hamster::ToFile::getSpace()
{
    std::string space = "";
    for (int i = 0; i < _bodyCount; i++)
        space += "    ";
	return space;
}

std::string Hamster::ToFile::getSpace(int count)
{
	std::string space = "";
	for (int i = 0; i < count; i++)
		space += "    ";
	return space;
}

std::string Hamster::ToFile::toBody(ASTBody * body)
{
    std::string space = getSpace();
    std::string code = space + "{\n";
    for (int i = 0; i < body->getStatementCount(); i++)
    {
        std::string temp = toFile(body->getStatement(i));
        code += temp;
        code += "\n";
    }
    code = code + space + "}\n";
    return code;
}

std::string Hamster::ToFile::toPackage(ASTPackage * package)
{
	std::string code = getSpace() + "package ";
    
    IS_NULL(package->getPackageName());
    std::string packageName = toPackageName(package->getPackageName());

    IS_NULL(package->getBody());
    std::string packageBody = toBody(package->getBody());

    code += packageName;
    code += "\n";
    code += packageBody;

    return code;
}

std::string Hamster::ToFile::toImport(ASTImport * import)
{
    std::string code = getSpace() + "using ";
    
    IS_NULL(import->getPackageName());
    std::string packageName = toPackageName(import->getPackageName());

    code += packageName;
    code += ";\n";

    return code;
}

std::string Hamster::ToFile::toPackageName(ASTGuidance * packageName)
{
    if (packageName->getCount() <= 0)
        return "";
    std::string code = getSpace() + packageName->getNext(0);
    for (int i = 1; i < packageName->getCount(); i++)
    {
        code += ".";
        code += getSpace() + packageName->getNext(i);
    }
    code += ";";
    return code;
}

std::string Hamster::ToFile::toDef(ASTDef * def)
{
    std::string code = def->getType();
    code += " = ";
    code += def->getName();
    return code;
}

std::string Hamster::ToFile::toEnum(ASTEnum * astEnum)
{
    std::string code = getSpace() + astEnum->getName();
    IS_NULL(astEnum->getBody());
    code += toBody(astEnum->getBody());
    return code;
}

std::string Hamster::ToFile::toValue(ASTValue * value)
{
    std::string code = getSpace() + value->getValue().String + ",\n";
    return std::string();
}

std::string Hamster::ToFile::toClass(ASTClass * astClass)
{
    std::string code = getSpace() + astClass->getName() + "\n";
    std::string body = toBody(astClass->getBody());
    code += body;
    return code;
}

std::string Hamster::ToFile::toDefBody(ASTDef * def)
{
	return std::string();
}

std::string Hamster::ToFile::getMeta(vector<ASTDef*> body, int space)
{
	return std::string();
}

void Hamster::ToFile::initMessageID()
{
	ifstream infile("E:\\My\\C++\\Hamster\\Debug\\init.txt");
	if (!infile.is_open())   //若失败,则输出错误消息,并终止程序运行 
	{
		LOG_ERROR("Error: Unable to read from the configuration file");
		system("pause");
		exit(-1);
	}

	char buffer[1024] = "";
	while (!infile.eof())
	{
		infile.getline(buffer, 1024);
		string s(buffer);
		int separate = s.find(':');
		string key = s.substr(0, separate);
		string value = s.substr(separate + 1, s.size());
		int mid = MC::toInt(value);
		ToFile::_messageID[key] = mid;
	}
	infile.close(); 
}

void Hamster::ToFile::saveMessageID()
{
	ofstream  infile("E:\\My\\C++\\Hamster\\Debug\\init.txt");
	if (!infile.is_open())
	{
		LOG_ERROR("Error: Unable to save from the configuration file");
		system("pause");
		exit(-1);
	}
	for each (auto var in ToFile::_messageID)
	{
		string key = var.first;
		int value = var.second;
		infile << key;
		infile << ":";
		infile << value;
		infile << "\n";
	}
	infile.close();
}

bool Hamster::ToFile::addMessageID(std::string messageName, int ID)
{
	auto result = ToFile::_messageID.find(messageName);
	if (result != ToFile::_messageID.end())
		return false;
	ToFile::_messageID[messageName] = ID;
	return true;
}

int Hamster::ToFile::getMaxMessageID()
{
	int max = 0;
	for each (auto var in ToFile::_messageID)
	{
		int value = var.second;
		if (max < value)
			max = value;
	}
	return max + 1;
}
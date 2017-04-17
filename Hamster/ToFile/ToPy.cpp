#include "ToPy.h"
#include <string>

Hamster::ToPy::ToPy()
{
	ToFile::ToFile();
}

Hamster::ToPy::~ToPy()
{
}

std::string Hamster::ToPy::toBody(ASTBody * body)
{
	std::string code = "";
	for (int i = 0; i < body->getStatementCount(); i++)
	{
		std::string temp = toFile(body->getStatement(i));
		code = code + temp;
		code += "\n";
	}

	return code;
}

std::string Hamster::ToPy::toPackage(ASTPackage * package)
{
	std::string code = "";  // getSpace(level);

	IS_NULL(package->getBody());
	code += toBody(package->getBody());

	return code;
}

std::string Hamster::ToPy::toImport(ASTImport * import)
{
	string importCode = getSpace();
	importCode = importCode + "import " + toPackageName(import->getPackageName()) + "\n";
	return importCode;
}

std::string Hamster::ToPy::toPackageName(ASTGuidance * packageName)
{
	string name = getSpace();
	int packageNameCount = packageName->getCount();
	name = name + packageName->getNext(0);
	for (int i = 1; i < packageNameCount; i++)
	{
		name += ".";
		name += packageName->getNext(i);
	}
	return name;
}

std::string Hamster::ToPy::toDef(ASTDef * def)
{
	std::string code = getSpace();
	ASTNode *parent = def->getParent();
	// python 中，类内和类外的写法是不一样的
	if (nullptr == parent)
	{
		code = code + def->getName() + " = " + toDefBody(def);
	}
	else if (AST::ASTType::AST_TYPE_CLASS == parent->type)
	{
		code = code + "self." + def->getName() + " = " + toDefBody(def);
	}
	return code;
}

std::string Hamster::ToPy::toEnum(ASTEnum * astEnum)
{
	return std::string();
}

std::string Hamster::ToPy::toValue(ASTValue * value)
{
	return std::string();
}

std::string Hamster::ToPy::toClass(ASTClass * astClass)
{
	std::string code = getSpace();
	code += "class " + astClass->getName() + ":\n";
	std::string subSpace = getSpace(_bodyCount + 1);
	code = code + subSpace + "def __init__(self):\n";
	// python 的属性要定义在__init__函数内，因此会多一层
	_bodyCount += 2;
	std::string value = toBody(astClass->getBody());
	code += value;
	_bodyCount -= 2;
	return code;
}

std::string Hamster::ToPy::toDefBody(ASTDef * def)
{
	std::string code = "";
	if ("uint16" == def->getType() || "uint32" == def->getType()
		|| "int16" == def->getType() || "int32" == def->getType())
		return "0";
	else if ("string" == def->getType())
		return "''";
	else if ("float" == def->getType())
		return "0.0";
	else if ("bool" == def->getType())
		return "True";
	else if ("list" == def->getType())
		return "list()";
	else
		return def->getType() + "()";
	return code;
}


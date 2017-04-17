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

	// 设置包名
	if ("" != _packageName)
	{
		LOG_ERROR("Error: More than one package definition");
		exit(-1);
	}
	_packageName = package->getPackageName()->toString();

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
	// 获取类型并去掉\n一类的字符
	std::string className = astClass->getName();
	className = className.substr(0, className.find('\n'));

	int mid = 0;
	// 检查是否存在父类
	ASTValue *parentValue = astClass->getInherit();
	if (nullptr != parentValue)
	{
		std::string parentName = parentValue->getValue().String;
		if ("Message" == parentName)
		{
			mid = ToFile::getMaxMessageID();
			ToFile::addMessageID(className, mid);
		}
		className = className + "(" + parentName + ")";
	}

	// 合成类结构
	code += "class " + className + ":\n";

	std::string subSpace = getSpace(_bodyCount + 1);
	// 生成meta结构
	std::vector<ASTDef*> defs;
	ASTBody *defBody = dynamic_cast<ASTBody*>(astClass->getBody()->getStatement(0));
	if (nullptr == defBody)
		return "";
	size_t defsCoun = defBody->getStatementCount();
	for (size_t i = 0; i < defsCoun; i++)
	{
		ASTNode *node = defBody->getStatement(i);
		if (AST::ASTType::AST_TYPE_DEF == node->type)
			defs.push_back(dynamic_cast<ASTDef*>(node));
	}
	std::string meta = subSpace + getMeta(defs, _bodyCount + 2) + "\n";
	code += meta;
	code += (subSpace + "MID = " + MC::toStr(mid) + "\n");

	// 初始化属性
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

std::string Hamster::ToPy::getMeta(vector<ASTDef*> body, int space)
{
	std::string spaceStr = getSpace(space);
	std::string code = "META = (\n";
	for (int i = 0; i < body.size(); i++)
	{
		ASTDef *subDef = body[i];
		if (nullptr == subDef)
			continue;
		std::string sub = spaceStr;
		if ("uint16" == subDef->getType())
			sub += "( BinaryTypeDef.UINT16, " + subDef->getName() + ", ), \n";
		else if ("uint32" == subDef->getType())
			sub += "( BinaryTypeDef.UINT32, " + subDef->getName() + ", ), \n";
		else if ("int16" == subDef->getType())
			sub += "( BinaryTypeDef.INT16, " + subDef->getName() + ", ), \n";
		else if ("int32" == subDef->getType())
			sub += "( BinaryTypeDef.INT32, " + subDef->getName() + ", ), \n";
		else if ("string" == subDef->getType())
			sub += "( BinaryTypeDef.STRING, " + subDef->getName() + ", ), \n";
		else if ("float" == subDef->getType())
			sub += "( BinaryTypeDef.FLOAT, " + subDef->getName() + ", ), \n";
		else if ("bool" == subDef->getType())
			sub += "( BinaryTypeDef.BOOL, " + subDef->getName() + ", ), \n";
		else if ("list" == subDef->getType())
			sub += "( BinaryTypeDef.LIST, " + subDef->getName() + ", BinaryTypeDef.UINT16, ), \n";
		else
			sub += "( BinaryTypeDef.STRUCT, " + subDef->getName() + ", ), \n";
		code += sub;
	}
	code += spaceStr;
	code += ")";
	return code;
}


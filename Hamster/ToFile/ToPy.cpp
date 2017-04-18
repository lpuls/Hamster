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
	std::string subPath = package->getPackageName()->getNext(0);
	_packagePath = subPath;
	for (size_t i = 1; i < package->getPackageName()->getCount() - 1; i++)
	{
		subPath = package->getPackageName()->getNext(i);
		_packagePath += "\\";
		_packagePath += subPath;
	}
	_packageName = package->getPackageName()->getNext(package->getPackageName()->getCount() - 1);

	return code;
}

std::string Hamster::ToPy::toImport(ASTImport * import)
{
	std::string importCode = getSpace();
	std::string packageName = toPackageName(import->getPackageName());
	int count = import->getPackageName()->getCount();
	importCode = importCode + "from " + packageName + " import " + import->getPackageName()->getNext(count - 1);
	return importCode;
}

std::string Hamster::ToPy::toPackageName(ASTGuidance * packageName)
{
	string name = getSpace();
	int packageNameCount = packageName->getCount();
	name = name + packageName->getNext(0);
	for (int i = 1; i < packageNameCount - 1; i++)
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
	std::string code = "\nclass " + astEnum->getName() + ":\n";
	
	// 获取枚举下的所有定义
	std::vector<ASTValue*> defs;
	ASTBody *defBody = astEnum->getBody();
	if (nullptr == defBody)
		return "";
	size_t defsCoun = defBody->getStatementCount();
	for (size_t i = 0; i < defsCoun; i++)
	{
		ASTNode *node = defBody->getStatement(i);
		if (AST::ASTType::AST_TYPE_VALUE == node->type)
			defs.push_back(dynamic_cast<ASTValue*>(node));
	}

	_bodyCount += 1;
	for (size_t i = 0; i < defs.size(); i++)
	{
		std::string value = toValue(defs[i]);
		code += value;
		code = code + (" = " + MC::toStr(i));
		code += "\n";
	}
	_bodyCount -= 1;

	return code;
}

std::string Hamster::ToPy::toValue(ASTValue * value)
{
	std::string space = getSpace();
	return (space + value->getValue().String);
}

std::string Hamster::ToPy::toClass(ASTClass * astClass)
{
	std::string code = getSpace();
	// 获取类型并去掉\n一类的字符
	std::string className = astClass->getName();
	className = className.substr(0, className.find('\n'));

	int mid = 0;
	// 检查是否存在父类
	bool isMessageObject = false;
	ASTValue *parentValue = astClass->getInherit();
	if (nullptr != parentValue)
	{
		std::string parentName = parentValue->getValue().String;
		isMessageObject = isMessage(parentName);
		if (isMessageObject)
		{
			mid = ToFile::getMaxMessageID();
			ToFile::addMessageID(className, mid);
		}
		className = className + "(" + parentName + ")";
	}

	// 合成类结构
	code += "\nclass " + className + ":\n";

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
	if (isMessageObject)
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
	for (size_t i = 0; i < body.size(); i++)
	{
		ASTDef *subDef = body[i];
		if (nullptr == subDef)
			continue;
		std::string sub = spaceStr;
		std::string binaryTypeDef = ToFile::getType(subDef->getType());
		std::string otherInfo = getMeta(subDef->getOther());  // 目前暂不支持list<list<...>>这样的写法
		sub += "( " + binaryTypeDef + ", '" + subDef->getName() + "', " + otherInfo + " ), \n";
		code += sub;
	}
	code += spaceStr;
	code += ")";
	return code;
}

std::string Hamster::ToPy::getMeta(ASTNode *other)
{
	if (nullptr == other)
		return "";
	if (AST::ASTType::AST_TYPE_VALUE == other->type)
		return ToFile::getType((dynamic_cast<ASTValue*>(other))->getValue().String);
	else if (AST::ASTType::AST_TYPE_DEF == other->type)
		return getMeta(dynamic_cast<ASTDef*>(other));
	return "";
}



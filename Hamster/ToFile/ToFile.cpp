#include "ToFile.h"
#include "../Tool.h"

#define IS_EQUAL(type, value) typeid(ASTGuidance) == nodeType
#define IS_NULL(node) if (nullptr == node) { LOG_ERROR("null node"); return ""; }

Hamster::ToFile::ToFile()
{
}

Hamster::ToFile::~ToFile()
{
}

std::string Hamster::ToFile::toFile(ASTNode * node, int level)
{
    std::string code = "";
    const std::type_info& nodeType = typeid(*node);
    if (IS_EQUAL(ASTBody, nodeType))
    {
        ASTBody * body = dynamic_cast<ASTBody*>(node);
        IS_NULL(body);
        code += toBody(body, level);
    }
    else if (IS_EQUAL(ASTPackage, nodeType))
    {
        ASTPackage * package = dynamic_cast<ASTPackage*>(node);
        IS_NULL(package);
        code = toPackage(package, level);
    }
    else if (IS_EQUAL(ASTImport, nodeType))
    {
        ASTImport * import = dynamic_cast<ASTImport*>(node);
        IS_NULL(import);
        code = toImport(import, level);
    }
    else if (IS_EQUAL(ASTGuidance, nodeType))
    {
        ASTGuidance * packageName = dynamic_cast<ASTGuidance*>(node);
        IS_NULL(packageName);
        code = toPackageName(packageName, level);
    }
    else if (IS_EQUAL(ASTDef, nodeType))
    {
        ASTDef * def = dynamic_cast<ASTDef*>(node);
        IS_NULL(def);
        code = toDef(def, level);
    }
    else if (IS_EQUAL(ASTEnum, nodeType))
    {
        ASTEnum * astEnum = dynamic_cast<ASTEnum*>(node);
        IS_NULL(astEnum);
        code = toEnum(astEnum, level);
    }
    else if (IS_EQUAL(ASTValue, nodeType))
    {
        ASTValue * value = dynamic_cast<ASTValue*>(node);
        IS_NULL(value);
        code = toValue(value, level);
    }
    else if (IS_EQUAL(A, nodeType))
    {
        ASTClass * astClass = dynamic_cast<ASTClass*>(node);
        IS_NULL(astClass);
        code = toClass(astClass, level);
    }
    return code;
}

std::string Hamster::ToFile::getSpace(int level)
{
    std::string space = "";
    for (int i = 0; i < level; i++)
        space += "    ";
    return std::string();
}

std::string Hamster::ToFile::toBody(ASTBody * body, int level)
{
    std::string space = getSpace(level);
    std::string code = space + "{\n";
    for (int i = 0; i < body->getStatementCount(); i++)
    {
        std::string temp = toFile(body->getStatement(i), level + 1);
        code += temp;
        code += "\n";
    }
    code = code + space + "}\n";
    return code;
}

std::string Hamster::ToFile::toPackage(ASTPackage * package, int level)
{
    std::string code = getSpace(level) + "package ";
    
    IS_NULL(package->getPackageName());
    std::string packageName = toPackageName(package->getPackageName(), level);

    IS_NULL(package->getBody());
    std::string packageBody = toBody(package->getBody(), level + 1);

    code += packageName;
    code += "\n";
    code += packageBody;

    return code;
}

std::string Hamster::ToFile::toImport(ASTImport * import, int level)
{
    std::string code = getSpace(level) + "using ";
    
    IS_NULL(import->getPackageName());
    std::string packageName = toPackageName(import->getPackageName(), level);

    code += packageName;
    code += ";\n";

    return code;
}

std::string Hamster::ToFile::toPackageName(ASTGuidance * packageName, int level)
{
    if (packageName->getCount() <= 0)
        return "";
    std::string code = getSpace(level) + packageName->getNext(0);
    for (int i = 1; i < packageName->getCount(); i++)
    {
        code += ".";
        code += getSpace(level) + packageName->getNext(i);
    }
    code += ";";
    return code;
}

std::string Hamster::ToFile::toDef(ASTDef * def, int level)
{
    std::string code = def->getType();
    code += " = ";
    code += def->getName();
    return code;
}

std::string Hamster::ToFile::toEnum(ASTEnum * astEnum, int level)
{
    std::string code = getSpace(level) + astEnum->getName();
    IS_NULL(astEnum->getBody());
    code += toBody(astEnum->getBody(), level);
    return code;
}

std::string Hamster::ToFile::toValue(ASTValue * value, int level)
{
    std::string code = getSpace(level) + value->getValue().String + ",\n";
    return std::string();
}

std::string Hamster::ToFile::toClass(ASTClass * astClass, int level)
{
    std::string code = getSpace(level) + astClass->getName() + "\n";
    std::string body = toBody(astClass->getBody(), level);
    code += body;
    return code;
}

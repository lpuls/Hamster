#include "ToFile.h"
#include "../Tool.h"

Hamster::ToFile::ToFile()
{
}

Hamster::ToFile::~ToFile()
{
}

void Hamster::ToFile::toFile(std::string path, ASTNode * node, int level)
{
    const std::type_info& nodeType = typeid(*node);
    LOG_WARNING(nodeType.name());
}

std::string Hamster::ToFile::toBody(ASTBody * body)
{
    return std::string();
}

std::string Hamster::ToFile::toPackage(ASTPackage * package)
{
    return std::string();
}

std::string Hamster::ToFile::toImport(ASTPackage * import)
{
    return std::string();
}

std::string Hamster::ToFile::toPackageName(ASTGuidance * packageName)
{
    return std::string();
}

std::string Hamster::ToFile::toDef(ASTDef * def)
{
    return std::string();
}

std::string Hamster::ToFile::toEnum(ASTEnum * astEnum)
{
    return std::string();
}

std::string Hamster::ToFile::toValue(ASTValue * value)
{
    return std::string();
}

std::string Hamster::ToFile::toClass(ASTValue * astClass)
{
    return std::string();
}

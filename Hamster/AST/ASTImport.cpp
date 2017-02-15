#include "../Tool.h"
#include "ASTImport.h"

using namespace Hamster::AST;

ASTImport::ASTImport()
{
	// packageName = nullptr;
}

ASTImport::~ASTImport()
{
    /*
	if (nullptr != packageName)
	    delete(packageName);
	packageName = nullptr;
    */
}

std::string ASTImport::print()
{
    std::string log = "Import " + packageName;
    // MC::toStr(log, packageName);
    MC::log(log, DARK_GREEN);
    return log;
}
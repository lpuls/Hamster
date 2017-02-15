#include "../Tool.h"
#include "ASTImport.h"

using namespace Hamster::AST;

ASTImport::ASTImport()
{
	packageName = nullptr;
}

ASTImport::~ASTImport()
{
	if (nullptr != packageName)
		delete(packageName);
	packageName = nullptr;
}

void ASTImport::print()
{
	LOG_INFO("Import : ");
	if (nullptr != packageName)
		packageName->print();
}
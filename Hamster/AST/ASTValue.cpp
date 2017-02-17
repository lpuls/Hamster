#include "ASTValue.h"

using namespace Hamster::AST;

ASTValue::ASTValue() 
{
}

ASTValue::~ASTValue() 
{
}

void ASTValue::setValue(char* value)
{
	_value.String = value;
	_type = UASTValueType::STRING;
}

void ASTValue::setValue(int value)
{
	_value.Int = value;
	_type = UASTValueType::INTEGER;
}

void ASTValue::setValue(double value)
{
	_value.Double = value;
	_type = UASTValueType::DOUBLE;
}

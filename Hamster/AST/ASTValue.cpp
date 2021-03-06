#include "ASTValue.h"
#include "../Tool.h"

using namespace Hamster::AST;

ASTValue::ASTValue() 
{
	ASTNode::ASTNode();
	type = ASTType::AST_TYPE_VALUE;
}

ASTValue::~ASTValue() 
{
}

std::string Hamster::AST::ASTValue::toString()
{
    std::string value = "";
    switch (_type)
    {
    case UASTValueType::BOOL:
        return "";
    case UASTValueType::DOUBLE:
        return MC::toStr(value, _value.Double) + ";";
    case UASTValueType::INTEGER:
        return MC::toStr(value, _value.Int) + ";";
    case UASTValueType::STRING:
        return MC::toStr(value, _value.String) + ";";
    default:
        return "";
    }
   
}

void Hamster::AST::ASTValue::release()
{
}

void ASTValue::setValue(char* value)
{
	_value.String = MC::toChar(MC::toStr(value).c_str());
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

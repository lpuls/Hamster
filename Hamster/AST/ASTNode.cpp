#include "ASTNode.h"
#include "../Tool.h"
using namespace Hamster::AST;

ASTNode::ASTNode()
{
	type = ASTType::AST_TYPE_NODE;
	parent = nullptr;
}

ASTNode::~ASTNode()
{
}

std::string ASTNode::toString()
{
    MC::log("Just Node", DARK_GREEN);
    return "Just Node";
}

void ASTNode::release()
{

}

ASTNode* ASTNode::getParent()
{
	ASTNode* result = parent;
	while (nullptr != result && AST::ASTType::AST_TYPE_BODY == result->type)
	{
		result = result->parent;
	}
	return result;
}



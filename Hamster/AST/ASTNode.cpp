#include "ASTNode.h"
#include "../Tool.h"
using namespace Hamster::AST;

ASTNode::ASTNode()
{
	type = ASTType::AST_TYPE_NODE;
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



#include "ASTNode.h"
#include "../Tool.h"
using namespace Hamster::AST;

ASTNode::ASTNode()
{
}

ASTNode::~ASTNode()
{
}

std::string ASTNode::print()
{
    MC::log("Just Node", DARK_GREEN);
    return "Just Node";
}



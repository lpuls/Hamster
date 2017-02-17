#include "ASTBody.h"

using namespace Hamster::AST;

ASTBody::ASTBody()
{
}

ASTBody::~ASTBody()
{
}

void ASTBody::addStatement(ASTNode* node)
{
	_body.push_back(node);
}

ASTNode* ASTBody::getStatement(int index)
{
	if (index >= 0 && index < _body.size())
		return _body[index];
	return nullptr;
}

int ASTBody::getStatementCount()
{
	return _body.size();
}

std::string ASTBody::print()
{
	std::string log = "Body: \n";
	for (int i = 0; i < _body.size(); i++)
	{
		ASTNode* child = _body[i];
		log = log + child->print() + "\n";
	}
	return log;
}

void ASTBody::release()
{
	for (int i = 0; i < _body.size(); i++)
	{
		ASTNode* child = _body[i];
		if (nullptr != child)
		{
			child->release();
			delete(child);
		}
		child = nullptr;
	}
	_body.clear();
}
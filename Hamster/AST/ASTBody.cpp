#include "ASTBody.h"
#include "../Tool.h"

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

std::string ASTBody::toString()
{
	std::string log = "";
	for (int i = 0; i < _body.size(); i++)
	{
		ASTNode* child = _body[i];
        if (nullptr == child)
        {
            exit(0);
            LOG_ERROR("child is null");
            system("pause");
        }
		log = log + child->toString() + "\n";
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
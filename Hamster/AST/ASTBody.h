#ifndef __AST_BODY__
#define  __AST_BODY__

#include "ASTNode.h"
#include <vector>

namespace Hamster
{
	namespace AST
	{
		class ASTBody : public ASTNode
		{
		public:
			ASTBody();
			~ASTBody();

			std::string virtual toString() override;
			void virtual release() override;

			void addStatement(ASTNode* node);
			ASTNode* getStatement(int index);
			int getStatementCount();
		private:
			std::vector<ASTNode*> _body;
		};

	}
}

#endif
#ifndef __AST_NODE__
#define __AST_NODE__

#include <vector>
#include <string>
#include <iostream>

namespace Hamster
{
    namespace AST
    {
		enum ASTType
		{
			AST_TYPE_NODE,
			AST_TYPE_BODY,
			AST_TYPE_CLASS,
			AST_TYPE_DEF,
			AST_TYPE_ENUM,
			AST_TYPE_GUIDANCE,
			AST_TYPE_IMPORT,
			AST_TYPE_PACKAGE,
			AST_TYPE_STRUCT,
			AST_TYPE_VALUE
		};

		class ASTNode
		{
		public:
			ASTNode();
			~ASTNode();

			ASTType type;
	
			std::string virtual toString();
			void virtual release();
		};

    }
}

#endif // !__AST_NODE__

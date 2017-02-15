#ifndef __AST_NODE__
#define __AST_NODE__

#include <vector>
#include <string>
#include <iostream>

namespace Hamster
{
    namespace AST
    {
		class ASTNode
		{
		public:
			ASTNode();
			~ASTNode();

			std::string virtual print();
		};

    }
}

#endif // !__AST_NODE__

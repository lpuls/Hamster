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
        };

        class ASTStringValue
        {
        public:
            std::string value;
        };

        class ASTImport
        {
        public:
            std::string packageName;
        };

        class ASTGuidance
        {
        public:
            std::string name;
        };
    }
}

#endif // !__AST_NODE__

#ifndef __AST_STRUCT__
#define __AST_STRUCT__

#include "ASTNode.h"
#include "../Tool.h"

#include <string>

namespace Hamster
{
    namespace AST
    {
        class ASTStruct : public ASTNode
        {
        public:
            ASTStruct();
            ~ASTStruct();

            std::string virtual toString() override;
            void virtual release() override;

            SET(std::string, _name, Name);
            GET(std::string, _name, Name);

        protected:
            std::string _name;
        };
    }
}

#endif
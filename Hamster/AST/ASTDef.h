#ifndef __AST_DEF__
#define __AST_DEF__

#include "ASTNode.h"
#include "ASTValue.h"
#include "../Tool.h"

namespace Hamster
{
    namespace AST
    {
        class ASTDef : public ASTNode
        {
        public:
            ASTDef();
            ~ASTDef();

            std::string virtual toString() override;
            void virtual release() override;

            GET(std::string, _type, Type);
            SET(std::string, _type, Type);

            GET(std::string, _name, Name);
            SET(std::string, _name, Name);

        private:
            std::string _type;
            std::string _name;
        };
    }
}

#endif
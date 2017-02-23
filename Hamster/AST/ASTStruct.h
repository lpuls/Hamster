#ifndef __AST_STRUCT__
#define __AST_STRUCT__

#include "ASTNode.h"
#include "ASTBody.h"
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

            SET(ASTBody*, _body, Body);
            GET(ASTBody*, _body, Body);

        protected:
            std::string _name;
            ASTBody* _body;
        };
    }
}

#endif
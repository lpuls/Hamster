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
			void setType(std::string type);

            GET(std::string, _name, Name);
            SET(std::string, _name, Name);

			GET(ASTNode *, _other, Other);
			SET(ASTNode *, _other, Other);
        private:
            std::string _type;
            std::string _name;
			ASTNode *_other;
        };
    }
}

#endif
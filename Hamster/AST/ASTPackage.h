#ifndef __AST_PACKAGE__
#define __AST_PACKAGE__

#include "ASTNode.h"
#include "ASTGuidance.h"

namespace Hamster
{
    namespace AST
    {
        class ASTPackage : public ASTNode
        {
        public:
            ASTPackage();
            ~ASTPackage();

            std::string virtual print() override;

            ASTGuidance* packageName;

        };
    }
}

#endif // !__AST_PACKAGE__

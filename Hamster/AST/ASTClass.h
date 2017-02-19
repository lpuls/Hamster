#ifndef __AST_CLASS__
#define __AST_CLASS__

#include "ASTStruct.h"

namespace Hamster
{
    namespace AST
    {
        class ASTClass : public ASTStruct
        {
        public:
            ASTClass();
            ~ASTClass();

            std::string virtual toString() override;
            void virtual release() override;

        private:

        };
    }
}

#endif

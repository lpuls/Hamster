#ifndef __AST_ENUM__
#define __AST_ENUM__

#include "ASTStruct.h"
#include "ASTValue.h"
#include <vector>

namespace Hamster
{
    namespace AST
    {
        class ASTEnum : public ASTStruct
        {
        public:
            ASTEnum();
            ~ASTEnum();

            std::string virtual toString() override;
        };
    }
}

#endif
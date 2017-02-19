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
            void virtual release() override;

            void addEnum(ASTValue* enumValue);
            ASTValue* getEnum(int index);
            int getEnumCount();

        private:
            std::vector<ASTValue*> _enums;
        };
    }
}

#endif
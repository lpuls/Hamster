#ifndef __AST_CLASS__
#define __AST_CLASS__

#include "ASTStruct.h"
#include "ASTDef.h"

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

            int getDefCount();
            void addDef(ASTDef* def);
            ASTDef* getDef(int index);

        private:
            std::vector<ASTDef*> _defs;
        };
    }
}

#endif

#ifndef __AST_CLASS__
#define __AST_CLASS__

#include "ASTStruct.h"
#include "ASTValue.h"
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

			SET(ASTValue*, _inherit, Inherit);
			GET(ASTValue*, _inherit, Inherit);

            std::string virtual toString() override;

		protected:
			ASTValue *_inherit;
        };
    }
}

#endif

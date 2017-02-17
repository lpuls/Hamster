#ifndef __AST_PACKAGE__
#define __AST_PACKAGE__

#include "ASTNode.h"
#include "ASTBody.h"
#include "ASTGuidance.h"

#include <vector>

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
			void virtual release() override;

			SET(ASTGuidance*, _packageName, PackageName);
			GET(ASTGuidance*, _packageName, PackageName);

			GET(ASTBody*, _body, Body);
			SET(ASTBody*, _body, Body); 
		private:
			ASTGuidance* _packageName;
			ASTBody* _body;
        };
    }
}

#endif // !__AST_PACKAGE__

#ifndef __AST_IMPORT__
#define __AST_IMPORT__

#include "ASTNode.h"
#include "ASTGuidance.h"

#include <vector>
#include <string>
#include <iostream>

namespace Hamster
{
	namespace AST
	{
		class ASTImport : public ASTNode
		{
		public:
			ASTImport();
			~ASTImport();

			// ASTGuidance* packageName;
            std::string packageName;

			std::string virtual print() override;

		};
	}
}

#endif
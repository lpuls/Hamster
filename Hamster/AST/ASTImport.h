#ifndef __AST_IMPORT__
#define __AST_IMPORT__

#include "Node.h"
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

			ASTGuidance* packageName;

			void virtual print() override;

		};
	}
}

#endif
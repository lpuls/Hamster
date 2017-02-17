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

			std::string virtual print() override;
			void virtual release() override;

			SET(ASTGuidance*, _packageName, PackageName);
			GET(ASTGuidance*, _packageName, PackageName);

		private: 
			ASTGuidance* _packageName;

		};
	}
}

#endif
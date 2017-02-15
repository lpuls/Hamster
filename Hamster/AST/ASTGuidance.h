#ifndef __AST_GUIDANCE__
#define __AST_GUIDANCE__

#include "Node.h"

#include <vector>
#include <string>
#include <iostream>

namespace Hamster
{
	namespace AST
	{
		class ASTGuidance : public ASTNode
		{
		public:
			ASTGuidance();
			~ASTGuidance();

			std::string name;
			ASTGuidance* next;

			void virtual print() override;
		};

	}
}
#endif
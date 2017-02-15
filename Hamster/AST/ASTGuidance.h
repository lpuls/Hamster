#ifndef __AST_GUIDANCE__
#define __AST_GUIDANCE__

#include "ASTNode.h"

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

			std::string virtual print() override;


        private:
		};

	}
}
#endif
#ifndef __AST_GUIDANCE__
#define __AST_GUIDANCE__

#include "ASTNode.h"
#include "../Tool.h"

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

			std::string virtual print() override;
			void virtual release() override;

			void addNext(std::string name);
			std::string getNext(int index);
			int getCount();

        private:
			std::vector<string> _next;
		};

	}
}
#endif
#ifndef __HAMSTER_BISON__
#define __HAMSTER_BISON__

#include "../Tool.h"
#include "../AST/ASTBody.h"

#include <stack>

namespace Hamster
{
	namespace Yacc
	{
		class Bison
		{
		public:
			~Bison();
			
            static Bison* getInstance();

            void toFile(std::string fileName);

            void pushBody(AST::ASTBody* body);
            AST::ASTBody* popBody();
            bool isBottom();

		private:

			static Bison* _instance;

            // AST::ASTBody* _body;
            std::stack<AST::ASTBody*> _bodys;

			Bison();


		};
	}
}

#endif
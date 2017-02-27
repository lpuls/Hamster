#ifndef __HAMSTER_BISON__
#define __HAMSTER_BISON__

#include "../Tool.h"
#include "../AST/ASTBody.h"

#include <vector>

namespace Hamster
{
	namespace Yacc
	{
		class Bison
		{
		public:
			~Bison();
			
            static Bison* getInstance();

            void toFile(std::string fileName, std::string content);

            void pushBody(AST::ASTBody* body);
            AST::ASTBody* getBody(int index);
            int getBodys();
            void clear();

		private:

			static Bison* _instance;

            // AST::ASTBody* _body;
            std::vector<AST::ASTBody*> _bodys;

			Bison();


		};
	}
}

#endif
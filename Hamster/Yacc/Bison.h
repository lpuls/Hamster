#ifndef __HAMSTER_BISON__
#define __HAMSTER_BISON__

#include "../Tool.h"
#include "../AST/ASTBody.h"


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

            GET(AST::ASTBody*, _body, Body);
		private:

			static Bison* _instance;

            AST::ASTBody* _body;

			Bison();


		};
	}
}

#endif
#ifndef __HAMSTER_BISON__
#define __HAMSTER_BISON__

#include "../AST/ASTBody.h"
#include "../Tool.h"

namespace Hamster
{
	namespace Yacc
	{
		// AST::ASTBody* mainCode = new AST::ASTBody();
		class Bison
		{
		public:
			static Bison* getInstance();

			~Bison();

			GET(AST::ASTBody*, _mainCode, Body);

		private:
			AST::ASTBody* _mainCode;

			static Bison* _instance;

			Bison();
		};
	}
}

#endif
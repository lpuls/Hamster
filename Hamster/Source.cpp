#include "Yacc.h"
#include "ToFile/ToFile.h"
#include "ToFile/ToFile.h"
#include "ToFile/ToPy.h"
#include "Yacc/Bison.h"
#include "AST/ASTPackage.h"
#include "AST/ASTGuidance.h"
#include "AST/ASTDef.h"
#include "AST/ASTClass.h"
#include "AST/ASTBody.h"
#include "Tool.h"

using namespace Hamster;
using namespace Hamster::AST;
using namespace Hamster::Yacc;

int main(int argc, char ** argv)
{
	char * resultPath = "";
	if (argc >= 2)
	{
		resultPath = argv[0];
		ToFile::initMessageID();

		for (int i = 1; i < argc; i++)
		{
			yyInit(argv[i]);
			yyparse();
			yyOver();
			Hamster::AST::ASTBody * body = Bison::getInstance()->getBody(0);
			if (nullptr != body)
			{
				ToPy toPy;
				std::string content = toPy.toFile(body);
				ToFile::saveMessageID();
				LOG_INFO(content);
				std::string path = resultPath +  /*"Example\\Result\\"*/ toPy.getPackagePath();
				const char *command = MC::toChar(MC::toStr("md ", path).c_str());
				system(command);
				Bison::getInstance()->toFile(path + "\\" + toPy.getPackageName() + ".py", content);
			}
			Bison::getInstance()->clear();
		}
	}
	else
	{
		ToFile::initMessageID();

		yyInit("Example\\Proto\\Common.proto");
		yyparse();
		yyOver();
		Hamster::AST::ASTBody * body = Bison::getInstance()->getBody(0);
		if (nullptr != body)
		{
			ToPy toPy;
			std::string content = toPy.toFile(body);
			ToFile::saveMessageID();
			LOG_INFO(content);
			std::string path = "Example\\Result\\" +  toPy.getPackagePath();
			const char *command = MC::toChar(MC::toStr("md ", path).c_str());
			system(command);
			Bison::getInstance()->toFile(path + "\\" + toPy.getPackageName() + ".py", content);
		}
		Bison::getInstance()->clear();
	}

    system("pause");
    return 0;
}

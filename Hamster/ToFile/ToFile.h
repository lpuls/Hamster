#ifndef __TO_FILE__
#define __TO_FILE__

#include "../AST/ASTImport.h"
#include "../AST/ASTGuidance.h"
#include "../AST/ASTDef.h"
#include "../AST/ASTEnum.h"
#include "../AST/ASTValue.h"
#include "../AST/ASTClass.h"
#include "../AST/ASTPackage.h"
#include "../AST/ASTBody.h"
#include <string>

using namespace Hamster::AST;

#define IS_EQUAL(type, value) type == nodeType
#define IS_NULL(node) if (nullptr == node) { LOG_ERROR("null node"); return ""; }

namespace Hamster
{
	class ToFile
    {
    public:
        ToFile();
        ~ToFile();

        std::string toFile(ASTNode * node);
        std::string getSpace();
		std::string getSpace(int count);

        virtual std::string toBody(ASTBody * body);
        virtual std::string toPackage(ASTPackage * package);
        virtual std::string toImport(ASTImport * import);
        virtual std::string toPackageName(ASTGuidance * packageName);
        virtual std::string toDef(ASTDef * def);
        virtual std::string toEnum(ASTEnum * astEnum);
        virtual std::string toValue(ASTValue * value);
        virtual std::string toClass(ASTClass * astClass);
		virtual std::string toDefBody(ASTDef * def);

	protected:
		int _bodyCount;
    };
}

#endif
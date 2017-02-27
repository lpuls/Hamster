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

namespace Hamster
{
    class ToFile
    {
    public:
        ToFile();
        ~ToFile();

        virtual void toFile(std::string path, ASTNode * node, int level);

        virtual std::string toBody(ASTBody * body);
        virtual std::string toPackage(ASTPackage * package);
        virtual std::string toImport(ASTPackage * import);
        virtual std::string toPackageName(ASTGuidance * packageName);
        virtual std::string toDef(ASTDef * def);
        virtual std::string toEnum(ASTEnum * astEnum);
        virtual std::string toValue(ASTValue * value);
        virtual std::string toClass(ASTValue * astClass);

    private:

    };
}

#endif
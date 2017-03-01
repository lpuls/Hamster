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

        std::string toFile(ASTNode * node, int level);
        std::string getSpace(int level);

        virtual std::string toBody(ASTBody * body, int level);
        virtual std::string toPackage(ASTPackage * package, int level);
        virtual std::string toImport(ASTImport * import, int level);
        virtual std::string toPackageName(ASTGuidance * packageName, int level);
        virtual std::string toDef(ASTDef * def, int level);
        virtual std::string toEnum(ASTEnum * astEnum, int level);
        virtual std::string toValue(ASTValue * value, int level);
        virtual std::string toClass(ASTClass * astClass, int level);

    private:

    };
}

#endif
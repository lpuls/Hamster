#ifndef __TO_CSHARP__
#define __TO_CSHARP__

#include "ToFile.h"

namespace Hamster
{
    class ToCsharp : public ToFile
    {
    public:
        ToCsharp();
        ~ToCsharp();

        virtual std::string toBody(ASTBody * body, int level)  override;
        virtual std::string toPackage(ASTPackage * package, int level)  override;
        virtual std::string toImport(ASTImport * import, int level)  override;
        virtual std::string toPackageName(ASTGuidance * packageName, int level)  override;
        virtual std::string toDef(ASTDef * def, int level)  override;
        virtual std::string toEnum(ASTEnum * astEnum, int level)  override;
        virtual std::string toValue(ASTValue * value, int level)  override;
        virtual std::string toClass(ASTClass * astClass, int level)  override;

    private:

    };
}

#endif // !__TO_CSHARP__

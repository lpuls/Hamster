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

        virtual std::string toBody(ASTBody * body)  override;
        virtual std::string toPackage(ASTPackage * package)  override;
        virtual std::string toImport(ASTImport * import)  override;
        virtual std::string toPackageName(ASTGuidance * packageName)  override;
        virtual std::string toDef(ASTDef * def)  override;
        virtual std::string toEnum(ASTEnum * astEnum)  override;
        virtual std::string toValue(ASTValue * value)  override;
        virtual std::string toClass(ASTClass * astClass)  override;

    private:

    };
}

#endif // !__TO_CSHARP__

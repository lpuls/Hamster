#ifndef __TO_PY__
#define __TO_PY__

#include "ToFile.h"

namespace Hamster
{
	class ToPy : public ToFile
	{
	public:	
		ToPy();
		~ToPy();

		virtual std::string toBody(ASTBody * body)  override;
		virtual std::string toPackage(ASTPackage * package)  override;
		virtual std::string toImport(ASTImport * import)  override;
		virtual std::string toPackageName(ASTGuidance * packageName)  override;
		virtual std::string toDef(ASTDef * def)  override;
		virtual std::string toEnum(ASTEnum * astEnum)  override;
		virtual std::string toValue(ASTValue * value)  override;
		virtual std::string toClass(ASTClass * astClass)  override;
		virtual std::string toDefBody(ASTDef * def) override;
		virtual std::string getMeta(vector<ASTDef*> body, int space) override;
	};
}

#endif
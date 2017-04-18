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
#include <map>

using namespace Hamster::AST;

#define MESSAGE_CLASS_NAME "Message"
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
		GET(std::string, _packageName, PackageName);
		GET(std::string, _packagePath, PackagePath);

        virtual std::string toBody(ASTBody * body);
        virtual std::string toPackage(ASTPackage * package);
        virtual std::string toImport(ASTImport * import);
        virtual std::string toPackageName(ASTGuidance * packageName);
        virtual std::string toDef(ASTDef * def);
        virtual std::string toEnum(ASTEnum * astEnum);
        virtual std::string toValue(ASTValue * value);
        virtual std::string toClass(ASTClass * astClass);
		virtual std::string toDefBody(ASTDef * def);
		virtual std::string getMeta(vector<ASTDef*> body, int space);
		virtual std::string getMeta(ASTNode *other);

		static void initMessageID();
		static void saveMessageID();
		static bool addMessageID(std::string messageName, int ID);
		static int getMaxMessageID();
		static string getType(std::string type);
	protected:
		int _bodyCount;
		std::string _packageName;
		std::string _packagePath;
		static std::map<std::string, int> _messageID;
		static std::map<std::string, std::string> _typeDef;

		bool isMessage(std::string className);
    };
}

#endif
#ifndef __AST_VALUE__
#define __AST_VALUE__

#include "ASTNode.h"
#include "../Tool.h"
#include <string>

namespace Hamster
{
	namespace AST
	{
		union UASTValue
		{
			char* String;
			int Int;
			double Double;
		};

		enum UASTValueType
		{
			STRING,
			INTEGER,
			DOUBLE,
            BOOL,
		};

		class ASTValue : public ASTNode
		{
		public:
			ASTValue();
			~ASTValue();

			GET(UASTValueType, _type, Type);
			SET(UASTValueType, _type, Type);

			GET(UASTValue, _value, Value);
			
			void setValue(char* value);
			void setValue(int value);
			void setValue(double value);

		private: 
			UASTValueType _type;
			UASTValue _value;
		};

	}
}

#endif
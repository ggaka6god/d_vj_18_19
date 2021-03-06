#ifndef STRING_H
#define STRING_H

#include <string.h>

class String
{
public:
	String();

	String(const char* str);

	String(const String& str);

	~String();

	String operator= (const String & string);

private:
	char* str;
	unsigned int memory_allocated;
};

#endif // !STRING_H


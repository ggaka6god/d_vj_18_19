#include "String.h"



String::String() :str(nullptr), memory_allocated(0) {}

String::String(const char * str)
{

	memory_allocated = strlen(str) + 1;
	this->str = new char[memory_allocated];
	strcpy_s(this->str, memory_allocated, str);

}

String::String(const String& str)
{

	memory_allocated = str.memory_allocated;
	this->str = new char[memory_allocated];
	strcpy_s(this->str, memory_allocated, str.str);

}

String::~String()
{

	if (str != NULL)
		delete[] str;

}

String String::operator=(const String & string)
{

	delete[] str;
	//Acabar

	return String();
}


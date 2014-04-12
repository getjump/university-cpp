#include "String.h"

String::Char::Char(char &chr) : chr(chr) {}

String::Char::operator char()
{
	return this->chr;
}

String::Char& String::Char::operator=(const char &ch)
{
	this->chr = ch;
	return *this;
}

bool String::Char::operator==(const char &ch) const
{
	return this->chr == ch;
}
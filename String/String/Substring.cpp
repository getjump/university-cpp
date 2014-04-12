#include "String.h"

using namespace std;

String::Substring::Substring(String &str, int offset, int length) : offset(offset), str(&str), length(length) {}

String::Substring String::Substring::operator=(const String& str)
{
	if (str.length() != this->length - (length-offset))
	{
		int len = this->str->buf->length - this->length + str.length();
			
		char* newStr = new char[len];

		memcpy(newStr, this->str->buf->string, offset * sizeof(char));
		memcpy(newStr + offset * sizeof(char), str.buf->string, str.length());
		memcpy(
			newStr + (offset + str.length()) * sizeof(char),
			this->str->buf->string + (offset + length) * sizeof(char),
			(this->str->length() - offset) * sizeof(char)
			);

		newStr[len] = '\0';

		if (this->str->buf->capacity <= len)
		{
			int capacity = this->str->buf->capacity;
			--(*this->str->buf);
			this->str->buf = new Buffer(newStr, (int)(capacity * CAPACITY_CONSTANT));
		}
		else {
			this->str->buf->length = len;
			strcpy(this->str->buf->string, newStr);
		}

		this->length = str.length();
	}
	else {
		for (int i = offset; i < this->length; i++)
			this->str->buf->string[i] = str[i];
	}

	return *this;
}

String::Substring String::Substring::operator=(const char *str)
{
	return this->operator=(String(str));
}

String::Substring::operator String()
{
	char *str = new char[length];
	for (int i = offset; i < length; i++)
	{
		str[i - offset] = (*this->str)[i];
	}
	str[length] = '\0';
	return (*new String(str));
}
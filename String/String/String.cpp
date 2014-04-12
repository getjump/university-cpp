#include "String.h"

using namespace std;

String::String(const char* str) : buf(new Buffer(str, (int) (strlen(str) * CAPACITY_CONSTANT + 1)))
{
}

String::String(const char* str, int capacity) : buf(new Buffer(str, (int)(capacity * CAPACITY_CONSTANT)))
{
}

String::String(const String &str) : buf(str.buf)
{
	++(*buf);
}

String::String()
{
	this->buf = new Buffer();
}

String::~String()
{
	--(*buf);
}

int String::length() const
{
	return this->buf->length;
}

int String::capacity() const
{
	return this->buf->capacity;
}

void String::reserve(int res)
{
	this->buf = new Buffer(this->buf->string, res);
}

String::Substring String::operator()(int offset, int length)
{
	return Substring(*this, offset, length);
}

String String::operator=(const String &str)
{
	--(*buf);
	this->buf = str.buf;
	++(*buf);
	return *this;
}

String String::operator+(const String &str)
{
	return String(strcat(this->c_str(), str.c_str()));
}

String String::operator+=(const String &str)
{
	if (this->buf->capacity >= this->length() + str.length() + 1)
	{
		memcpy(this->buf->string + this->length() * sizeof(char), str.buf->string, (str.length()) * sizeof(char));
		(*this)[this->length() + str.length()] = '\0';
		this->buf->length++;
	}
	else {
		*this = String(strcat(this->c_str(), str.c_str()), this->buf->capacity);
	}
	return *this;
}

String::Substring String::substr(int offset, int length)
{
	return operator()(offset, length);
}

void String::remove(int offset, int length)
{
	String::Substring sub = this->substr(offset, length);
	sub = "";
}

void String::insert(int offset, const String &str)
{
	String::Substring sub = this->substr(offset, 0);
	sub = str;
}

String::Char String::operator[](int offset) const
{
	return this->buf->string[offset];
}

char* String::c_str() const
{
	char* str = new char[this->length()];
	strcpy(str, this->buf->string);
	return str;
}

bool String::operator!() const
{ 
	return buf->length == 0; 
}

bool String::operator==(const String &s) const
{ 
	return strcmp(buf->string, s.buf->string) == 0; 
}

bool String::operator!=(const String &s) const
{ 
	return strcmp(buf->string, s.buf->string) != 0; 
}

bool String::operator<(const String &s) const
{
	return strcmp(buf->string, s.buf->string) < 0; 
}

bool String::operator>(const String &s) const
{ 
	return strcmp(buf->string, s.buf->string) > 0; 
}

bool String::operator>=(const String &s) const
{ 
	return strcmp(buf->string, s.buf->string) >= 0; 
}

bool String::operator<=(const String &s) const
{ 
	return strcmp(buf->string, s.buf->string) <= 0; 
}

bool String::operator==(const char *s) const
{ 
	return strcmp(buf->string, s) == 0; 
}

bool String::operator!=(const char *s) const
{ 
	return strcmp(buf->string, s) != 0; 
}

bool String::operator<(const char *s) const
{ 
	return strcmp(buf->string, s) < 0; 
}

bool String::operator>(const char *s) const
{ 
	return strcmp(buf->string, s) > 0; 
}

bool String::operator>=(const char *s) const
{
	return strcmp(buf->string, s) >= 0; 
}

bool String::operator<=(const char *s) const
{
	return strcmp(buf->string, s) <= 0; 
}

int String::rc()
{
	return (int)(*this->buf);
}

ostream& operator<<(ostream &out, const String &s)
{
	out << s.c_str();
	return out;
}

istream &operator>>(istream &in, String &s) {
	char* buf = new char;
	in >> buf;
	--(*s.buf);
	s.buf = new String::Buffer(buf, (int) (strlen(buf) * CAPACITY_CONSTANT));
	return in;
}
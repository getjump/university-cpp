#include "String.h"

using namespace std;

String::Buffer::Buffer(const char* str, int capacity) : length(strlen(str)), references(1)
{
	this->capacity = capacity;
	string = new char[this->capacity];
	strcpy(string, str);
}

String::Buffer::Buffer()
{
	this->capacity = 15;
	this->references = 1;
	this->length = 0;
	this->string = new char;
}

String::Buffer::~Buffer()
{
	delete[] string;
	this->length = 0;
}

String::Buffer& String::Buffer::operator++()
{
	++this->references;
	return *this;
}

String::Buffer& String::Buffer::operator--()
{
	if (--this->references < 1)
		this->~Buffer();
	return *this;
}

String::Buffer::operator int()
{
	return this->references;
}
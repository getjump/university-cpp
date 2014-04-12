#ifndef ERROR_H_EXAMPLE
#define ERROR_H_EXAMPLE
/* Ошибка множественного определения функции */
/* Решение при помощи препроцессора */

#include <stdio.h>

void function()
{
	printf("Hello world!\n");
}

#endif
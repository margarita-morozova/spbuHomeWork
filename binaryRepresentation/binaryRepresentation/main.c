#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "ru - RU");
	system("chcp 1251");
	printf("Привет!");

	return 0;
}
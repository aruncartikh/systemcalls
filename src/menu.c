#include <stdlib.h>
#include <stdio.h>

int show_menu(void)
{
	int a;
	printf("1. Exit Example \n");
	printf("2. Fork Example \n");
	printf("3. File operation Example \n");
	scanf("%d",&a);
	return a;
}

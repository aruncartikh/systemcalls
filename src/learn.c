#include <stdio.h>
#include <string.h>


void add (int a, int b) {
	printf("Sum of a and b is %d \n",a + b);
}

void swap(int a, int b) {
	a = a+b;
	b = a - b;
	a = a - b;
	printf(" a : %d and b :%d \n",a,b);
}

void star_sequence_1()
{
	int i,j,k;
	for (i=1 ; i <= 5; i++) {
		for (j=5 ; j >=i; j--)
			printf(" ");
			for (k=1 ; k <=i; k++) {
				printf("*");
			}
		printf("\n");
	}
}

void star_sequence_2()
{
	int i,j,k;
	for (i=1 ; i <= 5; i++) {
			for (k=1 ; k <=i; k++) {
				printf("*");
			}
		printf("\n");
	}
}


void format(char *str)
{
	int i=0, len, j;
	len=strlen(str);
	printf("String before removing spaces = %s", str);

	for(i=0; i<len; i++)
	{
		if(str[i]==' ')
		{
			printf("Space detected at %d\n",i);
			for(j=i; j<len; j++)
			{
				str[j]=str[j+1];
			}
		len--;
		}
	}
	printf("String after removing spaces = %s", str);
}

int main() {
	int ch;
	int a, b;

	printf ("Enter your choice \n 1. Add \n 2. Swap two numbers\n 3. Star Sequence 1\n 4. Star Sequence 2\n 5. Format without space\n");
	scanf("%d",&ch);
	switch (ch) {
		case 1:
			printf("Enter two numbers\n");
			scanf("%d ",&a);
			scanf("%d ",&b);
			add (a,b);
			break;
		case 2:
			printf("Enter two numbers\n");
			scanf("%d ",&a);
			scanf("%d ",&b);
			swap (a,b);
			break;
		case 3:
			star_sequence_1();
			break;
		case 4:
			star_sequence_2();
			break;
		case 5:
			format("Attending an interview at Logitech");
			break;
		default:
			break;
	}
	return 0;
}
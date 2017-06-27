#include <stdio.h>

int main()
{
	int n;
	printf("Enter a positive number\n");
	scanf("%d", &n);
	(n%2==0) ? printf("It is even\n") : printf("It is odd\n");
}

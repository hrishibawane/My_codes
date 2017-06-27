#include <stdio.h>

int main()
{
	printf("Enter 2 nos.");
	int a, b, count = 0;
	scanf("%d %d", &a, &b);
	printf("%d - %d = ", a, b);
	while(count < b)
	{
		a--;
		count++;	
	}
	printf("%d\n", a);
}

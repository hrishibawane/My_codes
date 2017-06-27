#include <stdio.h>

int isPrime(int n)
{
	int i;
	for(i=2; i<n; i++)
		if(n%i==0)
			return 0;

	return 1;
}
int main()
{
	int n;
	printf("Enter a positive number\n");
	scanf("%d", &n);
	(isPrime(n)) ? printf("It is prime\n") : printf("It is not prime\n");
	(n%2==0) ? printf("It is even\n") : printf("It is not odd\n");
}

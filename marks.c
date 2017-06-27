#include <stdio.h>

int main()
{
	printf("Enter marks of student out of 100\n");
	double arr[5];
	int i;
	for(i=0; i<5; i++)
		scanf("%lf", &arr[i]);

	double total = 0;
	for(i=0; i<5; i++)
		total += arr[i];

	double ptg = total*0.2;
	printf("Total=%.2lf\nPercentage=%.2lf\n", total, ptg);
	
}

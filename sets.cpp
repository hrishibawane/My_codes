#include <stdio.h>

void getSet(int set[], int size)
{
	int i;
	for(i=0; i<size; i++)
		scanf("%d", &set[i]);
}
	
void printSet(int set[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", set[i]);
	printf("\n");
}
void sort(int set[], int size)
{
	int i, j;
	for(i=0; i<size-1; i++)
	{
		int flag = 0;
		for(j=i+1; j<size; j++)
		{
			if(set[i] > set[j])
			{
				int temp = set[i];
				set[i] = set[j];
				set[j] = temp;
				flag = 1;		
			}		
		}
		if(!flag) break;
	}
}
void setUnion(int setA[], int setB[], int n, int m)
{
	int setC[n+m];
	for(int i=0; i<n; i++)
		setC[i] = setA[i];
	for(int i=0, j=n; i<m; i++, j++)
		setC[j] = setB[i];

	sort(setC, n+m);
	for(int i=0; i<n+m; i++)
	{
		printf("%d ", setC[i]);
		if(setC[i]==setC[i+1]) i++;	
	}

}
void intersect(int setA[], int setB[], int n, int m)
{
	int setC[n+m];
	for(int i=0; i<n; i++)
		setC[i] = setA[i];
	for(int i=0, j=n; i<m; i++, j++)
		setC[j] = setB[i];

	sort(setC, n+m);
	for(int i=0; i<n+m-1; i++)
	{
		if(setC[i]==setC[i+1])
		{
			printf("%d ", setC[i]);
			i++;
		}
	}
}
int main()
{
	int n, m;
	printf("Enter size of set A\n");
	scanf("%d", &n);
	int setA[n];
	printf("Enter size of set B\n");
	scanf("%d", &m);
	int setB[n];
	printf("Enter elements of set A without repetition\n");
	getSet(setA, n);
	printf("Enter elements of set B without repetition\n");
	getSet(setB, m);
	printf("\nUnion : ");
	setUnion(setA, setB, n, m);
	printf("\nIntersection : ");
	intersect(setA, setB, n, m);
}

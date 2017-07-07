#include <stdio.h>
#include <stdlib.h>
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
	for(j=i+1; j<size; j++)
		if(set[i] > set[j])
		{
			int temp = set[i];
			set[i] = set[j];
			set[j] = temp;
		}
}
void setUnion(int setA[], int setB[], int n, int m)
{
int setC[n+m], i, j;
for(i=0; i<n; i++)
	setC[i] = setA[i];
for(i=0, j=n; i<m; i++, j++)
	setC[j] = setB[i];

sort(setC, n+m);
for(i=0; i<n+m; i++)
{
	printf("%d ", setC[i]);
	if(setC[i]==setC[i+1]) i++;
}
printf("\n");
}
void intersect(int setA[], int setB[], int n, int m)
{
int setC[n+m], i, j;
for(i=0; i<n; i++)
	setC[i] = setA[i];
for(i=0, j=n; i<m; i++, j++)
	setC[j] = setB[i];

sort(setC, n+m);
for(i=0; i<n+m-1; i++)
	if(setC[i]==setC[i+1])
	{
	printf("%d ", setC[i]);
	i++;
	}

printf("\n");
}
void difference(int setA[], int setB[], int n, int m)
{
int i, j;
for(i=0; i<n; i++)
	for(j=0; j<m; j++)
		if(setA[i]==setB[j])
		{
			setA[i] = -1;
			setB[j] = -1;
		}

for(i=0; i<n; i++)
	if(setA[i] != -1) printf("%d ", setA[i]);

}
void sym_diff(int setA[], int setB[], int n, int m)
{
	difference(setA, setB, n, m);
	difference(setB, setA, m, n);
}

int main()
{
int n, m;
printf("Enter size of set A\n");
scanf("%d", &n);
int setA[n];
printf("Enter size of set B\n");
scanf("%d", &m);
int setB[m];
printf("Enter elements of set A without repetition\n");
getSet(setA, n);
printf("Enter elements of set B without repetition\n");
getSet(setB, m);
int choice;
while(1)
{
	printf("Enter your choice:\n1. Union\n2. Intersection\n3. Difference\n4. Symmetric difference\n5. End\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: printf("Union: ");
		setUnion(setA, setB, n, m);
		break;
		case 2: printf("Intersection: ");
		intersect(setA, setB, n, m);
		break;
		case 3:
		{
		int x;
		printf("1. A-B\n2. B-A\n");
		scanf("%d", &x);
		(x==1) ? difference(setA, setB, n, m) : difference(setB, setA, m, n);
		break;
		}
		case 4: printf("Symmetric Difference: ");
		sym_diff(setA, setB, n, m);
		break;
		case 5: exit(0);
		default: printf("Wrong choice\n");
	}

}
return 0;
}

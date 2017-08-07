#include <stdio.h>
#include <stdlib.h>

int** mallocate(int row, int col)
{
int **a;
a = (int**)malloc(sizeof(int*)*row);
for(int i=0; i<row; i++)
	a[i] = (int*)malloc(sizeof(int*)*col);

return a;
}

void accept(int **m, int row, int col)
{
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			scanf("%d", *(m+i)+j);
}

void display(int **m, int row, int col)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			printf("%d ", *(*(m+i)+j));
		printf("\n");
	}
}

void add(int **a, int **b, int row, int col)
{
	int **c;
	c = mallocate(row, col);
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			*(*(c+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);

	display(c, row, col);
}

void multiply(int **a, int **b, int row1, int col1, int row2, int col2)
{
	int **c;
	c = mallocate(row1, col2);

	for(int i=0; i<row1; i++)
		for(int j=0; j<col2; j++)
			*(*(c+i)+j) = 0;

	for(int i=0; i<row1; i++)
		for(int j=0; j<col2; j++)
			for(int k=0; k<col1; k++)
				*(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);

	display(c, row1, col2);
}

void transpose(int **a, int row, int col)
{

	for(int i=0; i<col; i++)
	{
		for(int j=0; j<row; j++)
			printf("%d ", *(*(a+j)+i));

		printf("\n");
	}
}

int saddle_pt(int **a, int row, int col)
{
	for(int i=0; i<row; i++)
	{
		int min = *(*(a+i)+0), ind;
		for(int j=0; j<col; j++)
			if(*(*(a+i)+j) < min)
			{
				min = *(*(a+i)+j);
				ind = j;
			}

		int k;
		for(k=0; k<row; k++)
			if(*(*(a+k)+ind) > min)
				break;

		if(k==row) return min;
	}
	return -1;
}

int main()
{
int ch;
int **a, **b, row1, row2, col1, col2;
while(1)
{
	printf("\nEnter your choice:\n1. Accept\n2. Display\n3. Add\n4. Multiply\n5. Transpose\n6. Saddle point\n7. End\n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: printf("\nEnter row & col size of matrix A: ");
			scanf("%d %d", &row1, &col1);
			a = mallocate(row1, col1);
			printf("\nEnter elements of matrix A:");
			accept(a, row1, col1);
			printf("\nEnter row & col size of matrix B: ");
			scanf("%d %d", &row2, &col2);
			b = mallocate(row1, col1);
			printf("\nEnter elements of matrix B:");
			accept(b, row2, col2);
			break;

		case 2: printf("\nElements of A\n"); display(a, row1, col1);
			printf("\nElements of B\n"); display(b, row2, col2);
			break;

		case 3: if(row1==row2 && col1==col2)
			{
				printf("\nMatrix A + Matrix B =\n");
				add(a, b, row1, col1);
			}
			else printf("\nAddition not possible");
			break;

		case 4: if(col1==row2)
			{
				printf("\nMatrix A x Matrix B = \n");
				multiply(a, b, row1, col1, row2, col2);
			}
			else printf("\nMultiplication not possible");
			break;

		case 5: printf("\nTranspose of A:\n"); transpose(a, row1, col1);
			printf("\nTranspose of B:\n"); transpose(b, row2, col2);
			break;

		case 6: printf("\n");
			int ans = saddle_pt(a, row1, col1);
			(ans == -1) ? printf("No saddle point in A\n") : printf("Saddle Point in A: %d\n", ans);
			int res = saddle_pt(b, row1, col1);
			(res == -1) ? printf("No saddle point in B\n") : printf("Saddle Point in B: %d\n", res);
			break;

		case 7: exit(0);

	}
}
}

//bubble, selection, insertion

#include <stdio.h>
#include <string.h>
void bubble(char s[20][20], int n)
{
	char temp[20];
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n-i-1; j++)
			if(strcmp(s[j], s[j+1])>0)
			{
				strcpy(temp, s[j]);
				strcpy(s[j], s[j+1]);
				strcpy(s[j+1], temp);
			}

	for(int i=0; i<n; i++)
		printf("%s ", s[i]);
}

void selection(char s[20][20], int n)
{
	char temp[20];
	for(int i=0; i<n; i++)
	{
		int max = i;
		for(int j=i+1; j<n; j++)
			if(strcmp(s[j], s[max])>0)
				max = j;

		strcpy(temp, s[max]);
		strcpy(s[max], s[i]);
		strcpy(s[i], temp);
	}

	for(int i=0; i<n; i++)
		printf("%s ", s[i]);
}


void insertion(char s[20][20], int n)
{
	char temp[20];
	for(int i=1; i<n; i++)
	{
		strcpy(temp, s[i]);
		int j = i;
		while(j>0 && strcmp(s[j-1], temp)<0)
		{
			strcpy(s[j], s[j-1]);
			j--;
		}
		strcpy(s[j], temp);
	}

	for(int i=0; i<n; i++)
		printf("%s ", s[i]);
}


int main()
{
	char s[20][20];
	int n;
	printf("Enter no. of strings\n");
	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%s", s[i]);

	printf("\nBubble Sort: "); bubble(s, n);
	printf("\nSelection Sort: "); selection(s, n);
	printf("\nInsertion Sort: "); insertion(s, n);

}

#include <stdio.h>
#include <stdlib.h>

int length(char *s)
{
	int n=0;
	while(*s != '\0')
	{
		n++;
		s++;
	}
	return n;
}
void reverse(char *s)
{
	int n = length(s);
	char *temp;
	for(int i=0; i<n/2; i++)
	{
		*temp = *(s+i);
		*(s+i) = *(s+n-i-1);
		*(s+n-i-1) = *temp;
	}
	printf("%s\n", s);
}

int palindrome(char *s)
{
	int n = length(s);
	for(int i=0; i<n/2; i++)
		if(*(s+i) != *(s+n-i-1))
			return 1;

	return 0;
}

int scomp(char *x, char *y)
{
	int cmp = 0;
	while(*x != '\0' || *y != '\0')
	{
		if(*x > *y)
		{
			cmp = 1; break;
		}
		else if(*x < *y)
		{
			cmp = -1; break;
		}
		else
		{
			cmp = 0;
			x++;
			y++;
		}
	}
	return cmp;
}
void scopy(char *x, char *y)
{
	int i;
	for(i=0; i<length(y); i++)
		*(x+i) = *(y+i);

	*(x+i) = '\0';
	printf("Copied string : %s\n", x);
}

int search(char *s, char c, int i)
{
int n = length(s), a;
for(a=i; a<n; a++)
{
    if(*(s+a)==c)
        return a;
}
return -1;
}

int substring(char *x, char *y)
{
int n = length(x), m = length(y), i;

for(i=0; i<n; i++)
{
    int ind = search(x, *(y+0), i);
    int c = 0;
    if(ind == -1)
        return ind;
    else
    {
        int j, k;
        for(j=ind, k=0; j<n && k<m; j++, k++)
            if(*(x+j) == *(y+k))
                c++;
        if(c==m)
            return 1;
    }
}
    return -1;
}


int main()
{
int choice;
char *x = malloc(50);
char *y = malloc(50);
while(1)
{
printf("Enter your choice\n1. Length of string\n2. Palindrome\n3. String comparison\n4. Copy string\n5. Reverse String\n6. Substring\n7. Exit\n");
scanf("%d", &choice);
switch(choice)
{
    case 1: printf("Enter a string\n");
    scanf("%s", x);
    printf("\n%d\n", length(x));
    break;

    case 2: printf("Enter a string\n");
    scanf("%s", x);
    palindrome(x)==0 ? printf("It is a palindrome\n") : printf("It is not a palindrome\n");
    break;

    case 3: printf("Enter 2 strings\n");
    scanf("%s %s", x, y);
    int res = scomp(x, y);
    if(res==-1) printf("String 2 is greater than 1\n");
    else if(res==0) printf("Strings are equal\n");
    else printf("String 1 is greater than 2\n");
    break;

    case 4: printf("Enter 2 strings\n");
    scanf("%s %s", x, y);
    scopy(x, y);
    break;

    case 5: printf("Enter a string\n");
    scanf("%s", x);
    reverse(x);
    break;

    case 6: printf("Enter 2 strings\n");
    scanf("%s %s", x, y);
    int ans = substring(x, y);
    ans == -1 ? printf("Not a subtring\n") : printf("It is a substring\n");
    break;

    case 7: exit(0);
}
}
return 0;
}

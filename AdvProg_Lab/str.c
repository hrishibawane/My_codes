#include <stdio.h>
#include <stdlib.h>
void accept(char str[])
{
printf("Enter a string\n");
scanf("%s", str);
}

int length(char str[])
{
int i=0, n=0;
while(str[i] != '\0')
{
	i++,
	n++;
}
return n;
}

int palindrome(char str[])
{
int len = length(str), i;
for(i=0; i<len/2; i++)
    if(str[i] != str[len-i-1])
        return -1;

return 0;
}

int scomp(char str1[], char str2[])
{
int i=0;
while(str1[i]!='\0' || str2[i]!='\0')
{
    if(str1[i] != str2[i])
        return str1[i]-str2[i];
    i++;
}
return 0;
}

void scopy(char str1[], char str2[])
{
int i=0, len=length(str1);
for(i=0; i<len; i++)
    str2[i] = str1[i];

printf("\nString 2 is now = %s\n", str2);
}

void reverse(char str[])
{
int len = length(str), i;
for(i=0; i<len/2; i++)
{
char temp = str[i];
str[i] = str[len-i-1];
str[len-i-1] = temp;
}
printf("\n%s", str);
}

int search(char s[], char c, int i)
{
int n = length(s), a;
for(a=i; a<n; a++)
{
    if(s[a]==c)
        return a;
}
return -1;
}

int substring(char s1[], char s2[])
{
int n = length(s1), m = length(s2), i;

for(i=0; i<n; i++)
{
    int ind = search(s1, s2[0], i);
    int c = 0;
    if(ind == -1)
        return ind;
    else
    {
        int j, k;
        for(j=ind, k=0; j<n && k<m; j++, k++)
            if(s1[j]==s2[k])
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
char str1[20], str2[20];
while(1)
{
printf("Enter your choice\n1. Length of string\n2. Palindrome\n3. String comparison\n4. Copy string\n5. Reverse String\n6. Substring\n7. Exit\n");
scanf("%d", &choice);
switch(choice)
{
    case 1: printf("Enter a string\n");
    scanf("%s", str1);
    printf("\n%d\n", length(str1));
    break;
    case 2: printf("Enter a string\n");
    scanf("%s", str1);
    palindrome(str1)==0 ? printf("It is a palindrome\n") : printf("It is not a palindrome\n");
    break;
    case 3: printf("Enter 2 strings\n");
    scanf("%s %s", str1, str2);
    int res = scomp(str1, str2);
    if(res<0) printf("String 2 is greater than 1\n");
    else if(res==0) printf("Strings are equal\n");
    else printf("String 1 is greater than 2\n");
    break;
    case 4: printf("Enter 2 strings\n");
    scanf("%s %s", str1, str2);
    scopy(str1, str2);
    break;
    case 5: printf("Enter a string\n");
    scanf("%s", str1);
    reverse(str1);
    break;
    case 6: printf("Enter 2 strings\n");
    scanf("%s %s", str1, str2);
    int ans = substring(str1, str2);
    ans == -1 ? printf("Not a subtring\n") : printf("It is a substring\n");
    break;
    case 7: exit(0);
}
}
return 0;
}
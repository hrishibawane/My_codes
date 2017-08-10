/*
Create a database using array of structures and perform following operations on it:
1.Create database
2.Display database
3.Add record
4.Search record
5.Modify record
6.Delete record
*/
#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct
{
	int e_id;
	char name[30];
	int salary;
}employee;

void insert_rec(employee emp[MAX],int ino);
int search_rec(employee emp[MAX], int id);
void display_rec(employee emp[MAX]);
void delete_rec(employee emp[MAX]);
void initialize(employee emp[MAX]);
int findfree(employee emp[MAX]);
void delete(employee emp[MAX]);
void modify_rec(employee emp[MAX]);

int iCount = 0;

int main()
{
int opt,ino,id,flag;
employee emp[MAX];
initialize(emp);
do
{
	printf("\n1. Insert a record");
	printf("\n2. Search a record");
	printf("\n3. Display  a record");
	printf("\n4. Modify  a record");
	printf("\n5. Delete a record logically");
	printf("\n6. Delete a record");
	printf("\nEnter your choice: ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
		printf("\nHow many records do you wish to enter? ");
		scanf("%d", &ino);
		insert_rec(emp,ino);
		break;

		case 2:
		printf("\nEnter employee ID: ");
		scanf("%d",&id);
		flag = search_rec(emp,id);
		if(flag!=-1)
		{
			printf("\nRecord exists.");
			printf("\n\tID\tName\tSalary");
			printf("\n\t%d\t%s\t%d",emp[flag].e_id,emp[flag].name,emp[flag].salary);
		}
		else
		printf("\nRecord does not exist.");
		break;

		case 3:
		display_rec(emp);
		break;

		case 4:
		modify_rec(emp);
		break;

		case 5:
		delete_rec(emp);
		break;

		case 6:
		delete(emp);
		break;

		default:
		printf("\nEnter valid option.");
	}
}while(opt!=7);
}

void initialize(employee emp[MAX])
{
int i;
for(i=0;i<MAX;i++)
	emp[i].e_id = 0;

}

void insert_rec(employee emp[MAX],int no)
{
int id,j,i,flag=0,pos;
for(j=0;j<no;j++)
{
	printf("Enter a employee ID:");
	scanf("%d",&id);
	flag = search_rec(emp,id);
	if(flag!=-1)
	{
		printf("\nRecord exists.\n");
		j--;
		flag = 0;
	}
	else
	{
		pos = findfree(emp);
		if(pos==-1)
		{
			printf("\nEmpty slot is not present.");
			return;
		}
		emp[pos].e_id = id;
		printf("\nEnter your name: ");
		scanf("%s",emp[pos].name);
		printf("\nEnter your salary: ");
		scanf("%d",&emp[pos].salary);
		printf("\nRecord entered succesfully.");
		printf("\n");
		iCount++;
	}
}
}

int findfree(employee emp[MAX])
{
int i;
for(i=0;i<MAX;i++)
{
if(emp[i].e_id==0)
	return i;
}
return -1;

}

int search_rec(employee emp[MAX], int id)
{
int i;
for(i=0;i<iCount;i++)
{
if(id==emp[i].e_id)
{
return i;
}
}
return -1;
}

void display_rec(employee emp[MAX])
{
int i;
printf("\n*******************Records*******************\n");
for(i=0;i<iCount;i++)
{
if(emp[i].e_id!=0)
{
printf("\nEmployee ID: %d",emp[i].e_id);
printf("\nName: %s",emp[i].name);
printf("\nSalary: %d",emp[i].salary);
}
}
}

void modify_rec(employee emp[MAX])
{
int id,i,flag=0;
printf("\nEnter an employee ID: ");
scanf("%d",&id);
flag = search_rec(emp,id);
if(flag!=-1)
{
printf("\nEnter your name: ");
scanf("%s",emp[flag].name);
printf("\nEnter your salary: ");
scanf("%d",&emp[flag].salary);
}
else
printf("Record does not exist.");
}

void delete_rec(employee emp[MAX])
{
int id, flag = 0;
printf("\nEnter a employee ID: ");
scanf("%d", &id);
flag = search_rec(emp,id);
if(flag!=-1)
{
emp[flag].e_id = 0;
printf("\nRecord Deleted.");
}
else
printf("\nRecord not found.");
}

void delete(employee emp[MAX])
{
int id,i,flag=0;
printf("\nEnter employee ID: ");
flag = search_rec(emp,id);
for(i=flag+1;i<MAX;i++)
{
emp[i-1].e_id = emp[i].e_id;
strcpy(emp[i-1].name,emp[i].name);
emp[i-1].salary = emp[i].salary;
}
printf("\nRecord deleted succesfully.");
}

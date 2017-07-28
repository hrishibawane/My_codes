#include <stdio.h>

struct employee
{
char name[20];
int emp_id;
double salary;	
};

typedef struct employee employee;

void insert(employee emp[], int n)
{
printf("\nEnter employee details");
for(int i=0; i<n; i++)
{
	printf("\nName: ");
	scanf("%s", emp[i].name);
	printf("\nEmployee id: ");
	scanf("%d", &emp[i].emp_id);
	printf("\nSalary: ");
	scanf("%lf", &emp[i].salary);
}
}

void display(employee emp[], int n)
{
printf("\n**************Employee Records**************\n");
for(int i=0; i<n; i++)
{
	printf("\nEmployee name: %s", emp[i].name);
	printf("\nEmployee id: %d", emp[i].emp_id);
	printf("\nEmployee salary: %.2lf", emp[i].salary);
}
}

int search(employee emp[], int id, int n)
{
	for(int i=0; i<n; i++)
		if(emp[i].emp_id==id)
			return i;	
	
	return -1;
}

int main()
{
	int n;
	printf("\nEnter no. of records to fill: ");
	scanf("%d", &n);
	employee emp[n];
	insert(emp, n);
	display(emp, n);
	int ind = search(emp, 420, n);
	printf("%s\n%d\n%lf", emp[ind].name, emp[ind]emp_id; emp[ind].salary)
}

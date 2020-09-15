#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main()
{
	struct Employee employee = {0};
	struct Employee minPaid;
	struct Employee employees[MAX_EMPLOYEES];

	int numEmployee = 0;
	char boolean = 'y';

	do{
		printf("Name: ");
		scanf("%s", &employee.name);

		printf("Salary: ");
		scanf("%d", &employee.salary);

		employees[numEmployee] = employee;

		if(numEmployee < MAX_EMPLOYEES-1){
			printf("Add another user (y/n)? ");
			scanf(" %c", &boolean);
			printf("\n");
		}
		numEmployee++;

	} while (numEmployee < MAX_EMPLOYEES && boolean=='y');

	heapSort(employees, numEmployee);
	
	printList(employees, numEmployee);

	return 0;
}


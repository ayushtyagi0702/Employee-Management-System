#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// use to define MAX_EMPLOYEES as constant value of 10
#define MAX_EMPLOYEES 10

// using structure -it is a user based datatype 
typedef struct {
    char name[50];
    int employeeID;
    char designation[50];
    int experience; // in years
    int age;
    char joiningDate[11]; // Format: YYYY-MM-DD
} Employee;

void addEmployee(Employee employees[], int *count);
void deleteEmployee(Employee employees[], int *count, int employeeID);
void searchEmployee(Employee employees[], int count, int employeeID);
void sortEmployeesByAge(Employee employees[], int count);
void displayEmployees(Employee employees[], int count);

int main() {
    Employee employees[MAX_EMPLOYEES];  // using array of structur to save the data of employees
    int count = 0;
    int choice, employeeID;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Search Employee\n");
        printf("4. Sort Employees by Age\n");
        printf("5. Display All Employees\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &employeeID);
                deleteEmployee(employees, &count, employeeID);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &employeeID);
                searchEmployee(employees, count, employeeID);
                break;
            case 4:
                sortEmployeesByAge(employees, count);
                break;
            case 5:
                displayEmployees(employees, count);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full!\n");
        return;
    }
    
    Employee *emp = &employees[*count];
    
    printf("Enter Name: ");
    scanf("%s", emp->name);
    printf("Enter Employee ID: ");
    scanf("%d", &emp->employeeID);
    printf("Enter Designation: ");
    scanf("%s", emp->designation);
    printf("Enter Experience (in years): ");
    scanf("%d", &emp->experience);
    printf("Enter Age: ");
    scanf("%d", &emp->age);
    printf("Enter Joining Date (YYYY-MM-DD): ");
    scanf("%s", emp->joiningDate);

    (*count)++;
    printf("Employee added successfully!\n");
}

void deleteEmployee(Employee employees[], int *count, int employeeID) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (employees[i].employeeID == employeeID) {
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            printf("Employee with ID %d deleted successfully!\n", employeeID);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", employeeID);
    }
}

void searchEmployee(Employee employees[], int count, int employeeID) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (employees[i].employeeID == employeeID) {
            printf("Employee found:\n");
            printf("Name: %s\n", employees[i].name);
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Designation: %s\n", employees[i].designation);
            printf("Experience: %d years\n", employees[i].experience);
            printf("Age: %d\n", employees[i].age);
            printf("Joining Date: %s\n", employees[i].joiningDate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", employeeID);
    }
}

void sortEmployeesByAge(Employee employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (employees[j].age > employees[j + 1].age) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("Employees sorted by age successfully!\n");
}

void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to display!\n");
        return;
    }

    printf("\nEmployee List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Employee ID: %d\n", employees[i].employeeID);
        printf("Designation: %s\n", employees[i].designation);
        printf("Experience: %d years\n", employees[i].experience);
        printf("Age: %d\n", employees[i].age);
        printf("Joining Date: %s\n", employees[i].joiningDate);
        printf("---------------------------\n");
    }
}

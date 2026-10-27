#include <stdio.h>
#include "employees.h"

void addEmployee(void) {
    printf("Adding employee...\n");
}

void listEmployees(void) {
    printf("Listing employees...\n");
}

double calculatePayrollTotal(void) {
    return 0.0;
}

void saveEmployee(int id, const char *name, double salary) {
    FILE *fp = fopen("data/employees.txt", "a");
    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }
    fprintf(fp, "%d %s|%.2f\n", id, name, salary);
    fclose(fp);
}

void loadEmployees(void) {
    FILE *fp = fopen("data/employees.txt", "r");
    int id;
    char name[50];
    double salary;
    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }
    while (fscanf(fp, "%d %49[^ ]|%lf\n", &id, name, &salary) == 3) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", id, name, salary);
    }
    fclose(fp);
}
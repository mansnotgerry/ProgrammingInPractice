#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"

int main(void) {
    printf("Municipal Financial Management System\n");
    addEmployee();
    listEmployees();
    addBudget();
    employeeReport();
    
    return 0;
}
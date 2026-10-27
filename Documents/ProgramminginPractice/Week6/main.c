#include <stdio.h>
#include <string.h>

int main() {
    float salaries[5];
    float totalSalary = 0, avgSalary, highestSalary, lowestSalary;
    float searchSalary;
    int foundSalary = 0;

    printf("--- Employee Salaries ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        totalSalary += salaries[i];

        if (i == 0) {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        } else {
            if (salaries[i] > highestSalary) highestSalary = salaries[i];
            if (salaries[i] < lowestSalary) lowestSalary = salaries[i];
        }
    }

    avgSalary = totalSalary / 5;
    printf("\nAll Salaries:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", salaries[i]);
    }
    printf("\nAverage Salary: %.2f\n", avgSalary);
    printf("Highest Salary: %.2f\n", highestSalary);
    printf("Lowest Salary: %.2f\n", lowestSalary);

    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);
    for (int i = 0; i < 5; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary found at position %d\n", i);
            foundSalary = 1;
            break;
        }
    }
    if (!foundSalary) {
        printf("Salary not found.\n");
    }

    float budgets[5];
    float totalBudget = 0, avgBudget;
    
    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        totalBudget += budgets[i];
    }
    avgBudget = totalBudget / 5;

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                float temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nTotal Budget: %.2f\n", totalBudget);
    printf("Average Budget: %.2f\n", avgBudget);
    printf("Sorted Budgets (Lowest to Highest):\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f\n", budgets[i]);
    }

    char registrations[3][20];
    char searchReg[20];
    int foundReg = 0;

    printf("\n--- Vehicle Registration Numbers ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nAll Vehicle Registrations:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", registrations[i]);
    }

    printf("\nEnter registration number to search for: ");
    scanf("%19s", searchReg);
    for (int i = 0; i < 3; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration found at position %d\n", i);
            foundReg = 1;
            break;
        }
    }
    if (!foundReg) {
        printf("Registration number not found.\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

// Global storage for suppliers (Week 7 extension)
char supplierNames[MAX_SUPPLIERS][100];
char emails[MAX_SUPPLIERS][100];
char phones[MAX_SUPPLIERS][30];
char towns[MAX_SUPPLIERS][50];
int supplierCount = 0;

// Function Prototypes (Week 8)
void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main() {
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer

        switch(choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4: {
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT (15%): %.2f\n", calculateVAT(amount));
                break;
            }
            case 5: {
                float basic, housing, transport;
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                printf("Gross Salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            }
            case 6: {
                float revenue, expenses;
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                float result = calculateBudget(revenue, expenses);
                printf("Budget Balance: %.2f\n", result);
                if (result > 0) printf("Status: SURPLUS\n");
                else if (result < 0) printf("Status: DEFICIT\n");
                else printf("Status: BALANCED\n");
                break;
            }
            case 7: {
                int searchId, pos;
                printf("Enter employee ID (try 101-105): ");
                scanf("%d", &searchId);
                pos = searchEmployee(searchId, employeeIDs, 5);
                if (pos != -1) {
                    printf("Employee found at position %d\n", pos);
                } else {
                    printf("Employee not found (-1).\n");
                }
                break;
            }
            case 8:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please select between 1 and 8.\n");
        }
    } while(choice != 8);

    return 0;
}

void displayMenu() {
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Search Employee\n");
    printf("8. Exit\n");
    printf("Enter choice: ");
}

void addSupplier() {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier storage is full!\n");
        return;
    }
    printf("Enter supplier name: ");
    fgets(supplierNames[supplierCount], sizeof(supplierNames[supplierCount]), stdin);
    supplierNames[supplierCount][strcspn(supplierNames[supplierCount], "\n")] = '\0';

    printf("Enter email: ");
    fgets(emails[supplierCount], sizeof(emails[supplierCount]), stdin);
    emails[supplierCount][strcspn(emails[supplierCount], "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(phones[supplierCount], sizeof(phones[supplierCount]), stdin);
    phones[supplierCount][strcspn(phones[supplierCount], "\n")] = '\0';

    printf("Enter town: ");
    fgets(towns[supplierCount], sizeof(towns[supplierCount]), stdin);
    towns[supplierCount][strcspn(towns[supplierCount], "\n")] = '\0';

    supplierCount++;
    printf("Supplier added successfully.\n");
}

void displaySupplier() {
    if (supplierCount == 0) {
        printf("No suppliers recorded yet.\n");
        return;
    }
    printf("\n--- SUPPLIER DETAILS ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("Supplier %d:\n", i + 1);
        printf("  Name: %s\n", supplierNames[i]);
        printf("  Email: %s\n", emails[i]);
        printf("  Phone: %s\n", phones[i]);
        printf("  Town: %s\n", towns[i]);
    }
}

void searchSupplier() {
    char searchName[100];
    int found = 0;
    printf("Enter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(supplierNames[i], searchName) == 0) {
            printf("Supplier found!\n");
            printf("  Name: %s\n  Email: %s\n  Phone: %s\n  Town: %s\n", 
                   supplierNames[i], emails[i], phones[i], towns[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Supplier not found.\n");
    }
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    
}
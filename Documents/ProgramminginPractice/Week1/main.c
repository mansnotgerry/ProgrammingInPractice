#include <stdio.h>
#include <string.h>

int main() {
    // Variable declarations
    char municipalityName[100];
    char mayorName[100];
    int population;

    // 1 & 2. Display System Title and Welcome Message
    printf("==================================================\n");
    printf("      Municipal Financial Management System       \n");
    printf("==================================================\n");
    printf("        Welcome to Windhoek Municipality          \n");
    printf("==================================================\n\n");

    // 3. Prompt user for input
    printf("Enter Municipality Name: ");
    fgets(municipalityName, sizeof(municipalityName), stdin);
    // Remove trailing newline character left by fgets
    municipalityName[strcspn(municipalityName, "\n")] = 0;

    printf("Enter Mayor's Name: ");
    fgets(mayorName, sizeof(mayorName), stdin);
    mayorName[strcspn(mayorName, "\n")] = 0;

    printf("Enter Population: ");
    scanf("%d", &population);

    // 4. Display formatted report
    printf("\n\n==================================================\n");
    printf("            MUNICIPAL INFORMATION REPORT          \n");
    printf("==================================================\n");
    printf(" Municipality Name : %s\n", municipalityName);
    printf(" Mayor's Name      : %s\n", mayorName);
    printf(" Population        : %d\n", population); // Formatted integer output
    printf("==================================================\n");

    return 0;
}
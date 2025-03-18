#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char firstName[50], lastName[50];
    int birthDay, birthMonth, birthYear;

    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int currentDay = tm.tm_mday;
    int currentMonth = tm.tm_mon + 1;  // In struct tm, months start from 0 (January = 0)
    int currentYear = tm.tm_year + 1900; // tm.tm_year is the number of years since 1900

    // Request first name, last name, and birthdate
    printf("Enter your first name: ");
    scanf("%s", firstName);  // Input first name
    printf("Enter your last name: ");
    scanf("%s", lastName);  // Input last name
    printf("Enter your birth date (day month year): ");
    scanf("%d %d %d", &birthDay, &birthMonth, &birthYear);  // Input birth day, month, and year

    // Calculate age
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;  // If birthday hasn't occurred yet this year, subtract 1 from age
    }

    // Display the greeting with calculated age
    printf("\nHello, %s %s!\n", firstName, lastName);
    printf("You are %d years old.\n", age);

    return 0;
}

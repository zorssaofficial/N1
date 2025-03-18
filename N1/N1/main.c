#include <stdio.h>
#include <time.h>

int main() {
    int birth_day, birth_month, birth_year;
    int current_day, current_month, current_year;

    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    current_day = tm.tm_mday;
    current_month = tm.tm_mon + 1; // months start from 0
    current_year = tm.tm_year + 1900; // year starts from 1900

    // Ask for the birth date
    printf("Enter your birth date (dd mm yyyy): ");
    scanf("%d %d %d", &birth_day, &birth_month, &birth_year);

    // Calculate the age
    int age = current_year - birth_year;

    // If the birthday hasn't occurred yet this year, subtract 1 year
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--;
    }

    // Output the result
    printf("Your age: %d years\n", age);

    return 0;
}
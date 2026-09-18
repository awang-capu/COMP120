// Part 1 solution

#include <stdio.h>

int main(void) {
    char name[26] = "Frank";       // Stores your name in a variable
    char size = 'M';               // Stores your cup size as a single character 'S', 'M', or 'L'
    float price_per_cup = 3.2f;    // Price for a medium ('M') cup (this should allow decimals!)
    int cups_per_day = 2;          // Stores the number of cups of coffee you drink per day
    int days_per_month = 30;       // Assume there are 30 days in a month
    int months_per_year = 12;

    float monthly_cost;
    double yearly_cost;

    // TODO: calculate monthly cost
    monthly_cost = price_per_cup * cups_per_day * days_per_month;

    // TODO: calculate yearly cost from monthly cost
    yearly_cost = monthly_cost * months_per_year;

    // TODO: print info to match the sample run below
    printf("Hello, %s! Thanks for participating.\n", name);
    printf("You drink %d cups of size %c coffee per day.\n", cups_per_day, size);
    printf("Your monthly cost on coffee is $%.2f.\n", monthly_cost);
    printf("Your yearly cost on coffee is $%.2lf.\n", yearly_cost);

    return 0;
}




// // Part 2 solution

// #include <stdio.h>

// int main(void) {
//     char name[26];
//     int cups_per_day;
//     float price_per_cup;

//     int days_per_month = 30;
//     int months_per_year = 12;

//     float monthly_cost;
//     double yearly_cost;

//     // Prompt for and read the user's name
//     printf("What is your name: ");
//     scanf("%s", name);

//     // TODO: prompt for and read cups per day
//     printf("Enter how many cups of coffee you drink per day: ");
//     scanf("%d", &cups_per_day);

//     // TODO: prompt for and read price per cup
//     printf("Enter the price per cup: ");
//     scanf("%f", &price_per_cup);

//     // TODO: calculate monthly cost
//     monthly_cost = price_per_cup * cups_per_day * days_per_month;

//     // TODO: calculate yearly cost from monthly cost
//     yearly_cost = monthly_cost * months_per_year;

//     // TODO: print a summary addressed to the friend, by name
//     printf("Hey %s! You drink %d cups of coffee per day.\n", name, cups_per_day);
//     printf("Your monthly cost on coffee is $%f\n", monthly_cost);
//     printf("Your monthly cost on coffee is $%lf\n", yearly_cost);

//     return 0;
// }

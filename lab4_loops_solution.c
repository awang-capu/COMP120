// Part 1

#include <stdio.h>

int main() {

    int sum = 0;
    for (int i = 2; i <= 10; i = i + 2)
        sum += i;
    printf("The sum of even integers from 1 to 10 is: %d.\n", sum);

    return 0;
}

// // Part 2

// #include <stdio.h>

// int main(void) {
//     int num;
//     printf("Enter a whole number:\n");
//     scanf("%d", &num);
//     while (num > 0) {
//         printf("%d\n", num % 2);
//         num = num / 2;
//     }
//     return 0;
// }

// // Part 3

// #include <stdio.h>

// int main(void) {
//     int n = 10;

//     // Header row
//     printf("   |");
//     for (int j = 1; j <= n; j++) {
//         printf("%4d", j); // Print the number using at least 4 characters,
//     }                     // padding with spaces on the left if it is shorter
//     printf("\n");

//     // Divider
//     printf("---+");
//     for (int j = 1; j <= n; j++) {
//         printf("----");
//     }
//     printf("\n");

//     // Table body
//     for (int i = 1; i <= n; i++) {
//         printf("%2d |", i);
//         for (int j = 1; j <= n; j++) {
//             printf("%4d", i * j);
//         }
//         printf("\n");
//     }

//     return 0;
// }

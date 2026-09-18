#include <stdio.h>

int main(void) {
    // Hardcoded for testing; generalize later by
    // reading the user's input with scanf()
    int a_3_digit_number = 146;
    
    int ones_digit = a_3_digit_number % 10;
    int tmp_num = a_3_digit_number / 10;

    int tens_digit = tmp_num % 10;
    tmp_num = tmp_num / 10;

    int hundreds_digit = tmp_num % 10;

    printf("Hundreds digit is: %d\n", hundreds_digit);
    printf("Tens digit is: %d\n", tens_digit);
    printf("Ones digit is: %d\n", ones_digit);
    return 0;
}


// Method 2:
// #include <stdio.h>

// int main(void) {
//     int a_3_digit_number;
//     printf("Please enter a 3-digit integer:\n");
//     scanf("%d", &a_3_digit_number);
    
//     int hundreds_digit = a_3_digit_number / 100;
//     int tens_digit = a_3_digit_number % 100 / 10;
//     int ones_digit = a_3_digit_number % 10;

//     printf("Hundreds digit is: %d\n", hundreds_digit);
//     printf("Tens digit is: %d\n", tens_digit);
//     printf("Ones digit is: %d\n", ones_digit);
//     return 0;
// }

// Method 3:
// int tens_digit = a_3_digit_number / 10 % 10;

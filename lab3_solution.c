// Part 1

#include <stdio.h>

int main(void) {
    int test_score;
    printf("Enter your test score (0-100): ");
    scanf("%d", &test_score);

    if (test_score < 0 || test_score > 100) {
        printf("Invalid score. Please enter an integer between 0 and 100.\n");
        return 1;
    }

    char letter_grade;
    if (test_score >= 90) {
        letter_grade = 'A';
    } else if (test_score >= 80) {
        letter_grade = 'B';
    } else if (test_score >= 70) {
        letter_grade = 'C';
    } else if (test_score >= 60) {
        letter_grade = 'D';
    } else if (test_score >= 50) {
        letter_grade = 'E';
    } else {
        letter_grade = 'F';
    }
    printf("Your score is %d%%, so your letter grade is %c.\n", test_score, letter_grade);
    return 0;
}

// Part 2

#include <stdio.h>

int main(void) {
    char button_input;
    printf("Press a button (o/f/u/d/+/-): ");
    scanf("%c", &button_input);
    switch (button_input) {
        case 'O': // This line is optional
        case 'o':
            printf("Power is on.\n");
            break;
        case 'F': // This line is optional
        case 'f':
            printf("Power is off.\n");
            break;
        case 'U': // This line is optional
        case 'u':
            printf("Channel up.\n");
            break;
        case 'D': // This line is optional
        case 'd':
            printf("Channel down.\n");
            break;
        case '+':
            printf("Volume up.\n");
            break;
        case '-':
            printf("Volume down.\n");
            break;
        default:
            printf("Invalid input.\n");
            break;
    }
    return 0;
}

// Part 3

#include <stdio.h>

int main(void) {
    char var_name[50];
    printf("Enter a variable name: ");
    scanf("%s", var_name); 
    if (var_name[0] == '_' || (var_name[0] >= 'a' && var_name[0] <= 'z') || (var_name[0] >= 'A' && var_name[0] <= 'Z')) {
        printf("\"%s\" may be a valid name for a variable.\n", var_name);
    } else {
        printf("\"%s\" is NOT a valid name for a variable.\n", var_name);
    }
    return 0;
}


// Part 3 - Solution 2

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char var_name[50];
    printf("Enter a variable name: ");
    scanf("%s", var_name); 
    if (var_name[0] == '_' || isalpha(var_name[0])) {
        printf("\"%s\" may be a valid name for a variable.\n", var_name);
    } else {
        printf("\"%s\" is NOT a valid name for a variable.\n", var_name);
    }
    return 0;
}

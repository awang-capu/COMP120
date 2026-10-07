#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ============================================================
// Function 1: int sum_integers(int num)
//
// Return the sum of all integers from 0 to num, inclusive.
//
// Examples:
//     sum_integers(0)  -> 0
//     sum_integers(1)  -> 1
//     sum_integers(5)  -> 15
//     sum_integers(10) -> 55
//
// Assume the input num is a non-negative integer.
// ============================================================

int sum_integers(int num) {
    int total = 0;
    for (int i = 1; i <= num; i++)
        total += i;
    return total;
}

// ============================================================
// Function 2: int sum_chars(char str[])
//
// Return the sum of the decimal values of all characters
// in the string.
//
// Examples:
//     sum_chars("")   -> 0
//     sum_chars("A")  -> 65
//     sum_chars("AB") -> 131
//
// Do not include the value of '\0'.
// ============================================================

int sum_chars(char str[]) {
    int total = 0;
    for (int i = 0; i < strlen(str); i++) {
        total += (int)str[i];
    }

    return total;
}


// ============================================================
// Function 3: int running_total(int num)
//
// Return the square of num by adding |num| to a running total |num| times.
//
// Examples:
//     running_total(0)  -> 0
//     running_total(2)  -> 4
//     running_total(8) -> 64
//     running_total(-4) -> 16
//
// Hint: you may want to use abs() from <stdlib.h>,
// or multiply num by -1 if it is negative.   
// ============================================================

int running_total(int num) {
    // if (num < 0)
    //     num *= -1;
    num = abs(num);   
    int total = 0;
    for (int i = 0; i < num; i++) {
        total += num;
    }
    return total;
}


// ============================================================
// Function 4: char score_to_grade(int test_score)
//
// Return the matching letter grade for the test_score.
// If the score is not in the range of 0 - 100, return 'X';
// If the score is in the range of 90 - 100, return 'A';
// If the score is in the range of 80 - 89, return 'B';
// If the score is in the range of 70 - 79, return 'C';
// If the score is in the range of 60 - 69, return 'D';
// If the score is in the range of 50 - 59, return 'E';
// If the score is in the range of 0 - 49, return 'F';
//
// Examples:
//     score_to_grade(-1)  -> 'X'
//     score_to_grade(120)  -> 'X'
//     score_to_grade(91)  -> 'A'
//     score_to_grade(89)  -> 'B'
//     score_to_grade(45)  -> 'F'
//
// Assume the input test_score can be any integer
// ============================================================

char score_to_grade(int test_score) {
    if (test_score > 100 || test_score < 0) {
        return 'X';
    }

    char letter_grade;
    if (test_score >= 90) {
        letter_grade = 'A'; // return 'A';
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

    return letter_grade;
}


// ============================================================
// Function 5: int sum_range(int start, int end)
//
// Return the sum of all integers from start to end, inclusive.
//
// Examples:
//     sum_range(1, 5)   -> 15
//     sum_range(3, 6)   -> 18
//     sum_range(10, 10) -> 10
//
// Assume start is a non-negative integer, and start <= end.
// ============================================================

int sum_range(int start, int end) {
    int total = 0;
    for (int i = start; i <= end; i++) {
        total += i;
    }

    return total;
}

// ============================================================
// Function 5.1: double average_range(int start, int end)
//
// Return the average of all integers from start to end, inclusive.
//
// Examples:
//     average_range(1, 3)   -> 2.000000
//     average_range(2, 6)   -> 4.000000
//     average_range(4, 5)   -> 4.500000
//
// Assume start is a non-negative integer, and start <= end.
// Requirement: must call sum_range()
// ============================================================

double average_range(int start, int end) {
    return (double)sum_range(start, end) / (end - start + 1);
}


// ============================================================
// Function 6: bool is_digit(char ch)
//
// Return true if the input char is a digit, false otherwise.
//
// Examples:
//     is_digit('a')  -> false
//     is_digit('1')  -> true
//     is_digit('0')  -> true
//
// ============================================================

bool is_digit(char ch) {
    if (ch >= '0' && ch <= '9') 
        return true;
    else
        return false;
}

// ============================================================
// Function 6.1: int count_digits(char str[])
//
// Return the number of digits in a string.
//
// Examples:
//     count_digits("abc")  -> 0
//     count_digits("01a")  -> 2
//     count_digits("Mc9nd")  -> 1
//
// Requirement: must call is_digit()
// ============================================================

int count_digits(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (is_digit(str[i]))
            count++;
    }
    return count;
}


// ============================================================
// Function 7: int factorial(int num)
//
// Return the factorial of num.
//
// The factorial of num is the product of all integers
// from 1 to num.
//
// Examples:
//     factorial(0) -> 1
//     factorial(1) -> 1
//     factorial(3) -> 6
//     factorial(5) -> 120
//
// Assume num is a non-negative integer.
// ============================================================

int factorial(int num) {
    int fac = 1;
    for (int i = 1; i <= num; i++)
        fac *= i;
    return fac;
}



// ============================================================
// Function 8: bool is_prime(int num)
//
// Return true if num is a prime number,
// and false otherwise.
//
// A prime number is an integer greater than 1
// that has exactly two positive divisors: 1 and itself.
//
// Examples:
//     is_prime(2)  -> true
//     is_prime(3)  -> true
//     is_prime(4)  -> false
//     is_prime(7)  -> true
//     is_prime(10) -> false
//     is_prime(1)  -> false
//
// Assume num is a non-negative integer.
// ============================================================

bool is_prime(int num) {
    if (num <= 1)
        return false;
    // for (int i = 2; i < num; i++)
    for (int i = 2; i <= (int)sqrt(num); i++)
    // for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}


// ============================================================
// Function 9: bool is_vowel(char ch)
//
// Return true if ch is a vowel,
// and false otherwise.
//
// Treat both uppercase and lowercase letters as vowels.
//
// Examples:
//     is_vowel('a') -> true
//     is_vowel('E') -> true
//     is_vowel('x') -> false
//     is_vowel('A') -> true
//     is_vowel(' ') -> false
//
// ============================================================

bool is_vowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
        return true;
    else 
        return false;
}


// ============================================================
// Function 9.1: int count_vowels(char str[])
//
// Return the number of vowels in the string.
//
// Requirement: must call is_vowel().
//
// Examples:
//     count_vowels("")        -> 0
//     count_vowels("hello")   -> 2
//     count_vowels("HELLO")   -> 2
//     count_vowels("Computer")-> 3
//     count_vowels("xyz")     -> 0
//
// ============================================================

int count_vowels(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if (is_vowel(str[i]))
            count++;
    return count;
}


// ============================================================
// Function 10: bool is_palindrome(int num)
// (From https://leetcode.com/problems/palindrome-number/description/)
// Return true if num reads the same forward and backward,
// and return false otherwise.
//
// A palindrome number reads the same from left to right
// and from right to left.
//
// Examples:
//     is_palindrome(121)  -> true
//     is_palindrome(123)  -> false
//     is_palindrome(1)    -> true
//     is_palindrome(1221) -> true
//     is_palindrome(1234) -> false
//     is_palindrome(0)    -> true
//     is_palindrome(-121) -> false
//
// Hint: You may want to use % 10 to get the last digit
// and / 10 to remove the last digit.
//
// Assume the input num can be any integer.
// ============================================================

bool is_palindrome(int num) {
    if (num < 0)
        return false;
    int num_rev = 0;
    int num_original = num;
    while (num != 0) {
        int last_digit = num % 10;
        num_rev = num_rev * 10 + last_digit;
        num /= 10;
    }
    // printf("%d\n", num_rev);
    return num_rev == num_original;
}


// ============================================================
// Do not modify the tests below.
// ============================================================

void test_sum_integers(void) {
    assert(sum_integers(0) == 0);
    assert(sum_integers(1) == 1);
    assert(sum_integers(2) == 3);
    assert(sum_integers(5) == 15);
    assert(sum_integers(10) == 55);
}

void test_sum_chars(void) {
    assert(sum_chars("") == 0);
    assert(sum_chars("A") == 65);
    assert(sum_chars("AB") == 131);
    assert(sum_chars("abc") == 294);
    assert(sum_chars("Hello") == 500);
}

void test_running_total(void) {
    assert(running_total(0) == 0);
    assert(running_total(1) == 1);
    assert(running_total(2) == 4);
    assert(running_total(5) == 25);
    assert(running_total(8) == 64);
    assert(running_total(-4) == 16);
}

void test_score_to_grade(void) {
    // Invalid scores
    assert(score_to_grade(-1) == 'X');
    assert(score_to_grade(-100) == 'X');
    assert(score_to_grade(101) == 'X');
    assert(score_to_grade(120) == 'X');

    // A: 90 - 100
    assert(score_to_grade(90) == 'A');
    assert(score_to_grade(100) == 'A');

    // B: 80 - 89
    assert(score_to_grade(80) == 'B');
    assert(score_to_grade(89) == 'B');

    // C: 70 - 79
    assert(score_to_grade(70) == 'C');
    assert(score_to_grade(79) == 'C');

    // D: 60 - 69
    assert(score_to_grade(60) == 'D');
    assert(score_to_grade(69) == 'D');

    // E: 50 - 59
    assert(score_to_grade(50) == 'E');
    assert(score_to_grade(59) == 'E');

    // F: 40 - 49
    assert(score_to_grade(40) == 'F');
    assert(score_to_grade(45) == 'F');

    // Scores below 40 but still in the valid range
    assert(score_to_grade(0) == 'F');
    assert(score_to_grade(39) == 'F');
}

void test_sum_range(void) {
    assert(sum_range(0, 0) == 0);
    assert(sum_range(1, 1) == 1);
    assert(sum_range(1, 5) == 15);
    assert(sum_range(3, 6) == 18);
    assert(sum_range(10, 10) == 10);
    assert(sum_range(10, 15) == 75);
}

void test_average_range(void) {
    assert(fabs(average_range(0, 0) - 0.00) < 0.000001); // fabs() from math.h
    assert(fabs(average_range(1, 3) - 2.00) < 0.000001);
    assert(fabs(average_range(2, 6) - 4.00) < 0.000001);
    assert(fabs(average_range(4, 5) - 4.50) < 0.000001);
    assert(fabs(average_range(1, 10) - 5.50) < 0.000001);
}

void test_is_digit(void) {
    // Digits
    assert(is_digit('0') == true);
    assert(is_digit('1') == true);
    assert(is_digit('5') == true);
    assert(is_digit('9') == true);

    // Non-digits
    assert(is_digit('a') == false);
    assert(is_digit('z') == false);
    assert(is_digit('A') == false);
    assert(is_digit(' ') == false);
    assert(is_digit('-') == false);
}

void test_count_digits(void) {
    assert(count_digits("") == 0);
    assert(count_digits("abc") == 0);
    assert(count_digits("01a") == 2);
    assert(count_digits("Mc9nd") == 1);
    assert(count_digits("12345") == 5);
    assert(count_digits("a1b2c3") == 3);
    assert(count_digits("Hello2026") == 4);
}

void test_factorial(void) {
    assert (factorial(1) == 1);
    assert (factorial(2) == 2);
    assert (factorial(3) == 6);
    assert (factorial(5) == 120);
}

void test_is_prime(void) {
    // Prime
    assert(is_prime(2) == true);
    assert(is_prime(3) == true);
    assert(is_prime(5) == true);
    assert(is_prime(11) == true);
    assert(is_prime(17) == true);
    assert(is_prime(97) == true);

    // Non-prime
    assert(is_prime(1) == false);
    assert(is_prime(4) == false);
    assert(is_prime(6) == false);
    assert(is_prime(9) == false);
    assert(is_prime(12) == false);
    assert(is_prime(49) == false);
    assert(is_prime(70) == false);
}

void test_is_vowel(void) {
    assert(is_vowel('A') == true);
    assert(is_vowel('e') == true);
    assert(is_vowel('I') == true);
    assert(is_vowel('u') == true);

    assert(is_vowel('B') == false);
    assert(is_vowel('w') == false);
    assert(is_vowel('Y') == false);
    assert(is_vowel('q') == false);
    assert(is_vowel('M') == false);
}

void test_count_vowels(void) {
    assert(count_vowels("abCde") == 2);
    assert(count_vowels("QbCdM") == 0);
    assert(count_vowels("") == 0);
    assert(count_vowels("aeiouAEIOUmmm") == 10);
}

void test_is_palindrome(void) {
    assert(is_palindrome(121) == true);
    assert(is_palindrome(111) == true);
    assert(is_palindrome(123454321) == true);
    assert(is_palindrome(99) == true);

    assert(is_palindrome(-121) == false);
    assert(is_palindrome(123) == false);
    assert(is_palindrome(98) == false);
}

// ============================================================
// Do not modify the main() below.
// ============================================================

int main(void) {
    
    test_sum_integers();
    test_sum_chars();
    test_running_total();
    test_score_to_grade();
    test_sum_range();
    test_average_range();
    test_is_digit();
    test_count_digits();
    test_factorial();
    test_is_prime();
    test_is_vowel();
    test_count_vowels();
    test_is_palindrome();


    printf("All tests passed!\n");

    return 0;
}

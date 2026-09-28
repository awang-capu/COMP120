# Lab 4: Loops

## Objectives

By the end of this lab, students will be able to:

1. Write a `for` loop correctly.
2. Use an accumulator variable to build up a running total inside a loop.
3. Choose a `while` loop when the number of iterations depends on a changing value rather than a fixed count.
4. Use the `%` (remainder) and `/` (integer division) operators together to process a number digit by digit.
5. Write nested loops, where the inner loop runs completely for each pass of the outer loop.
6. Format aligned tabular output with `printf` field widths such as `%4d`.


## Part 1: Sum of Even Integers


### Task

Write a program that uses a `for` loop to compute the sum of all even integers from 1 to 10, then prints the result.

### Hints

- if inside loop
- Or increase by 2 each iteration

### Expected Output

```
The sum of even integers from 1 to 10 is: 30.
```


---

## Part 2: Decimal to Binary Digits

**Concepts:** `while` loop, `%` and `/` operators, `scanf`

### Task

Write a program that reads a positive whole number from the user and prints the binary digits of the number starting from the lowest digit.

### Hint

- `num % 2`
- `num / 2`
- Use a `while` loop that continues as long as the number is greater than 0.


### Sample Run

```
Enter a whole number:
13
1
0
1
1
```


## Part 3: Multiplication Table

**Concepts:** nested `for` loops, `printf` field width, table formatting

### Task

Write a program that prints a formatted 10 × 10 multiplication table with a header row, a divider line, and row labels.

### Requirements

- Use `%4d` so every column is exactly 4 characters wide and numbers line up.

### Expected Output

```
   |   1   2   3   4   5   6   7   8   9  10
---+----------------------------------------
 1 |   1   2   3   4   5   6   7   8   9  10
 2 |   2   4   6   8  10  12  14  16  18  20
 3 |   3   6   9  12  15  18  21  24  27  30
 4 |   4   8  12  16  20  24  28  32  36  40
 5 |   5  10  15  20  25  30  35  40  45  50
 6 |   6  12  18  24  30  36  42  48  54  60
 7 |   7  14  21  28  35  42  49  56  63  70
 8 |   8  16  24  32  40  48  56  64  72  80
 9 |   9  18  27  36  45  54  63  72  81  90
10 |  10  20  30  40  50  60  70  80  90 100
```



🎉 Now complete your [lab_quiz](https://elearn.capu.ca/mod/quiz/view.php?id=3411292) on e-Learn. And that's all. Congratulations!

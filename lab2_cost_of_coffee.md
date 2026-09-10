# Lab2: The Cost of Coffee — Variables, `printf`, and `scanf` in C

## Learning Objectives

By the end of this lab, you will be able to:

- Declare variables of the correct C type (`int`, `float`, `double`, `char`, `char[]`) for a given real-world quantity
- Initialize variables and perform arithmetic between them
- Use `printf` with the correct format specifiers (`%d`, `%f`, `%lf`, `%c`, `%s`)
- Use `scanf` to read user input safely into variables
- Convert a "hardcoded" program into a general, reusable, interactive one

---

## Part 1 — The Hardcoded Coffee Calculator

### Scenario

You want to find out how much your coffee habit costs you per month and per year.

### Task

Write a C program that:

1. Stores your name in a variable
2. Stores your cup size as a single character (`'S'`, `'M'`, or `'L'`)
3. Stores the number of cups of coffee you drink per day
4. Stores the price of one cup of coffee (this should allow decimals!)
5. Assumes there are 30 days in a month and 12 months in a year
6. Calculates your monthly coffee cost
7. Calculates your yearly coffee cost from the monthly cost
8. Prints a friendly summary message using `printf`, including your name, cup size, cups per day, monthly cost, and yearly cost

### Requirements

- Use `int` for whole-number counts, `float` for the monthly cost, and `double` for the yearly cost (practice using all three)
- Use a `char` array (string) for your name
- Use a single `char` (not a `char[]`) for cup size, and print it with `%c`
- Every variable you declare should actually be used somewhere in the output — an unused variable is a sign it doesn't belong yet
- All values should be hardcoded (no `scanf` yet — that's Part 2)
- Print monthly and yearly cost rounded to 2 decimal places

### Starter Skeleton

```c
#include <stdio.h>

int main(void) {
    char name[26] = "Frank";
    char size = 'M';               // 'S', 'M', or 'L'
    float price_per_cup = 3.2f;    // price for a medium ('M') cup
    int cups_per_day = 2;
    int days_per_month = 30;
    int months_per_year = 12;

    float monthly_cost;
    double yearly_cost;

    // TODO: calculate monthly cost
    // TODO: calculate yearly cost from monthly cost

    printf("Hello, %s! Thanks for participating.\n", name);
    printf("You drink %d cups of size %c coffee per day.\n", cups_per_day, size);
    printf("Your monthly cost on coffee is $%.2f.\n", monthly_cost);
    printf("Your yearly cost on coffee is $%.2lf.\n", yearly_cost);

    return 0;
}
```

### Check Yourself

- If you drink 2 cups a day at $3.20/cup, your monthly cost should be $192.00.
- What happens to your output if you use `%d` instead of `%f` to print a `float`? Try it and explain the result in a one-line comment.
- What happens if you use `%s` instead of `%c` to print `size`? Try it and explain the result in a one-line comment. (Hint: `%s` expects a pointer to a string, not a single character's value.)

---

## Part 2 — The Interactive Coffee Calculator

### Scenario

Your Part 1 program only works for *you*, with numbers baked right into the code. Now hand the keyboard to a friend: the program should ask *them* directly for their own info and calculate *their* coffee cost, live, without you ever having to edit or recompile the code.

### Task

Copy your Part 1 program and modify it so that it:

1. Asks the person at the keyboard to enter their **name**
2. Asks them to enter how many **cups of coffee per day** they drink
3. Asks them to enter the **price per cup**
4. Reads all three values using `scanf`
5. Calculates monthly and yearly cost exactly as in Part 1 (`days_per_month` and `months_per_year` can stay hardcoded constants — those don't change from person to person)
6. Prints a summary addressed to them **by name**, showing their cups per day, monthly cost, and yearly cost, rounded to 2 decimal places

### Requirements

- Use `scanf("%d", &cups_per_day)` and `scanf("%f", &price_per_cup)` — note the `&` in front of the variable name for these
- For the name, use `scanf("%s", name)` — **no `&`** in front of a `char[]`, since the array name already refers to its address
- Print a prompt with `printf` *before* every `scanf`, so the user knows what to type and in what order
- Keep the prompts (the questions) generic/second-person ("Enter how many cups of coffee you drink per day:"), but make the **final summary** personal by using the stored name (e.g. `"Hey Maria! ..."`)
- Keep the same types as Part 1: `int` for counts, `float` for monthly cost, `double` for yearly cost

### Starter Skeleton

```c
#include <stdio.h>

int main(void) {
    char name[26];
    int cups_per_day;
    float price_per_cup;

    int days_per_month = 30;
    int months_per_year = 12;

    float monthly_cost;
    double yearly_cost;

    // Prompt for and read the user's name
    printf("What is your name: ");
    scanf("%s", name);

    // Prompt for and read cups per day
    printf("Enter how many cups of coffee you drink per day: ");
    scanf("%d", &cups_per_day);

    // TODO: prompt for and read price per cup

    // TODO: calculate monthly cost

    // TODO: calculate yearly cost from monthly cost

    // TODO: print a summary addressed to the friend, by name

    return 0;
}
```

### Sample Run

```
What is your name: Maria
Enter how many cups of coffee you drink per day: 2
Enter the price per cup: $1.60

Hey Maria! You drink 2 cups of coffee per day.
Your monthly cost on coffee is $96.00.
Your yearly cost on coffee is $1152.00.
```

### Common Pitfalls (read this before you start!)

- **Forgetting `&`**: `scanf` needs the *address* of a variable to write into, so `int` and `float` variables need `&` (e.g. `&cups_per_day`). A `char[]` name is already an address, so it does **not** take `&`.
- **`%s` and spaces**: `scanf("%s", name)` stops reading at the first whitespace, so a name like `"Mary Jane"` will only capture `"Mary"`. For this lab, ask for a single first name (or single "word" username) to keep things simple.
- **`%f` vs `%lf` in `scanf`**: This trips up a lot of students. In `printf`, both `%f` and `%lf` print a `double`-promoted value, so they look interchangeable. But in `scanf`, the specifier **must match the variable's actual type**: use `%f` to read into a `float*` and `%lf` to read into a `double*`. Mixing them up doesn't cause a compile error, but it silently reads garbage.
- **Not checking the buffer size**: `name` was declared as `char name[50]`. If the user types a name with 50+ characters, you'll overflow the array. That's outside the scope of this lab, but it's worth knowing this is why real-world programs use safer input functions.
- **Using `"%s you drink..."` in a prompt**: it's tempting to write `printf("Enter how many cups of coffee %s drinks per day: ", name)`, but that reads awkwardly ("Enter how many cups of coffee Maria you drink per day"). Keep the *questions* generic and second-person; save the personalization with `name` for the final summary line, where it reads naturally ("Hey Maria!").

### Stretch Goals (optional)

- Add a fourth question: how many days per week the friend actually buys coffee (instead of assuming every day), and adjust the monthly calculation.
- Print the price with a dollar sign using `printf("$%.2f", ...)` for every dollar amount, including the entered price per cup.
- Ask two friends' info back-to-back (reuse the same variables) and print a line saying which friend spends more per year.

---
---

# Solutions

> Try the lab yourself first! These are provided for after-the-fact checking or instructor use.

## Part 1 Solution

```c
#include <stdio.h>

int main(void) {
    char name[26] = "Frank";
    char size = 'M';
    float price_per_cup = 3.2f;
    int cups_per_day = 2;
    int days_per_month = 30;
    int months_per_year = 12;

    float monthly_cost;
    double yearly_cost;

    monthly_cost = cups_per_day * price_per_cup * days_per_month;
    yearly_cost = monthly_cost * months_per_year;

    printf("Hello, %s! Thanks for participating.\n", name);
    printf("You drink %d cups of size %c coffee per day.\n", cups_per_day, size);
    printf("Your monthly cost on coffee is $%.2f.\n", monthly_cost);
    printf("Your yearly cost on coffee is $%.2lf.\n", yearly_cost);

    return 0;
}
```

**Check Yourself — answers:**
- Using `%d` to print a `float` does not convert the value; it reinterprets the same bit pattern as if it were an integer, producing a meaningless, seemingly random-looking number (and it's technically undefined behavior in C). Format specifiers tell `printf` how to *interpret* the bytes it's handed, not just how to *format* them — they don't perform a type conversion.
- Using `%s` to print a `char` is worse than the `%d`/`float` case: `%s` tells `printf` to expect a `char*` (the address of a null-terminated string) and walk memory from there until it finds a `'\0'` byte. Handing it a single `char`'s *value* instead of an address means `printf` treats that value as an address and tries to read memory at it — this is undefined behavior and can crash the program (segfault). It's a good early warning that format specifiers and argument types must match exactly.

## Part 2 Solution

```c
#include <stdio.h>

int main(void) {
    char name[26];
    int cups_per_day;
    float price_per_cup;

    int days_per_month = 30;
    int months_per_year = 12;

    float monthly_cost;
    double yearly_cost;

    printf("What is your name: ");
    scanf("%s", name);

    printf("Enter how many cups of coffee you drink per day: ");
    scanf("%d", &cups_per_day);

    printf("Enter the price per cup: $");
    scanf("%f", &price_per_cup);

    monthly_cost = cups_per_day * price_per_cup * days_per_month;
    yearly_cost = monthly_cost * months_per_year;

    printf("\nHey %s! You drink %d cups of coffee per day.\n", name, cups_per_day);
    printf("Your monthly cost on coffee is $%.2f.\n", monthly_cost);
    printf("Your yearly cost on coffee is $%.2lf.\n", yearly_cost);

    return 0;
}
```

### Grading Rubric Suggestion (10 pts total)

| Criterion | Points |
|---|---|
| Part 1 compiles and produces correct hardcoded output | 2 |
| Part 1 uses correct types (`int`/`float`/`double`/`char[]`) and `%.2f`/`%.2lf` rounding | 1 |
| Part 2 compiles and correctly reads all 3 inputs via `scanf` | 3 |
| Part 2 uses `&` correctly (present for `int`/`float`, absent for `char[]`) | 2 |
| Part 2 output is personalized (uses friend's name and their numbers) | 1 |
| Code is reasonably readable (meaningful variable names, comments) | 1 |

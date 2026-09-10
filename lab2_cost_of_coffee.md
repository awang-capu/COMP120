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

Assume you drink coffee every day, and you want to find out how much your coffee habit costs you per month and per year.

### Task

New a `.c` file named `lab2_part1.c`, copy and paste the following starter C program into it, and finish the program that:

1. Calculates your monthly coffee cost
2. Calculates your yearly coffee cost from the monthly cost
3. Prints a friendly summary message using `printf`, including your name, cup size, cups per day, monthly cost, and yearly cost

### Note:

- Every variable you declare should actually be used somewhere in the output — an unused variable is a sign it doesn't belong yet
- All values should be hardcoded (no `scanf` yet — that's Part 2)
- Print monthly and yearly cost rounded to 2 decimal places


### Starter Skeleton

```c
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

    // TODO: calculate yearly cost from monthly cost

    // TODO: print info to match the sample run below


    return 0;
}
```

### Sample Run
```
Hello, Frank! Thanks for participating.
You drink 2 cups of size M coffee per day.
Your monthly cost on coffee is $192.00.
Your yearly cost on coffee is $2304.00.
```


---

## Part 2 — The Interactive Coffee Calculator

Your Part 1 program only works for *you*, with numbers baked right into the code. Now hand the keyboard to a friend: the program should ask *them* directly for their own info and calculate *their* coffee cost, live, without you ever having to edit or recompile the code.

### Task

New a `lab2_part2.c` file, and copy the following starter code and modify it so that it:

1. Asks the person at the keyboard to enter their **name**
2. Asks them to enter how many **cups of coffee per day** they drink
3. Asks them to enter the **price per cup**
4. Reads all three values using `scanf`
5. Calculates monthly and yearly cost exactly as in Part 1 (`days_per_month` and `months_per_year` can stay hardcoded constants — those don't change from person to person)
6. Prints a summary addressed to them **by name**, showing their cups per day, monthly cost, and yearly cost, rounded to 2 decimal places

### Note:

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

🎉 **Congratulations! Now complete your lab2 quiz on e-Learn. And that's all for lab2.**

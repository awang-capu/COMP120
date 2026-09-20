# Lab 3: Boolean Expressions and Branches

## Objectives

By the end of this lab, students should be able to:

1. Write Boolean expressions using relational (`<`, `>=`, `==`, `!=`) and logical (`&&`, `||`, `!`) operators.
2. Use `if`, `else if`, and `else` to choose between several mutually exclusive outcomes.
3. Use a `switch` statement to select an action based on a single `char` value, including the roles of `break` and `default`.
4. Read a string from the user and examine its first character using array indexing (e.g. `var_name[0]`) and comparison operators on characters.

---

## Part 1: Letter Grade with IF-ELSE-IF

### Task

Write a C program that asks the user for their test score (an **integer percentage between 0 and 100**) and uses an **if / else if / else** chain to determine their letter grade. Store the letter grade in a `char` variable, and print a message reporting the score and the letter grade.

| Score range | Letter grade |
|-------------|--------------|
| 90 to 100   | A |
| 80 to 89    | B |
| 70 to 79    | C |
| 60 to 69    | D |
| 50 to 59    | E |
| below 50    | F |

### Requirements

- Read the score into an `int` variable.
- Store the letter grade in a `char` variable.
- Use an if / else if / else chain (not a `switch`).
- You may assume the user enters an integer from 0 to 100.

### Sample Run

```
Enter your test score (0-100): 83
Your score is 83%, so your letter grade is B.
```

---

## Part 2: TV Remote Control with `switch`

### Task

Write a C program that mimics the wireless remote control of a TV. The program reads **one character** from the user, then uses a **switch** statement to decide which action to simulate.

| Key | Action | Message to print |
|-----|--------|------------------|
| `o` | Power on | `Power is on.` |
| `f` | Power off | `Power is off.` |
| `u` | Channel up | `Channel up.` |
| `d` | Channel down | `Channel down.` |
| `+` | Volume up | `Volume up.` |
| `-` | Volume down | `Volume down.` |
| anything else | Invalid button | `Invalid input.` |

### Requirements

- Use a `switch` statement (not an if-else chain).
- End every case with `break`.
- Include a `default` case for invalid buttons.

### Hint
- Read the button into a `char` variable using `scanf(" %c", &button_input);`. The space before `%c` skips leftover whitespace and newline characters.

### Sample Run

```
Press a button (o/f/u/d/+/-): u
Channel up.
```

```
Press a button (o/f/u/d/+/-): x
Invalid input.
```

---

## Part 3: Valid Variable Name Checker (Strings)

### Task

In C, a variable name must **start with a letter (`a`-`z`, `A`-`Z`) or an underscore (`_`)**. Write a C program that asks the user to enter a variable name and checks whether its first character is allowed.

- If the first character is a letter or `_`, print: `"<name>" may be a valid name for a variable.`
- Otherwise, print: `"<name>" is NOT a valid name for a variable.`

The message says "may be" because only the first character is checked.

### Requirements

- Store the input in a character array, such as `char var_name[50];`, and read it with `scanf("%s", var_name);`.
- Check only the first character, `var_name[0]`.

### Hints
- Test whether the first character is a letter by comparing it with character constants, for example `c >= 'a' && c <= 'z'`. Remember that upper-case and lower-case letters are two separate ranges.
- Use `||` to combine the underscore test with the letter test in a single `if` condition.

### Sample Run

```
Enter a variable name: _count
"_count" may be a valid name for a variable.
```

```
Enter a variable name: 2ndScore
"2ndScore" is NOT a valid name for a variable.
```

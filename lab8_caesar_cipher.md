# Lab 8: File-Based Caesar Cipher

## Overview

Write a program that encrypts and decrypts a text file using a Caesar cipher. A Caesar cipher shifts alphabetic characters by a fixed key, preserves case, and leaves non-alphabetic characters unchanged.

Start by reading the [starter code](https://github.com/awang-capu/COMP120/blob/main/lab8_starter.c). Compile and run it to see how the keyboard-based menu works. The starter program reads the message from the keyboard and prints the result to the screen. Its encryption and decryption are incomplete. Your task is to change it so that it reads messages from a file and writes or prints them as described below.

The starter program's keyboard version behaves like this:

```
Caesar Cipher Menu
1. Encrypt
2. Decrypt
3. Quit
Enter choice: 1
Enter message: Hello, COMP120!
Enter key: 2
New message: Jgnnq, EQOR120!

Caesar Cipher Menu
1. Encrypt
2. Decrypt
3. Quit
Enter choice: 3
Goodbye!
```

Your file-based version does not print `New message:`. It follows the behavior in Part 1.

## Part 1: File Encryption and Decryption

Modify the starter code (or write your own program from scratch) so that the menu reads from and writes to files. Your `main` function may call functions for the menu options, similar to this:

```c
...
if (input_choice == 1) {
    encrypt();
} else if (input_choice == 2) {
    decrypt();
}
...
```

You may choose your own function names and parameters. The sample run below uses [lab8_msg.txt](https://github.com/awang-capu/COMP120/blob/main/lab8_msg.txt).

```
Caesar Cipher Menu
1. Encrypt
2. Decrypt
3. Quit
Enter choice: 1
Enter filename: lab8_msg.txt
Enter key: 2

Caesar Cipher Menu
1. Encrypt
2. Decrypt
3. Quit
Enter choice: 2
Enter filename: lab8_msg_encrypted.txt
Enter key: 2
Hello! How are things going?
Like coding? Perfect.
Have a good time. Farewell!

Caesar Cipher Menu
1. Encrypt
2. Decrypt
3. Quit
Enter choice: 3
Goodbye!
```

## Part 2: Correct `shift_message` for Any Integer Key

Your program must handle any integer key, including large and negative ones. The file `lab8_dialogue_encrypted.txt` was encrypted with key 2026. Decrypting it with key 2026 must recover the original dialogue exactly:

```
Caesar Cipher Menu
1. Encrypt
2. Decrypt
3. Quit
Enter choice: 2
Enter filename: lab8_dialogue_encrypted.txt
Enter key: 2026
Dog: Why did the cookie go to the doctor?
Cat: I don’t know. Why?
Dog: It felt crumby.
Cat: Oh no! Did the doctor give it medicine?
Dog: Yes, a spoonful of sprinkles, three times a day.
Cat: Did it help?
Dog: It got so sweet that now it’s a cupcake.
Cat: Wait, how does a cookie turn into a cupcake?
Dog: Nobody knows. The doctor just says it’s “rising to the occasion.”

Caesar Cipher Menu
1. Encrypt
2. Decrypt
3. Quit
```

Rewrite `shift_message` so that:

- Letters wrap around the alphabet. `z` shifted by 1 becomes `a`, and `Z` shifted by 1 becomes `A`.
- Keys larger than 26 and negative keys both work. A key of 29 behaves like 3, a key of -3 behaves like 23, and a key of 2026 behaves like 24.
- Case is preserved.
- Non-letters are unchanged. This includes digits, punctuation, spaces, and non-ASCII characters such as `’` and `“ ”`, which are stored as multiple bytes in the file.

## Submission

Now complete your lab_quiz on e-Learn. And that's all. Congratulations!

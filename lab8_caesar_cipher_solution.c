// Part 1 sample solution
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STRING_SIZE_LIMIT 1024
#define INTEGER_SIZE_LIMIT 20

bool is_alpha(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void shift_message(char str[], int key) {
    for (int i = 0; str[i] != '\0'; i++)
        if (is_alpha(str[i]))
            str[i] = str[i] + key;
}

void remove_new_line(char file_name[]) {
    int len = strlen(file_name);
    if (len > 0 && file_name[len - 1] == '\n')
        file_name[len - 1] = '\0';
}

void encrypt() {
    char file_name[STRING_SIZE_LIMIT];
    int key;
    char key_line[INTEGER_SIZE_LIMIT];

    printf("Enter filename: ");
    fgets(file_name, STRING_SIZE_LIMIT, stdin);
    remove_new_line(file_name);

    printf("Enter key: ");
    fgets(key_line, INTEGER_SIZE_LIMIT, stdin);
    sscanf(key_line, "%d", &key);
    
    char line[1024];
    FILE *in = fopen(file_name, "r");
    FILE *out = fopen("lab8_msg_encrypted.txt", "w");

    if (in == NULL || out == NULL) {
        perror("fopen");
        if (in != NULL) fclose(in);
        if (out != NULL) fclose(out);
        return;
    }

    while (fgets(line, sizeof(line), in) != NULL) {
        shift_message(line, key);
        fputs(line, out);
    }

    fclose(in);
    fclose(out);
}

void decrypt() {
    char file_name[STRING_SIZE_LIMIT];
    int key;
    char key_line[INTEGER_SIZE_LIMIT];

    printf("Enter filename: ");
    fgets(file_name, STRING_SIZE_LIMIT, stdin);
    remove_new_line(file_name);

    printf("Enter key: ");
    fgets(key_line, INTEGER_SIZE_LIMIT, stdin);
    sscanf(key_line, "%d", &key);
    
    char line[1024];
    FILE *in = fopen(file_name, "r");

    if (in == NULL) {
        perror("fopen");
        if (in != NULL) fclose(in);
        return;
    }

    while (fgets(line, sizeof(line), in) != NULL) {
        shift_message(line, -key);
        printf("%s", line);
    }
    printf("\n");

    fclose(in);
}

void show_choices(void) {
    printf("Caesar Cipher Menu\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Quit\n");
    printf("Enter choice: ");
}

int main(void) {
    int input_choice;
    char input_choice_line[INTEGER_SIZE_LIMIT];
    while(1) {
        show_choices();
        fgets(input_choice_line, INTEGER_SIZE_LIMIT, stdin);
        sscanf(input_choice_line, "%d", &input_choice);
        if (input_choice == 1) {
            encrypt();
        } else if (input_choice == 2) {
            decrypt();
        } else if (input_choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input! Enter 1, 2, or 3.\n\n");
        }
    }
    return 0;
}

// Part 2 sample solution

#define ALPHABET_SIZE 26

void shift_message(char str[], int key) {
    /* Reduce key to 0..25. This handles negative and large keys. */
    int shift = ((key % ALPHABET_SIZE) + ALPHABET_SIZE) % ALPHABET_SIZE;
    char base;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_alpha(str[i])) {
            if ('a' <= str[i] && str[i] <= 'z')
                base = 'a';
            else 
                base = 'A';
            str[i] = (str[i] - base + shift) % ALPHABET_SIZE + base;
        }
}

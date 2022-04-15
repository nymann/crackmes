#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        // If user doesn't provide a second argument (a password)
        printf("Usage : %s <license pass code here [numbers only]>\n", *argv);
        return 0;
    }

    const int CORRECT_SUM = 50;
    char* password = argv[1];
    int password_length = strlen(password);
    int activation_sum = 0;
    int index = 0;


    while(index < password_length) {
        char char_at_index = password[index];
        activation_sum += atoi(&char_at_index);
        index++;
    }

    if (activation_sum == CORRECT_SUM) {
        puts("Premium access has been activated !");
        return 0;
    }

    puts("Wrong license code");
    return 0;
}

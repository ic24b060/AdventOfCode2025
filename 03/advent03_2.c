#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"

void main(void) {
    FILE *file = fopen("03/03_input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    long long total_joltage = 0;
    char str[200];
    char joltage[13] = "000000000000";
    long long current_highest_joltage = 0;
    while (fscanf(file, "%s", str) != EOF) {
        joltage[11] = str[strlen(str) - 1];
        joltage[10] = str[strlen(str) - 2];
        joltage[9] = str[strlen(str) - 3];
        joltage[8] = str[strlen(str) - 4];
        joltage[7] = str[strlen(str) - 5];
        joltage[6] = str[strlen(str) - 6];
        joltage[5] = str[strlen(str) - 7];
        joltage[4] = str[strlen(str) - 8];
        joltage[3] = str[strlen(str) - 9];
        joltage[2] = str[strlen(str) - 10];
        joltage[1] = str[strlen(str) - 11];
        joltage[0] = str[strlen(str) - 12];

        char new_str[200];
        strncpy(new_str, str, strlen(str) - 12);
        new_str[strlen(str) - 12] = '\0';
        printf("%s\n", str);
        //printf("%s\n", new_str);
        //printf("%s\n", joltage);

        for (int j = 0; j < 12; j++) {
            // We take the string above our highest number and search it for the biggest digit in there
            int highest_digit = 0;
            int current_digit = 0;
            int highest_digit_place = 0;
            for (int i = 0; i < strlen(new_str); i++) {
                current_digit = new_str[i] - '0';
                if (current_digit > highest_digit) {
                    highest_digit = current_digit;
                    highest_digit_place = i;
                }
            }
            //printf("%d, %d\n", highest_digit, highest_digit_place);

            // We check if this found biggest digit is equal to or greater than our current digit
            // Even if it is equal we want it, since it is higher up than our current digit
            if (joltage[j] <= new_str[highest_digit_place]) {
                char old_joltage = joltage[j];
                joltage[j] = new_str[highest_digit_place];

                // If it is, we assign it, and then cut up our remaining string to include the numbers between
                int old_new_str_length = strlen(new_str);
                for (int i = 0; i < old_new_str_length; i++) {
                    if (highest_digit_place + 1 + i > old_new_str_length) {
                        break;
                    }
                    new_str[i] = new_str[highest_digit_place + 1 + i];
                }
                // We add the old joltage number to the end, since it might be higher than the next coming number
                new_str[old_new_str_length - highest_digit_place - 1] = old_joltage;
                new_str[old_new_str_length - highest_digit_place] = '\0';
                //printf("%s\n", new_str);
            } else {
                break;
            }
        }

        printf("Highest Found joltage: %s\n", joltage);
        current_highest_joltage += atoll(joltage);
        total_joltage += current_highest_joltage;

        current_highest_joltage = 0;
    }
    fclose(file);

    printf("Total Joltage: %lld\n", total_joltage);
}
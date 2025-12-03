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

    int total_joltage = 0;
    char str[100];
    char joltage[3] = "00";
    int current_highest_joltage = 0;
    int current_joltage = 0;
    int found_i = 0;
    int found_j = 0;
    while (fscanf(file, "%s", str) != EOF) {
        for (int i = 0; i < strlen(str) - 1; i++) {
            joltage[0] = str[i];
            for (int j = i + 1; j < strlen(str); j++) {
                joltage[1] = str[j];

                current_joltage = atoi(joltage);
                if (current_joltage > current_highest_joltage) {
                    current_highest_joltage = current_joltage;
                    found_i = i;
                    found_j = j;
                }
            }
        }
        total_joltage += current_highest_joltage;
        printf("Joltage: %d\n", current_highest_joltage);


        // BUG FINDING:
        int length = strlen(str);
        for (int i = length; i > found_i; i--) {
            str[i] = str[i-1];
        }
        str[found_i] = '_';

        for (int i = length+1; i > found_j+1; i--) {
            str[i] = str[i-1];
        }
        str[found_j+1] = '_';

        str[length+2] = '\0';
        printf("%s\n", str);

        current_highest_joltage = 0;
        found_i = 0;
        found_j = 0;
        //printf("%s\n", str);
    }
    fclose(file);

    printf("Total Joltage: %d\n", total_joltage);
}

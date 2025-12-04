#include <stdio.h>
#include <string.h>

void main(void) {
    FILE *file = fopen("04/input.txt", "r");
    // FILE *file = fopen("04/test_input.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char line[200][200];
    int i = 0;
    while (fgets(line[i], 200, file) != NULL) {
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    int roll_extractable = 0;
    int roll_next_to = 0;
    int shelf_length = strlen(line[0]);
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < shelf_length; k++) {
            if (line[j][k] != '@') {
                continue;
            }

            // 9x9 Grid check
            for (int l = -1; l <= 1; l++) {
                for (int m = -1; m <= 1; m++) {
                    if (m == 0 && l == 0) {
                        continue;
                    }
                    if (j + l < 0 || j + l > shelf_length) {
                        continue;
                    }
                    if (k + m < 0 || k + m > shelf_length) {
                        continue;
                    }

                    if (line[j + l][k + m] == '@' || line[j + l][k + m] == 'X') {
                        roll_next_to++;
                    }
                }
            }

            if (roll_next_to < 4) {
                roll_extractable++;
                line[j][k] = 'X';
            }
            roll_next_to = 0;
        }
    }


    printf("Rolls Accessible: %d\n", roll_extractable);
}

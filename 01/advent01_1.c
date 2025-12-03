#include <stdio.h>
#include <string.h>
#include <math.h>

int dial_clicks = 0;

int rotate(int initial, char *str) {
    int rot = 0;
    int str_length = strlen(str) - 1;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            continue;
        }
        rot += (str[i] - '0') * (int) pow(10, str_length - i - 1);
    }
    if (str[0] == 'L') {
        rot *= -1;
    }
    //printf("Rot: %d\n", rot);

    initial += rot;
    while (initial < 0 || initial > 99) {
        if (initial > 99) {
            initial -= 100;
        }
        if (initial < 0) {
            initial += 100;
        }
    }
    return initial;
}


void main(void) {
    int dial = 50;
    FILE *file = fopen("01/input.txt", "r");
    if (file != NULL) {
        char line[1000];
        while (fgets(line, sizeof(line), file) != NULL) {
            dial = rotate(dial, line);
            if (dial == 0) {
                dial_clicks++;
            }
        }
        fclose(file);
    }
    printf("End Dial: %d\n", dial);
    printf("Dial Clicks: %d\n", dial_clicks);
}

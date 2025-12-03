
/*
 *THIS WAS NOT MADE WITH C
 *I USED PYTHON FOR DAY 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_dash(int* num1, int* num2, char* str) {
    char str_num1[50];
    char str_num2[50];
    int dash_found = 0;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (dash_found == 1) {
            str_num2[j] = str[i];
            j++;
            continue;
        }

        if (str[i] == '-') {
            dash_found = 1;
            str_num1[i] = '\0';
            continue;
        }

        str_num1[i] = str[i];
    }
    str_num2[j] = '\0';

    printf("%s\n", str_num1);
    printf("%s\n", str_num2);

    *num1 = atoi(str_num1);
    *num2 = atoi(str_num2);

    printf("%d\n", *num1);
    printf("%d\n", *num2);
}

void main(void) {
    char str[] = "11-22";
    int num1, num2;
    split_dash(&num1, &num2, str);

}

*/
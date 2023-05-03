#include "check.h"
#include <stdio.h>
#include <stdlib.h>

int name_verification(char* input_arr)
{
    char name_of_figure[6] = "circle";
    int letters = 0;
    for (int i = 0; i < 6; i++) {
        if (input_arr[i] != name_of_figure[i]) {
            letters = letters + 1;
            break;
        }
    }
    return letters;
}

int checking_parameters_figure(char* input_arr)
{
    int cursor = 7;
    int cnt = 0;

    if (input_arr[cursor] == ' ') {
        cnt++;
    }
    while (input_arr[cursor] != ' ') {
        if ((input_arr[cursor] != '-')
            && (!(((input_arr[cursor] <= '9') && (input_arr[cursor] >= '0'))
                  || (input_arr[cursor] == '.')))
            && (input_arr[cursor] != ' ')) {
            cnt++;
            break;
        } else {
            cursor++;
        }
    }

    while ((input_arr[cursor] != ',') && (input_arr[cursor + 1] != ' ')) {
        if ((input_arr[cursor] != '-')
            && (!(((input_arr[cursor] <= '9') && (input_arr[cursor] >= '0'))
                  || (input_arr[cursor] == '.')))
            && (input_arr[cursor] != ' ')) {
            cnt++;
            break;
        } else {
            cursor++;
        }
    }

    if (input_arr[cursor + 1] != ' ') {
        cnt++;
    }

    cursor++;

    while (input_arr[cursor] != ')') {
        if ((input_arr[cursor] != '-')
            && (!(((input_arr[cursor] <= '9') && (input_arr[cursor] >= '0'))
                  || (input_arr[cursor] == '.')))
            && (input_arr[cursor] != ' ')) {
            cnt++;
            break;
        } else {
            cursor++;
        }
    }
    return cnt;
}

bebra
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <libgeometry/check.h>

#define massive_size 50

        int
        main()
{
    float radius = 0, radius2 = 0;
    float area = 0, perimeter = 0, area2 = 0, perimetr2 = 0;
    char r_arr[massive_size], r_arr2[massive_size];
    char input_arr[massive_size] = {0}, input_arr2[massive_size] = {0};
    FILE* fptr = NULL;
    FILE* fptr2 = NULL;
    char* ukazat1 = input_arr;
    char* ukazat2 = input_arr2;
    fptr = fopen("input.txt", "r");
    fptr2 = fopen("input2.txt", "r");
    if (!fptr || !fptr2) {
        printf("Can't open the file.\n");
        return -1;
    } else {
        int i = 0;
        while (i < massive_size) {
            fscanf(fptr, "%c", &input_arr[i]);
            fscanf(fptr2, "%c", &input_arr2[i]);
            ++i;
        }
    }
    fclose(fptr);
    fclose(fptr2);
    int counter_1 = name_verification(input_arr);
    int counter_2 = checking_parameters_figure(input_arr);
    if (counter_1 > 0) {
        for (int i = 0; i < massive_size; i++) {
            printf("%c", input_arr[i]);
        }
        printf("Please state the correct name of figure.\n");
    } else {
        if (counter_2 > 0) {
            for (int i = 0; i < massive_size; i++) {
                printf("%c", input_arr[i]);
            }
            printf("Please state the correct parameters of figure.\n");
        } else {
            for (int i = 0; i < massive_size; i++) {
                if ((input_arr[i] == ',') && (input_arr[i + 1] == ' ')) {
                    for (int k = i; input_arr[k + 1] != ')'; k++) {
                        r_arr[k - i] = input_arr[k + 1];
                    }
                }
            }
            radius = atof(r_arr);
            if (radius < 0) {
                printf("Please state positive radius.\n");
                return -1;
            }
            area = M_PI * radius * radius;

            perimeter = 2 * M_PI * radius;

            printf("\n");
            for (int i = 0; i < massive_size; i++) {
                printf("%c", input_arr[i]);
            }
            printf("Area = %.3f\n", area);
            printf("Perimeter = %.3f\n", perimeter);
        }
    }
    int counter_3 = name_verification(input_arr2);
    int counter_4 = checking_parameters_figure(input_arr2);
    if (counter_3 > 0) {
        for (int i = 0; i < massive_size; i++) {
            printf("%c", input_arr2[i]);
        }
        printf("Please state the correct name of figure.\n");
        return -1;
    } else {
        if (counter_4 > 0) {
            for (int i = 0; i < massive_size; i++) {
                printf("%c", input_arr2[i]);
            }
            printf("Please state the correct parameters of figure.\n");
            return -1;
        } else {
            for (int i = 0; i < massive_size; i++) {
                if ((input_arr2[i] == ',') && (input_arr2[i + 1] == ' ')) {
                    for (int k = i; input_arr2[k + 1] != ')'; k++) {
                        r_arr2[k - i] = input_arr2[k + 1];
                    }
                }
            }
            radius2 = atof(r_arr2);
            if (radius2 < 0) {
                printf("Please state positive radius.\n");
                return -1;
            }
            area2 = M_PI * radius2 * radius2;
            perimetr2 = 2 * M_PI * radius2;
            printf("\n");
            for (int i = 0; i < massive_size; i++) {
                printf("%c", input_arr2[i]);
            }
            printf("Area2 = %.3f\n", area2);
            printf("Perimeter2 = %.3f\n", perimetr2);
        }
    }
    char* x1_s = (ukazat1 + 7);
    char* x2_s = (ukazat2 + 7);
    char* y1_s = (ukazat1 + 9);
    char* y2_s = (ukazat2 + 9);
    int x1 = atoi(x1_s);
    int x2 = atoi(x2_s);
    int y1 = atoi(y1_s);
    int y2 = atoi(y2_s);
    if (radius - radius2 < sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
        && sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
                < radius + radius2)
        printf("Figures intersect.\n");
    else
        printf("Figures don't intersect.\n");
    return 0;
}

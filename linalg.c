#include <stdio.h>
#include "input.h"
#include "linalg.h"

void input_matrix(double a[][MAX], int rows, int cols);
static void print_matrix(double a[][MAX], int rows, int cols);


void linalg_menu(void) {
    int selection;
    do {
        printf("\n ==== Linear Algebra Tool ====\n");
        printf("1. Display Matrix\n");
        printf("0. Return to Main Menu\n");
        printf("===========================\n");

        selection = get_int("Select an option: ");

        switch (selection) {
            case 1: {
                int rows = get_int("Enter number of rows: ");
                int cols = get_int("Enter number of columns: ");
                if (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) {
                    printf("invalid matrix size.\n");
                    break;
                }
                double A[MAX][MAX];

                printf("Enter a matrix\n");
                input_matrix(A, rows, cols);

                printf("\nYou entered:\n");
                print_matrix(A, rows, cols);
                break;
            }
            case 0: 
                printf("Returning to Main Menu\n"); 
                break;
            default: 
                printf("Unknown Option.\n"); 
                break;
        }
    } while (selection != 0);
}

/*
A general matrice's element is defined as a_ij (reference guide)
        a11 a12 a13 a14 ...a1j
        a21 a22 a23 a24 ...a2j
        a31 a32 a33 a34 ...a3j
        .    .   .   .
        .    .   .   .
        ai1 ai2 ai3 ai4
*/
void input_matrix(double a[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("Rows %d (%d values):\n", i, cols);
        for (int j = 0; j < cols; j++) {
            char prompt[PROMPT_LEN];
            snprintf(prompt, sizeof(prompt), "  a[%d][%d] = ", i, j);
            a[i][j] = get_double(prompt);
        }
    }
}

static void print_matrix(double a[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", a[i][j]);
        }
        printf("\n");
    }
}

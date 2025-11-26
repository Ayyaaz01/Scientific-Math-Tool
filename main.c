#include <stdio.h>
#include <stdbool.h>

#include "input.h"
#include "linalg.h"
#include "stats.h"

//function prototypes
static void main_menu(void);

int main(void) {
    main_menu();
    return 0;
}

static void main_menu(void) {
    printf("\n==== Numerical Toolkit ====\n ");
    printf("1. Linear Algebera Tool\n ");
    printf("2. Statistics Tool\n ");
    printf("3. Exit\n");
    printf("===========================\n ");
}
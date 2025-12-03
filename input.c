#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#include "input.h"

static void read_line(char *buffer, int size);

int get_int(const char *prompt) {
    char buffer[128];

    while (true) {
        printf("%s", prompt);
        read_line(buffer, sizeof(buffer));

        // Skip leading whitespace
        char *p = buffer;
        while (isspace((unsigned char)*p)) {
            p++;
        }

        // Check for empty input?
        if (*p == '\0') {
            printf("No input given. Please enter an integer.\n");
            continue;
        }

        errno = 0;
        char *endptr;
        long value = strtol(p, &endptr, 10);

        // No digits parsed
        if (endptr == p) {
            printf("That doesn't look like an integer. Please try again.\n");
            continue;
        }

        // Skip trailing whitespace
        while (isspace((unsigned char)*endptr)) {
            endptr++;
        }

        // Any junk after the number?
        if (*endptr != '\0') {
            printf("Unexpected characters after the number. Please try again.\n");
            continue;
        }

        // Check for overflow/underflow relative to long and the int range
        if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
            printf("Integer is out of range. Please try again.\n");
            continue;
        }

        return (int)value;
    }
}


int get_int_in_range(const char *prompt, int min , int max) {
    int value;
    while(true){
        value = get_int(prompt);
        if (value < min || value > max){
            printf("Value must be between %d and %d.\n", min, max);
        } else {
            return value;
        }
    }
}

double get_double(const char *prompt) {
    char buffer[128];

    while (true) {
        printf("%s", prompt);
        read_line(buffer, sizeof(buffer));

        // Skip leading whitespace
        char *p = buffer;
        while (isspace((unsigned char)*p)) {
            p++;
        }

        // Check for empty input
        if (*p == '\0') {
            printf("No input given. Please enter a number.\n");
            continue;
        }

        errno = 0;
        char *endptr;
        double value = strtod(p, &endptr);

        // No digits parsed
        if (endptr == p) {
            printf("That doesn't look like a number. Please try again.\n");
            continue;
        }

        // Skip trailing whitespace
        while (isspace((unsigned char)*endptr)) {
            endptr++;
        }

        // Any junk after the number?
        if (*endptr != '\0') {
            printf("Unexpected characters after the number. Please try again.\n");
            continue;
        }

        // Check for overflow / underflow and double's NaN/Inf values
        if (errno == ERANGE || !isfinite(value)) {
            printf("Number is too large, too small, or not finite. "
                   "Please enter a smaller, finite number.\n");
            continue;
        }

        // Check for matrice entrices
        if (value < MATRIX_MIN_VALUE || value > MATRIX_MAX_VALUE) {
            printf("Please enter a value between %.2f and %.2f.\n",
                   MATRIX_MIN_VALUE, MATRIX_MAX_VALUE);
            continue;
        }

        return value;
    }
}


//------------ Helper functions -----------------

static void read_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character
}
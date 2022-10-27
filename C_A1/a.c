//
// Created by sonia on 2022-10-26.
//

#include "a.h"
//
// Created by sonia on 2022-10-26.
//
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAX
#define MAX 100
#endif

int main(int argc, char *argv[]) {
    const char* str1 = "hello there";
    int n1 = 1234;

    char *num;
    char buffer[MAX];

    if (asprintf(&num, "%d", n1) == -1) {
        perror("asprintf");
    } else {
        memccpy(memccpy(buffer, str1, '\0', MAX) - 1, num, '\0', MAX);
        printf("%s\n", buffer);
        free(num);
    }

    exit(EXIT_SUCCESS);
}

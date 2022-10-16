#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

#include "traversal.h"
#include "text.h"
#include "report.h"

/*
 * I like an apple. apple is the one thing I want.
I like an apple. apple is the one thing I want.
I like an apple. apple is the one thing I want.
 */

int main(int argc, char *argv[]) {

    int traversals;
    char directory []= ".";
    char *input = argv[1];

    traversals = traversal(directory, input);
    //printf("%d", traversal);
    return 0;
}

//gcc main.c traversal.c


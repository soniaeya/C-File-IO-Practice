//
// Created by sonia on 2022-10-16.
//

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

#include "traversal.h"
#include "text.h"
#include "report.h"

int report(char input [], char file_name []){
    int count = 1;


    printf("%s", "Target String: ");
    printf("%s\n", input);

    printf("%s\n", "Search begins in current folder: ");
    printf("\n%s\n\n", "** Search Report **");
    printf("%s\t\t%s\n", "Updates", "File Name");

    printf("%d\t\t%s\n", count, file_name);
    printf("%s", "\n\n");



    return 0;

}

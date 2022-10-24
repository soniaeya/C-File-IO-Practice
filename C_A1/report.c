//
// Created by sonia on 2022-10-20.
//




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

int report(char input [], char file_name_arr [], int changes_num_arr [], int file_counter_int){
    int count = 1;
    char delim[] = " ";
    char *ptr = strtok(file_name_arr, delim);

    printf("%s", "Target String: ");
    printf("%s", input);
    printf("%s", "\nSearch begins in current folder: ");
    //printf("%s", getcwd('.', 256));               //getcwd()
    printf("\n\n%s\n\n", "** Search Report **");
    printf("%s\t\t%s\n", "Updates", "File Name");
    int i = 1;
    while (ptr){
        printf("%d\t\t%s\n", changes_num_arr [i], ptr);
        ptr = strtok(NULL, delim);
        i++;
    }
    return 0;

}

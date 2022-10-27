
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

#include "traversal.h"
#include "report.h"

/*
 * I like an apple.txt. apple.txt is the one thing I want.
I like an apple.txt. apple.txt is the one thing I want.
I like an apple.txt. apple.txt is the one thing I want.
 */




/*
 * To do list 10/17/22
 * - to do: search begins at/show current directory
 * - to do: iterate through sub directories
 * - fix: cannot put the last string in the line as upper case (need to add empty space to last element)
 *
 */
file_list fileList[SIZE];
int main(int argc, char *argv[]) {
    //char directory_name []= "./dir2";
    char directory_name[]= ".";
    char * input = argv[1];


    int file_counter_int=traversal(directory_name,input);

    for(int i=file_counter_int;i<SIZE;i++){
        fileList[i].count=0;
        fileList[i].name=NULL;
    }

    report(input, fileList);

    for(int i=0;i<SIZE;i++){
        free(fileList[i].name);
    }
    return 0;
}



//gcc main.c traversal.c


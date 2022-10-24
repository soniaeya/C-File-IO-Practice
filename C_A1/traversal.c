//
// Created by sonia on 2022-10-20.
//

#include "traversal.h"
//
// Created by sonia on 2022-10-15.
//
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "traversal.h"
#include "text.h"
#include "report.h"

int traversal(char directory_name [], char* input[]){
    DIR *folder;                    //Declaring directory
    //Name of directory
    folder = opendir(directory_name);    //Opening the directory
    struct dirent *entry;

    int count;
    FILE *fptr;
    char file_name [255];
    char empty [2] = " ";
    char file_name_arr [2000];

    int file_counter_int = 0;

    int changes_num = 0;
    int changes_num_arr [1000];
    while((entry = readdir(folder))) {

        if (strstr(file_name, ".txt") &&
            !strstr(file_name, "CMakeLists.txt")) {      //Check that the file is a text file
            file_counter_int++;
            if (fptr = fopen(file_name, "r+")) {      //opens the text file

                strcat(file_name_arr, file_name);
                strcat(file_name_arr, empty);


                changes_num = text(fptr, file_name, (char *) input);     //text function DND

                changes_num_arr[file_counter_int] = changes_num;        //getting the num of changes in an array


            }
            changes_num = 0;
        } else {
            continue;
        }
    }
    return (0);
}

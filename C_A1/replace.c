

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

int main(int argc, char *argv[]) {
    DIR *folder;                    //Declaring directory
    //char directory_name []= "./dir2";
    char directory_name []= ".";
    char * input = argv[1];
    //Name of directory
    folder = opendir(directory_name);    //Opening the directory
    struct dirent *entry;

    int count;

    char file_name [255];
    char empty [2] = " ";
    char file_name_arr [3000];

    int file_counter_int = 0;

    int changes_num = 0;
    int changes_num_arr [1000];


    if(folder == NULL){
        puts ("Unable to read directory");
        return(1);
    }
    else{

        while((entry = readdir(folder))){

            FILE *fptr;

            strncpy(file_name, entry->d_name, 254);
            file_name [254] = '\0';     //get filename string
            //printf("%s\n", file_name);

            if (entry->d_type == DT_DIR){       //if it is a directory
                int t;

                //t = traversal(file_name, input);     //traverse through the directory

                //printf ("Folder: %s\n", file_name);
            }                // if file is a folder/directory

            else {
                if(strstr(file_name, ".txt") && !strstr(file_name, "CMakeLists.txt")){      //Check that the file is a text file
                    file_counter_int++;
                    if(fptr = fopen(file_name, "r+")){      //opens the text file

                        strcat(file_name_arr, file_name);
                        strcat(file_name_arr, empty);
                        changes_num = text(fptr, file_name, input);     //text function DND
                        changes_num_arr[file_counter_int] = changes_num;        //getting the num of changes in an array
                        //printf("\n%d\n", changes_num);

                    }
                    changes_num = 0;
                }
                else{
                    continue;
                }

            }
        }
    }

    int file_couter_arr[file_counter_int];

    report(input, file_name_arr, changes_num_arr, file_counter_int);


    int traversals;
    printf("%s", "ffe");

    //traversals = traversal(directory_name, input);

    closedir(folder);
    //printf("%d", traversal);
    return 0;
}



//gcc main.c traversal.c


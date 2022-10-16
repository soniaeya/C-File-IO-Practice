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

    struct stat sb;
    int count;


    if(folder == NULL){
        puts ("Unable to read directory");
        return(1);
    }
    else{
        while((entry = readdir(folder))){
            FILE *fptr;

            char file_name [255];

            strncpy(file_name, entry->d_name, 254);
            file_name [254] = '\0';     //get filename string
            //printf("%s\n", file_name);

            if (entry->d_type == DT_DIR){
                //traversal(file_name);

                //printf ("Folder: %s\n", entry->d_name);
            }                // if file is a folder/directory

            else {

                if(strstr(file_name, ".txt") && !strstr(file_name, "CMakeLists.txt")){      //Check that the file is a text file
                    if(fptr = fopen(file_name, "r+")){      //opens the text file

                        text(fptr, file_name, input);

                        report(input, file_name);

                        //printf("%s", file_name);


                    }
                }
                else{
                    continue;
                }



                //fclose(fptr);
            }

        }

    }

    //printf("%d", count);
    closedir(folder);
    return (0);
}

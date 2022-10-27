//
// Created by sonia on 2022-10-20.
//
#define _GNU_SOURCE
//
// Created by sonia on 2022-10-15.
//
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#include "traversal.h"
#include "text.h"
#include "report.h"

file_list fileList[SIZE];
int file_counter_int = 0;

int traversal(char directory_name [], char input[]){


    DIR *folder;                    //Declaring directory
    //Name of directory
    struct dirent *entry;
    folder = opendir(directory_name);    //Opening the directory
    char file_name [255];
    FILE *fptr;
    int changes_num = 0;
    struct stat path;
    char newPath[200];

    if(folder == NULL){
        puts ("Unable to read directory");
        return(1);
    }

    else {
        printf("DIRECTORY HAS BEEN OPENED\n");
        printf("%s\n","Sonia");
        printf("Directory %s\n",directory_name);
        printf("%s\n","Sonia");
        while ((entry = readdir(folder))) {

            stat(entry->d_name, &path);

            if(strcmp(entry->d_name,"CMakeLists.txt")){
                continue;
            }
            else if (strstr(entry->d_name, ".txt")) {      //Check that the file is a text file
                file_counter_int++;
                printf("%s\n",entry->d_name);

                if (fptr = fopen(entry->d_name, "r+")) {      //opens the text file

                    text(fptr,entry->d_name,input);
                    fclose(fptr);

                }
                fileList[file_counter_int].count = changes_num;
                fileList[file_counter_int].name=(char*)malloc(strlen(file_name+1));
                strcpy(fileList[file_counter_int].name,file_name);
                fileList[file_counter_int].name[strlen(file_name)+1]='\0';

                changes_num = 0;

            } else if( entry->d_name[0] != '.' && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name,"cmake-build-debug") && strstr(entry->d_name,".txt")) {
                strcpy(newPath, directory_name);
                strcat(newPath, "/");
                strcat(newPath, entry->d_name);
                printf("%s\n",newPath);
                traversal(newPath, input);


            }
        }


    }

    if(closedir(folder)==0){
        printf("SUCCESSFULLY CLOSED THE DIR\n");
    }else{
        printf("CANNOT CLOSE THE DIR\n");
    }

    return file_counter_int;
}

//
// Created by sonia on 2022-10-20.
//



//
// Created by sonia on 2022-10-15.
//

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "traversal.h"
#include "text.h"
#include "report.h"
int count_int = 0;

int text (FILE *fptr, char file_name [], char * input){
    int count_int = 0;
    char line_output[1000];
    char delim[] = " ";
    char replacement [1000];
    char empty [] = " ";
    char upper;
    int newline_count = 0;

    //get modification count


    id: while (fgets(line_output, 1000, fptr)) {//check line in file
    char *ptr = strtok(line_output, delim);
    while(ptr){     //checks each word
        const char * c = input;
        //prints each word
        if(strstr(ptr, c)){
            char replace_str [strlen(ptr)];
            for(int i = 0; i< strlen(ptr)+1;i++){      //get replacement string
                upper = (char) toupper(ptr[i]);
                replace_str[i] = upper;
            }

            if(replacement == ""){
                strncat(replacement,replace_str, 256);
            }
            else{
                strncat(replacement,replace_str, 256);
                strncat(replacement,empty, 256);
            }

            count_int = count_int +1;

        }

        else if(strcmp(ptr, c)==0){

            char replace_str [strlen(ptr)];
            for(int i = 0; i< strlen(ptr)+1;i++){      //get replacement string
                upper = (char) toupper(ptr[i]);
                replace_str[i] = upper;
            }

            if(replacement == ""){
                strncat(replacement,replace_str, 256);
            }
            else{

                strncat(replacement,replace_str, 256);
                strncat(replacement,empty, 256);
            }

            count_int = count_int +1;

        }
        else{
            //printf("%s", (line_output));
            if(newline_count == 0){
                strncat(replacement,ptr, 256);
            }
            else{

                strncat(replacement,ptr, 256);
                strncat(replacement,empty, 256);
            }
        }
        ptr = strtok(NULL, delim);
        newline_count++;
    }
    newline_count = 0;
}
    if(fptr = fopen(file_name, "w+")){      //opens the text file

        fputs(replacement, fptr);
    }
    *replacement = '\0';
    fclose(fptr);
    return count_int;

}

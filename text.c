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


int text (FILE *fptr, char file_name [], char * input){

    char line_output[1000];
    char delim[] = " ";
    char replacement [1000];
    char empty [] = " ";
    char upper;
    int newline_count = 0;
    int change_count;
   //char report_card [256]= " ";
    //char report_card [256];


id: while (fgets(line_output, 1000, fptr)) {//check line in file
        char *ptr = strtok(line_output, delim);
        while(ptr){     //checks each word
            const char * c = input;

               //prints each word
           if(strcmp(ptr, c)==0){
               change_count++;

               char replace_str [strlen(ptr)];

               for(int i = 0; i< strlen(ptr)+1;i++){      //get replacement string
                           upper = (char) toupper(ptr[i]);
                           replace_str[i] = upper;

                   }
               strncat(replacement,empty, 256);
               strncat(replacement,replace_str, 256);


           }
           else{
               //printf("%s", (line_output));
               if(newline_count == 0){
                   strncat(replacement,ptr, 256);
               }
               else{
                   strncat(replacement,empty, 256);
                   strncat(replacement,ptr, 256);
               }
           }

            //fputs(ptr, fptr);

            ptr = strtok(NULL, delim);
            newline_count++;
        }

        newline_count = 0;
    }

    //printf("%s ", replacement);
    if(fptr = fopen(file_name, "w+")){      //opens the text file

       // printf("%s\n", replacement);
        fputs(replacement, fptr);


    }
    *replacement = '\0';
    fclose(fptr);
    //printf("%s\n", report_card);
}

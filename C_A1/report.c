//
// Created by sonia on 2022-10-20.
//




//
// Created by sonia on 2022-10-16.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "report.h"

int compare(const void *a, const void *b)
{

    file_list *fileListA = (file_list *)a;
    file_list *fileListB = (file_list *)b;

    return (fileListB->count - fileListA->count);
}

int report(char *input, file_list fileList[SIZE]){
    FILE *report;
    int count = 1;
    char delim[] = " ";
    report=fopen("report.txt","w");
    char path[200];
    getcwd(path,sizeof(path));

    if(report){
        fprintf(report, "Target string: %s\nSearch begins in current folder: %s\n** Search Report **\nUpdates\t\tFile Name\n", input, path);
        qsort(fileList,SIZE,sizeof(file_list),compare);
        for(int i=0;i<SIZE;i++){
            if(fileList[i].name!=NULL){
                fprintf(report, "%i", fileList[i].count);
                fputs("             ", report);
                fputs(fileList[i].name, report);
                fputs("\n", report);
            }
        }


    }else{
        printf("CANNOT GENERATE REPORT.TXT");
    }

    fclose(report);
    return 0;

}

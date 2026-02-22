#include<stdio.h>
#include<string.h>
#include "../include/helper.h"

void DisplayHelp()
{
    printf("----------------------------------\n");
    printf("Virtual File System Help\n");
    printf("----------------------------------\n");

    printf("creat filename permission\n");
    printf("ls\n");
    printf("man command\n");
    printf("help\n");
    printf("clear\n");
    printf("exit\n");
}

void ManPageDisplay(char Name[])
{
    if(strcmp(Name,"ls")==0)
    {
        printf("ls : List files\n");
    }
    else if(strcmp(Name,"creat")==0)
    {
        printf("creat : Create file\n");
    }
    else
    {
        printf("No manual entry\n");
    }
}
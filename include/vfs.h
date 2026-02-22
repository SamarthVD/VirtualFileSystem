#ifndef VFS_H
#define VFS_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>

#define MAXFILESIZE 50
#define MAXOPENFILES 20
#define MAXINODE 5

#define READ 1
#define WRITE 2

#define REGULARFILE 1

typedef struct BootBlock
{
    char Information[100];
}BootBlock;

typedef struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
}SuperBlock;

typedef struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next;
}INODE,*PINODE,*PPINODE;

typedef struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
}FILETABLE,*PFILETABLE;

typedef struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
}UAREA;

extern BootBlock bootobj;
extern SuperBlock superobj;
extern UAREA uareaobj;
extern PINODE head;

/* Functions */

void StartAuxillaryDataInitilisation();
void InitialiseSuperBlock();
void InitialiseUAREA();
void CreateDILB();

int CreateFile(char *,int);
void LsFile();
bool IsFileExist(char *);

#endif
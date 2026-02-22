#include "../include/vfs.h"

///////////////////////////////////////////////////////////
//
// Global Objects
//
///////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uareaobj;
PINODE head = NULL;

///////////////////////////////////////////////////////////
//
// Initialise UAREA
//
///////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName,"VirtualFileSystem");

    for(int i=0;i<MAXOPENFILES;i++)
    {
        uareaobj.UFDT[i] = NULL;
    }

    printf("UAREA initialised successfully\n");
}

///////////////////////////////////////////////////////////
//
// Initialise SuperBlock
//
///////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("SuperBlock initialised successfully\n");
}

///////////////////////////////////////////////////////////
//
// Create DILB
//
///////////////////////////////////////////////////////////

void CreateDILB()
{
    PINODE newn = NULL;
    PINODE temp = NULL;

    for(int i=1;i<=MAXINODE;i++)
    {
        newn = (PINODE)malloc(sizeof(INODE));

        newn->InodeNumber = i;
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->FileType = 0;
        newn->ReferenceCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        strcpy(newn->FileName,"");

        if(head == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp->next;
        }
    }

    printf("DILB created successfully\n");
}

///////////////////////////////////////////////////////////
//
// Auxiliary Initialisation
//
///////////////////////////////////////////////////////////

void StartAuxillaryDataInitilisation()
{
    strcpy(bootobj.Information,
    "Booting Virtual File System Completed");

    printf("%s\n",bootobj.Information);

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("Auxiliary data initialised\n");
}

///////////////////////////////////////////////////////////
//
// Check File Exist
//
///////////////////////////////////////////////////////////

bool IsFileExist(char *name)
{
    PINODE temp = head;

    while(temp != NULL)
    {
        if((strcmp(name,temp->FileName)==0)
        && (temp->FileType == REGULARFILE))
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

///////////////////////////////////////////////////////////
//
// Create File
//
///////////////////////////////////////////////////////////

int CreateFile(char *name,int permission)
{
    PINODE temp = head;
    int i = 0;

    if(name == NULL)
        return -1;

    if(permission < 1 || permission > 3)
        return -1;

    if(superobj.FreeInodes == 0)
        return -2;

    if(IsFileExist(name)==true)
        return -3;

    while(temp != NULL)
    {
        if(temp->FileType == 0)
            break;

        temp = temp->next;
    }

    if(temp == NULL)
        return -2;

    for(i=3;i<MAXOPENFILES;i++)
    {
        if(uareaobj.UFDT[i]==NULL)
            break;
    }

    if(i==MAXOPENFILES)
        return -8;

    uareaobj.UFDT[i] =
    (PFILETABLE)malloc(sizeof(FILETABLE));

    uareaobj.UFDT[i]->ReadOffset = 0;
    uareaobj.UFDT[i]->WriteOffset = 0;
    uareaobj.UFDT[i]->Mode = permission;

    uareaobj.UFDT[i]->ptrinode = temp;

    strcpy(temp->FileName,name);

    temp->FileSize = MAXFILESIZE;
    temp->ActualFileSize = 0;
    temp->FileType = REGULARFILE;
    temp->ReferenceCount = 1;
    temp->Permission = permission;

    temp->Buffer =
    (char*)malloc(MAXFILESIZE);

    superobj.FreeInodes--;

    return i;
}

///////////////////////////////////////////////////////////
//
// List Files
//
///////////////////////////////////////////////////////////

void LsFile()
{
    PINODE temp = head;

    printf("\n-----------------------------\n");
    printf("Files in Virtual File System\n");
    printf("-----------------------------\n");

    while(temp != NULL)
    {
        if(temp->FileType != 0)
        {
            printf("%d  %s  %d\n",
            temp->InodeNumber,
            temp->FileName,
            temp->ActualFileSize);
        }

        temp=temp->next;
    }

    printf("-----------------------------\n");
}
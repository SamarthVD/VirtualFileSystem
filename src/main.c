#include "../include/vfs.h"
#include "../include/helper.h"

int main()
{
    char str[80];
    char Command[5][20];
    int iCount = 0;
    int iRet = 0;

    StartAuxillaryDataInitilisation();

    while(1)
    {
        printf("\nVFS : > ");
        fgets(str,sizeof(str),stdin);

        iCount = sscanf(str,"%s %s %s",
        Command[0],Command[1],Command[2]);

        if(iCount == 1)
        {
            if(strcmp(Command[0],"exit")==0)
            {
                break;
            }
            else if(strcmp(Command[0],"ls")==0)
            {
                LsFile();
            }
            else if(strcmp(Command[0],"help")==0)
            {
                DisplayHelp();
            }
        }
        else if(iCount == 2)
        {
            if(strcmp(Command[0],"man")==0)
            {
                ManPageDisplay(Command[1]);
            }
        }
        else if(iCount == 3)
        {
            if(strcmp(Command[0],"creat")==0)
            {
                iRet = CreateFile(Command[1],
                atoi(Command[2]));

                printf("FD : %d\n",iRet);
            }
        }
    }
}
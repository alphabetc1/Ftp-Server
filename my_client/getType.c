#include "head.h"

int getType(char *ins,int *insType,char *name)
{
    memset(name,0,32);
    if(!strcmp("cd",ins))
    {
        *insType = 1;
        scanf("%s",name);
    }
    else if(!strcmp("ls",ins))
    {
        *insType = 2;
    }
    else if(!strcmp("puts",ins))
    {
        *insType = 3;
    }
    else if(!strcmp("gets",ins))
    {
        *insType = 4;
    }
    else if(!strcmp("pwd",ins))
    {
        *insType = 5;
    }
    else if(!strcmp("remove",ins))
    {
        *insType = 6;
        scanf("%s",name);
    }
    else return -1;
    return 0;
}

//int main()
//{
//    char buf[32];
//    int insType;
//    char name[20];
//    while(1)
//    {
//        scanf("%s",buf);
//        int ret = getRet(buf,&insType,name);
//        if(-1 == ret)
//        {
//            printf("error");
//            return -1;
//        }
//        printf("%d %s\n",insType,name);
//    }
//    return 0;
//}

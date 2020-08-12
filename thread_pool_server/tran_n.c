#include "tranfile.h"

int send_n(int sfd,void* ptran,int len)
{
    char *buf = (char*)ptran;
    int total=0;
    int ret;
    while(total<len)
    {
        ret=send(sfd,buf+total,len-total,0);
        if(-1==ret)
        {
            return -1;
        }
        total+=ret;
    }
    return 0;
}

int recv_n(int sfd,void* ptran,int len)
{
    char *buf = (char*)ptran;
    int total=0;
    int ret;
    while(total<len)
    {
        ret=recv(sfd,buf+total,len-total,0);
        if(0 == ret)
        {
            return -1;
        }
        total+=ret;
    }
    return 0;
}

int getFirstPath(char *path,char *name,char *filename)
{
    if(0 == name[0])
        return -1;
    int i,j,k = 0,t = 0;
    char flag = 0,tmp[15];
    for(i = 0; path[i] ;i++)
        ;
    path[i++] = '/';
    for(j = 0; name[j] && name[j] != '/';j++)
    {
        filename[k++] = name[j];
        path[i++] = name[j];
        flag = 1;
    }
    if('/' == name[j])
    {
        j++;
    }
    do{
        tmp[t++] = name[j++];
    }while(name[j]);
    tmp[t] = 0;
    strcpy(name,tmp);
    if(1 == flag)
        return 0;
    else 
        return -1;
}


void deleteLastPath(char *path)
{
    int i;
    for (i = 0; path[i];i++)
        ;
    while(path[i] != '/')
    {
        path[i--] = 0;
    }
    path[i] = 0;
}

#include "head.h"

int tranFile(int);
int tranIns(int sfd)
{
    int insType,ret;
    char ins[256];
    char name[32]; 
    memset(ins,0,sizeof(ins));
    memset(name,0,sizeof(name));
    scanf("%s",ins);
    getType(ins,&insType,name);
    ret = send_n(sfd,&insType,sizeof(int));
    if(-1 == ret)
    {
        return -1;
    }
    printf("send ok\n");
    if(1 == insType)    //cd
    {
        send_n(sfd,name,strlen(name));
    }
    if(2 == insType)
    {
        recv(sfd,ins,sizeof(ins),0);
        printf("%s\n",ins);
    }
    if(3 == insType)
    {
        tranFile(sfd);
    }
    if(4 == insType)
    {}
    if(5 == insType)
    {
        recv(sfd,ins,sizeof(ins),0);
        printf("%s\n",ins);
    }
    if(6 == insType)
    {
        send_n(sfd,name,strlen(name));
    }
    if(-1 ==ret)
    {
        return -1;
    }
    return 0;
}

int tranFile(int sfd)
{
    int dataLen,ret;
    char buf[1000] = {0};
    recv_n(sfd,&dataLen,sizeof(int));
    recv_n(sfd,buf,dataLen);
    printf("%s\n",buf);
    int fp = open(buf,O_WRONLY|O_CREAT,0666);
    if(-1 == fp)
    {
        perror("open");
        return -1;
    }
    off_t totalSize,loadSize = 0,lastSize = 0;
    recv_n(sfd,&dataLen,sizeof(int));
    recv_n(sfd,&totalSize,dataLen);
    off_t sliceSize = totalSize / 10000;
    while(1)
    {
        ret = recv_n(sfd,&dataLen,sizeof(int));
        if(-1 == ret)
        {
            printf("child crash\n");
            return -1;
        }
        if(dataLen>0)
        {
            ret = recv_n(sfd,buf,dataLen);
            if(-1 == ret)
            {
                printf("child crash\n");
                return -1;
            }
            write(fp,buf,dataLen);
            loadSize += dataLen;
            if(loadSize - lastSize >= sliceSize)
            {
                printf("%5.2f%s\r",(double)loadSize/totalSize*100,"%");
                fflush(stdout);
                lastSize = loadSize;
            }
        }
        else
        {
            close(fp);
            printf("100.00%s","%");
            printf("Transfer succeed!\n");
            break;
        }
    }
    return 0;
}

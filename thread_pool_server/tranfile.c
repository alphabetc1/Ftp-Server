#include "tranfile.h"
#include "sqlfunc.h"


int tranFile(int new_fd)
{
    train t;
    int ret;
    //发送文件名
    strcpy(t.buf,DOWNFILE);
    t.dataLen=strlen(DOWNFILE);
    ret=send_n(new_fd,(char*)&t,4+t.dataLen);
    if(-1==ret)
    {
        close(new_fd);
        printf("client close\n");
        return -1;
    }
    //发文件内容
    int fd=open(DOWNFILE,O_RDONLY);
    //发送大小
    struct stat statbuf;
    fstat(fd,&statbuf);
    memcpy(t.buf,&statbuf.st_size,sizeof(statbuf.st_size));
    t.dataLen=sizeof(statbuf.st_size);
    ret=send_n(new_fd,(char*)&t,4+t.dataLen);
    if(-1==ret)
    {
        close(new_fd);
        printf("client close\n");
        return -1;
    }
    while((t.dataLen=read(fd,t.buf,sizeof(t.buf))))
    {
        ret=send_n(new_fd,(char*)&t,4+t.dataLen);
        if(-1==ret)
        {
            close(new_fd);
            printf("client close\n");
            return -1;
        }
    }
    send_n(new_fd,(char*)&t,4+t.dataLen);
    close(new_fd);
    return 0;
}

int tranIns(int new_fd,char *path,char *code)
{
    MYSQL *conn1;
    int insType,ret;
    char name[256],filename[32];
    char procode[3],newcode[3];
    connectVirFile(&conn1);
    while(1)
    {
        memset(name,0,sizeof(name));
        ret = recv(new_fd,&insType,sizeof(int),0);
        if(0 == ret)
        {
            return -1;
        }
        if(1 == insType)    //cd
        {
            ret = recv(new_fd,name,sizeof(name),0);
            if(0 == ret)
            {
                return -1;
            }
            if(strcmp("..",name) == 0)
            {
                getProcode(conn1,procode,code);
                if(strcmp("0",procode)==0)
                {
                    return -1;
                }else {
                    strcpy(code,procode);
                    deleteLastPath(path);
                }
            }
            else {
                while(!(getFirstPath(path,name,filename)))
                {
                    getCodeByName(conn1,filename,code,newcode);
                    strcpy(code,newcode);
                }
            }
        }
        else if(2 == insType)   //ls
        {
            getNameByCode(conn1,name,code);
            printf("name:%s\n",name);
            send_n(new_fd,name,strlen(name));
        }
        else if(3 == insType)   //gets
        {
            tranFile(new_fd);   
        }
        else if(4 == insType)   //puts
        {}
        else if(5 == insType)   //pwd
        {
            printf("get pwd,now path:%s\n",path);
            send_n(new_fd,path,strlen(path));
        }
        else if(6 == insType)   //remove
        {
            ret = recv(new_fd,name,sizeof(name),0);
            if(0 == ret)
            {
                return -1;
            }
            ret = deleteFile(conn1,name,code);
            if(-1 == ret)
            {
                return -1;
            }
        }
        else 
        {
            strcpy(name,"error instruction\n");
            send_n(new_fd,name,strlen(name));
        }
    }
    mysql_close(conn1);
    return 0;
}

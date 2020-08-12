#include "head.h"
#include "tranfile.h"
#include "sqlfunc.h"

int geneRandom(char *str,int num)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < num;i++)
    {
        str[i] = rand()%26+'a';
    }
    str[i] = 0;
    return 0;
}

int checkUser(int new_fd,char *code,char *path)
{
    int ret,signup;
    MYSQL *conn,*conn1;
    FileNode f;
    memset(&f,0,sizeof(f));
    strcpy(f.procode,"0");
    char salt[13],userName[32],getPwd[256],truePwd[256],result[32] = {0};
    recv_n(new_fd,&signup,sizeof(int));
    connectUsers(&conn);
    connectVirFile(&conn1);
    if(2 == signup)          //注册
    {
        //getmd5value();
        geneRandom(salt,saltNum);
        recv(new_fd,userName,sizeof(userName),0);
        send_n(new_fd,salt,strlen(salt));
        recv(new_fd,getPwd,sizeof(getPwd),0);
        ret = insertUsers(conn,userName,getPwd,salt);//放入数据库，没重名就成功
        if(ret == 0)
        {
            strcpy(f.name,userName);
            strcpy(f.type,"d");
            strcpy(f.belong,userName);
            strcpy(f.md5value,"md5value");
            insertVirFile(conn1,f,path);
            getCodeByName(conn1,f.name,f.procode,code);
            strcpy(result,"注册成功");
            send_n(new_fd,result,strlen(result));
        }else {
            strcpy(result,"用户已存在");
            send_n(new_fd,result,strlen(result));
            mysql_close(conn);
            mysql_close(conn1);
            return -1;
        }
    }
    else if(1 == signup)    //登陆
    {
        recv(new_fd,userName,sizeof(userName),0);
        ret = getSaltByUsers(conn,userName,truePwd,salt);
        send_n(new_fd,salt,strlen(salt));
        recv(new_fd,getPwd,sizeof(getPwd),0);
        if(strcmp(truePwd,crypt(getPwd,salt)) == 0)
        {
            strcpy(path,userName);
            getCodeByName(conn1,userName,f.procode,code);
            strcpy(result,"登陆成功");
            send_n(new_fd,result,strlen(result));
        }
        else
        {
            strcpy(result,"登陆失败");
            send_n(new_fd,result,strlen(result));
            //mysql_close(conn);
            //mysql_close(conn1);
            //return -1;
        }
    }
    mysql_close(conn);
    mysql_close(conn1);
    return 0;
}

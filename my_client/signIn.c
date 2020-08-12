#include "head.h"

int signIn(int sfd)
{
    int signup;
    char userName[32],passwd[64],salt[13],result[16],truePwd[16];
    printf("登陆：1 注册：2\n");
    scanf("%d",&signup);
    printf("请输入账户名:");
    scanf("%s",userName);
    strcpy(passwd,getpass("请输入密码"));
    printf("账户:%s\n",userName);
    printf("密码:%s\n",passwd);
    send_n(sfd,&signup,sizeof(int));
    send_n(sfd,userName,strlen(userName));
    recv(sfd,salt,sizeof(salt),0);
    strcpy(truePwd,crypt(passwd,salt));
    printf("truePasswd:%s,salt:%s\n",truePwd,salt);
    send_n(sfd,truePwd,strlen(truePwd));
    recv(sfd,result,sizeof(result),0);
    printf("%s\n",result);
    return 0;
}


#ifndef __SQLFUNC_H__
#define __SQLFUNC_H__
#include "mysql/mysql.h"

typedef struct {
    char procode[3];
    char name[29];
    char type[2];
    char belong[30];
    char md5value[32];
}FileNode,*pFileNode;

int connectUsers(MYSQL **);
int connectVirFile(MYSQL **);
int insertUsers(MYSQL *,char *,char *,char*);
int getSaltByUsers(MYSQL *,char *,char *,char *);
int getCodeByName(MYSQL *,char *,char *,char *);
int getNameByCode(MYSQL *,char *,char *);
int deleteFile(MYSQL *,char *,char*);
int getProcode(MYSQL *,char *,char *);
int insertVirFile(MYSQL*,FileNode,char*);
#endif

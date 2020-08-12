#ifndef __TRANFILE_H__
#define __TRANFILE_H__
#include "head.h"
typedef struct{
    int dataLen;
    char buf[1000];
}train;
#define DOWNFILE "file"
int tranFile(int);
int tranIns(int,char*,char*);
int send_n(int,void*,int);
int recv_n(int,void*,int);
int checkUser(int,char*,char*);
void deleteLastPath(char*);
int getFirstPath(char*,char*,char*);
#endif

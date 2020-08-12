#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <sys/sem.h>
#include <signal.h>
#include <sys/msg.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <errno.h>
#include <sys/uio.h>
#include <ctype.h>
#include <crypt.h>

#define args_check(argc,num) {if(argc!=num) {printf("error args\n");return -1;}}
#define max(a,b) (a)>(b)?(a):(b)
int recv_n(int, void*, int);
int send_n(int, void*, int);
int getType(char*,int*,char*);
int tranIns(int sfd);
int signIn(int sfd);


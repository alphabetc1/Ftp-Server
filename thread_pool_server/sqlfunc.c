#include "head.h"
#include "sqlfunc.h"

int connectUsers(MYSQL **conn)
{
	const char* server="localhost";
	const char* user="root";
    const char* password = "2333";
	const char* database="users";
	*conn=mysql_init(NULL);
	if(!mysql_real_connect(*conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to database:%s\n",mysql_error(*conn));
        return -1;
	}else{
		printf("Connected...\n");
	}
    return 0;
}

int connectVirFile(MYSQL **conn)
{
	const char* server="localhost";
	const char* user="root";
    const char* password = "2333";
	const char* database="virFile";
	*conn=mysql_init(NULL);
	if(!mysql_real_connect(*conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to database:%s\n",mysql_error(*conn));
        return -1;
	}else{
		printf("Connected...\n");
	}
    return 0;
}

int insertUsers(MYSQL *conn,char *username,char *passwd,char*salt)
{
    char type[2] = "6";
	char query[128]="insert into users(username,passwd,type,salt) values('";
	strcat(query,username);
	strcat(query,"','");
	strcat(query,passwd);
	strcat(query,"',");
	strcat(query,type);
	strcat(query,",'");
	strcat(query,salt);
	strcat(query,"');");
    int t;
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
        return -1;
	}else{
		printf("insert success\n");
	}
	return 0;
}

int insertVirFile(MYSQL *conn,FileNode f,char *path)
{
	char query[128]="insert into virFile(procode,name,type,belong,md5value) values(";
	strcat(query,f.procode);
	strcat(query,",'");
	strcat(query,f.name);
	strcat(query,"','");
	strcat(query,f.type);
	strcat(query,"','");
	strcat(query,f.belong);
	strcat(query,"','");
	strcat(query,f.md5value);
	strcat(query,"');");

    strcpy(path,f.name);
    int t;
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
        return -1;
	}else{
		printf("insert success\n");
	}
	return 0;
}

int getSaltByUsers(MYSQL *conn,char *username,char *passwd,char *salt)
{
    int t;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char query[128]="select * from users where username = '";
	strcat(query,username);
	strcat(query,"';");
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
	}else{
		printf("Query made...\n");
		res=mysql_use_result(conn);
		if(res)
		{
            row=mysql_fetch_row(res);
            strcpy(passwd,row[2]);
            strcpy(salt,row[4]);
		}else{
			printf("Didn't find data\n");
		}
		mysql_free_result(res);
	}
	return 0;
}

int getCodeByName(MYSQL *conn,char *filename,char *procode,char *code)
{
    int t;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char query[128]="select * from virFile where name = '";
	strcat(query,filename);
	strcat(query,"' and procode = ");
    strcat(query,procode);
    strcat(query,";");
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
	}else{
		printf("Query made...\n");
		res=mysql_use_result(conn);
		if(res)
		{
            row=mysql_fetch_row(res);
            strcpy(code,row[1]);
		}else{
			printf("Didn't find data\n");
		}
		mysql_free_result(res);
	}
	return 0;
}

int getNameByCode(MYSQL *conn,char *lsName,char *procode)
{
    int t;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char query[128]="select * from virFile where procode = ";
    strcat(query,procode);
    strcat(query,";");
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
	}else{
		printf("Query made...\n");
		res=mysql_use_result(conn);
		if(res)
		{
			while((row=mysql_fetch_row(res))!=NULL)
			{	
				//printf("num=%d\n",mysql_num_fields(res));//列数
				for(t=0;t<mysql_num_fields(res);t++)
				{
                    strcat(lsName,row[t]);
                    strcat(lsName,"  ");
				}
				strcat(lsName,"\n");
			}
		}else{
			printf("Didn't find data\n");
		}
		mysql_free_result(res);
	}
	return 0;
}

int getProcode(MYSQL *conn,char *procode,char *code)
{
    int t;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char query[128]="select * from virFile where code =";
    strcat(query,code);
    strcat(query,";");
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
	}else{
		printf("Query made...\n");
		res=mysql_use_result(conn);
		if(res)
		{
			row=mysql_fetch_row(res);
            strcpy(procode,row[0]);
		}else{
			printf("Didn't find data\n");
		}
		mysql_free_result(res);
	}
	return 0;
}

int deleteFile(MYSQL *conn,char *filename,char *procode)
{
    int t;
	char query[200]="delete from virFile where name='";
    strcat(query,filename);
    strcat(query,"' and procode =");
    strcat(query,procode);
    strcat(query,";");
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
        return -1;
	}else{
		printf("Query made...\n");
        return 0;
    }
}



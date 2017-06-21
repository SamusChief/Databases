/**********************************************
**                                             				
** Course: Database Systems                    		
** Date: 06/15/2015                            			
** Description: Student starter code for sqlite		
**                                             				
***********************************************/

#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_SZ 256

int callme(void *, int, char **, char **);

int main(void) {    
   sqlite3 *conn;
   char *err_msg = 0;
   char *gmrStr = malloc (MAX_CMD_SZ);
   char goNext;
    
   int rc = sqlite3_open("./UMBC.db", &conn);
   if (rc != SQLITE_OK) {
       fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(conn));
       sqlite3_close(conn);
       return 1;
   }
   
   strcpy(gmrStr, "go");
   while(strcmp(gmrStr,"quit"))
   {
     printf("\033c");
     printf("please enter your sql statement\n");
     fgets (gmrStr, MAX_CMD_SZ, stdin);
     if ((strlen(gmrStr)>0) && (gmrStr[strlen (gmrStr) - 1] == '\n'))
        gmrStr[strlen (gmrStr) - 1] = '\0';
     printf("you entered %s\n", gmrStr);     
     if (strcmp(gmrStr,"quit"))
     {
      rc = sqlite3_exec(conn, gmrStr, callme, 0, &err_msg);
      if (rc != SQLITE_OK ) {   
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(conn);
        return 1;
      }
     }
     printf("Press any key to continue\n");
     goNext = getchar();
   } 
    
    sqlite3_close(conn);
    
    return 0;
}

int callme(void *cmdNum, int argc, char **argv, 
                    char **colName) {    
    cmdNum = 0;
    for (int i = 0; i < argc; i++) {
      printf("%-15s", colName[i]);
    }
    printf("\n");

    for (int i = 0; i < argc; i++) {
        printf("%-15s", argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    
    return 0;
}

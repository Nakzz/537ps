///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	main.c
//
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

#include "pid.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{

	//DEVANSHU
	//TODO:create argParser class
	//TODO:pass in argc and argv. Expecting a map?

	//TODO: create a command handler which will map each flag to a function

	//create pid's for all the PID using while
	int size = 3;
	struct pid *pid_list[size]; //TODO: change the initialization size at the size variables arg parser is giving
								//pid_list[0] = create_pid("22685");
								//pid_list[1] = create_pid(30);

	int totalPIDs = 0; // Everytime I initialize, I should be incrementing from 0 to keep track

	//if totalPID is 0, then
	// TODO: implement for all processes of the current user (and only of the current user)
	// find current user
	// for all processes for current user, create pid and add to list
	char ** allUserPID[1000];
	_getAllUserOwnedPID(allUserPID);

	for(int *i= allUserPID; *i; i++ ){
		printf("%s \n", i);
	}

	//and change flags for all pid in pid_list

	// pid_list[0]->flag_s=1;
	// pid_list[0]->flag_v=1;
	// pid_list[0]->flag_c=1;

	//print information about all the PIDs
	for (int i = 0; i < totalPIDs; i++)
	{
		if (pid_list[i])
			printPID(*pid_list[i]);
	}
}

void _getAllUserOwnedPID(char ** allUserPID)
{

	printf("The real user ID is %d\n", getuid());
	printf("The effective user ID is %d\n", geteuid());

	char path[20];

	strcpy(path, "/proc/");

	struct dirent *dp;
	DIR *dir = opendir(path);

	// Unable to open directory stream
	if (!dir)
		return;

	int size =0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (_isAllDigit(dp->d_name) == 1)
		{
			//enter those directory and check their status folder
			char pathStat[20];

			strcpy(pathStat, "head ");
			strcat(pathStat, path);
			strcat(pathStat, dp->d_name);
			strcat(pathStat, "/status | grep \"Uid:\"");
			// strcat(path,"/");

			FILE *popen(const char *command, const char *mode);
			int pclose(FILE *stream);

			// FILE *fPtr;
			// char ch;
			// fPtr = fopen(pathStat, "r");

			FILE *cmd;
    char result[1024];

    cmd = popen(pathStat, "r");

    if (cmd == NULL) {
        perror("popen");
    }
    while (fgets(result, sizeof(result), cmd)) {

char subbuff[5];
memcpy( subbuff, &result[5], 4 ); // hoping that all UID can only be 4 characters long
subbuff[4] = '\0';

        //printf("     %s %c \n", subbuff, subbuff[0]);

		char snum[5];

// convert 123 to string [buf]
		sprintf(snum, "%d", getuid());

        printf("    comparing: %s and %s \n", subbuff, snum);


		if(subbuff[0] == '0'){

			 if (snum[0] ==subbuff[0]){
	//ADD TO SOME LIST
			allUserPID[size++] = dp->d_name;
        printf("    adding %s \n", dp->d_name);
			 }

		

		}


		if(strcmp(subbuff, snum)==0){
			//ADD TO SOME LIST
			allUserPID[size++] = dp->d_name;
        printf("    adding %s \n", dp->d_name);

		}


    }
    pclose(cmd);

	
		}
	}

		for(int i= 0; allUserPID[i] != NULL; i++ ){
		printf("%s \n", allUserPID[i]);
	}

}

int _isAllDigit(char *s)
{
	if (s == NULL || *s == '\0' || isspace(*s))
		return 0;
	char *p;
	strtod(s, &p);
	return *p == '\0';
}

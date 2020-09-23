///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	main.c
//
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

#include "main.h"

int main(int argc, char** argv){

	node **arguments = argParser(argc, argv);
		for(int i=0; i<argc-1; i++){
			printf("%c\n",arguments[i]->c);
		}
	int size = 0;
	int sFlag = 0;
	int UFlag = 1;
	int cFlag = 1;
	int vFlag = 0;
	int SFlag = 0;
	char *pids[argc];
	for(int i=0; i<argc-1; i++){
		if (arguments[i]->c == '0'){
			continue;
		}else if(arguments[i]->c == 'p'){
			pids[size] = arguments[i]->flag;
			size ++;
		}else if(arguments[i]->c == 's'){
			sFlag = 1;
		}else if(arguments[i]->c == 'S'){
			SFlag = 1;
		}else if(arguments[i]->c == 'c'){
			cFlag = 0;
		}else if(arguments[i]->c == 'v'){
			vFlag = 1;
		}else if(arguments[i]->c == 'U'){
			UFlag = 0;
		}
	}

		struct pid **pidList;
		if(size == 0){
			//if totalPID is 0, then 
			// TODO: implement for all processes of the current user (and only of the current user)
        	// find current user
        	// for all processes for current user, create pid and add to list
				char ** allUserPID[1000];
	size = _getAllUserOwnedPID(allUserPID);

	printf("%d \n", size);

	// for(int *i= allUserPID; *i; i++ ){
	// 	printf("%s \n", i);
	// }
pidList = malloc(sizeof( struct pid *) * size);
			for(int i=0; i<size; i++){
				pidList[i] = create_pid((allUserPID[i]));
				if(pidList[i] != NULL){
				pidList[i]->flag_s = sFlag;
				pidList[i]->flag_U = UFlag;
				pidList[i]->flag_c = cFlag;
				pidList[i]->flag_v = vFlag;
				pidList[i]->flag_S = SFlag;
				}
			}

		}else{	
				pidList = malloc(sizeof( struct pid *) * size);
				if(pidList == NULL){
					printf("%s","%i\n" "errno: ", errno);
					fprintf(stderr, "Error: %s\n", strerror( errno ));
					exit(-1);
				}

			for(int i=0; i<size; i++){
				pidList[i] = create_pid((pids[i]));
				if(pidList[i] != NULL){
					pidList[i]->flag_s = sFlag;
					pidList[i]->flag_U = UFlag;
					pidList[i]->flag_c = cFlag;
					pidList[i]->flag_v = vFlag;
					pidList[i]->flag_S = SFlag;
				}	
			}
		}


for(int i=0; i<size; i++){
		if(pidList[i] != NULL){
			printPID(*pidList[i]);
		}
	}
		exit(0);
}

int _getAllUserOwnedPID(char ** allUserPID)
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
char pathExist[20];

                        strcpy(pathExist, path);
                        strcat(pathExist, dp->d_name);
                        strcat(pathExist, "/status");

                        if(access(pathExist, F_OK) !=-1){

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

        // printf("    comparing: %s and %s \n", subbuff, snum);


		if(subbuff[0] == '0'){

			 if (snum[0] ==subbuff[0]){
	//ADD TO SOME LIST
			allUserPID[size++] = dp->d_name;
        // printf("    adding %s \n", dp->d_name);
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
	}

	// 	for(int i= 0; allUserPID[i] != NULL; i++ ){
	// 	printf("%s \n", allUserPID[i]);
	// }

	return size;

}

int _isAllDigit(char *s)
{
	if (s == NULL || *s == '\0' || isspace(*s))
		return 0;
	char *p;
	strtod(s, &p);
	return *p == '\0';
}

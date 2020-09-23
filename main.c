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
#include "pid.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	
	//DEVANSHU
	//TODO:create argParser class
	node** arguments = argParser(argc, argv);
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
			*(pids[size]) = arguments[i]->flag;
			size ++;
		}else if(arguments[i]->c == 's'){
			sFlag = 1;
		}else if(arguments[i]->c == 'S'){
			SFlag = 1;
		}else if(arguments[i]->c == 'c'){
			cFlag = 0;
		}else if(arguments[i]->c == 'v'){
			vFlag = 1;
		}else if(arguments[i]-> == 'U'){
			UFlag = 0;
		}
	}

		if(size == 0){
			//if totalPID is 0, then 
			// TODO: implement for all processes of the current user (and only of the current user)
        	// find current user
        	// for all processes for current user, create pid and add to list
		}else{
			struct pid *pidList[size];	
			for(int i=0; i<size; i++){
				pidList[i] = create_pid((pids[i]));
				pidList[i]->flag_s = sFlag;
				pidlList[i]->flag_U = UFlag;
				pidList[i]->flag_c = cFlag;
				pidList[i]->flag_v = vFlag;
				pidList[i]->flag_S = SFlag;
			}
		}


	
	//print information about all the PIDs
	for(int i=0; i< totalPIDs; i++){
		if(pid_list[i])
			printPID(*pid_list[i]);
	}

}

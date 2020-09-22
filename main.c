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
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	
	//DEVANSHU
	//TODO:create argParser class
	//TODO:pass in argc and argv. Expecting a map?
	

	//TODO: create a command handler which will map each flag to a function

	
	//create pid's for all the PID using while
	int size = 3;
		struct pid *pid_list[size];	//TODO: change the initialization size at the size variables arg parser is giving
		pid_list[0] = create_pid("12815");
		//pid_list[1] = create_pid(30);
	
	int totalPIDs = 1;	// Everytime I initialize, I should be incrementing from 0 to keep track
	
	//if totalPID is 0, then 
		// TODO: implement for all processes of the current user (and only of the current user)
        	// find current user
        	// for all processes for current user, create pid and add to list
    

	//and change flags for all pid in pid_list

				pid_list[0]->flag_s=1;

	
	//print information about all the PIDs
	for(int i=0; i< totalPIDs; i++){
		if(pid_list[i])
			printPID(*pid_list[i]);
	}

}

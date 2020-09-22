///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	main.c
//                  
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

#include "pid.h";
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	
	//DEVANSHU
	//TODO:create argParser class
	//TODO:pass in argc and argv. Expecting a map?
	

	//TODO: create a command handler which will map each flag to a function

	//
	//create pid's for all the PID and change flags
	int size = 3;
	int totalPIDs = 2;	// Everytime I initialize, I should be incrementing from 0 to keep track
	struct pid *pid_list[size];	//TODO: change the initialization size at the size variables arg parser is giving
	// struct pid *p2 = create_pid(20);
	pid_list[0] = create_pid(20);
	pid_list[0]->flag_p=1;

	pid_list[1] = create_pid(30);
	
	//print information about all the PIDs
	for(int i=0; i< totalPIDs; i++){
		if(pid_list[i])
			printPID(*pid_list[i]);
	}

}

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
	int size = 5;
	struct pid *pid_list[size];	//TODO: change the initialization size at the size variables arg parser is giving
	// struct pid *p2 = create_pid(20);
	pid_list[0] = create_pid(20);
	pid_list[0]->flag_p=1;

	pid_list[1] = create_pid(30);
	
	//print information about all the PIDs
	for(int i=0; i<= size; i++){
		if(pid_list[i])
			printPID(*pid_list[i]);

	}

}

#include "pid.h";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    // constructor function for PID struct
	struct pid* create_pid(int id){
       struct pid *newPID;


        if(_pid_exists(id)){
        newPID = malloc(sizeof(struct pid)); //TODO: Do I have to clean this before ending my program? If should I should have a decontructor
       newPID->id = id;
        } //TODO: should we be throwing error message if it doesn't exist?
      

       

       return newPID;
    }	

    	void printPID(struct pid p){
        //printf(" printPID for Id is: %d  \n \n", p.id);

        printf("%d: %s \n", p.id, get_flag_p(p));
        //get_flag_p(p);
        //get_flag_s(p);
    }

    int _pid_exists(id){
        //TODO: finish implementing
        return 1; 
    }


	char* get_flag_p(struct pid p){
        // char *result = malloc(sizeof(char) *20);
        char result[100];
        
        //printf(" Id is: %d ,pFlag is: %d\n", p.id, p.flag_p);

        if(p.flag_p){
            strcpy(result, "todo: p");
            
        }

        return result;

    }

	char* get_flag_s(struct pid p){
        //printf(" Id is: %d ,sFlag is: %d\n", p.id, p.flag_p);

    }
	char* get_flag_S(struct pid p){

    }
	char* get_flag_U(struct pid p){

    }
	char* get_flag_v(struct pid p){

    }
	char* get_flag_c(struct pid p){

    }



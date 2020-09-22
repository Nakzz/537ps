///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	pid.c
//                  
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

#include "pid.h";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    // constructor function for PID struct
	struct pid* create_pid(int id){


        if(_pid_exists(id)){
       struct pid *newPID;

        newPID = malloc(sizeof(struct pid)); //TODO: Do I have to clean this before ending my program? If should I should have a decontructor
       newPID->id = id;

       return newPID;

        } //TODO: should we be throwing error message if it doesn't exist?
        else {
            return NULL;
        }      
    }	

    void printPID(struct pid p){
        //printf(" printPID for Id is: %d  \n \n", p.id);

        printf("%d: %s ; Done \n", p.id, get_flag_p(p));
        //get_flag_p(p);
        //get_flag_s(p);
    }

    int _pid_exists(id){
        //TODO: finish implementing
        if(id ==20)
            return 1; 
        
        return 0;
    }


	char* get_flag_p(struct pid p){
        char *result = malloc(sizeof(char) *20); // allocate memory on the heap
        //char result[100];
        
        //printf(" Id is: %d ,pFlag is: %d\n", p.id, p.flag_p);

        if(p.flag_p){
            strcpy(result, "todo: p"); //TODO: Finish implementing
            
        }

        return result;
    }

	char* get_flag_s(struct pid p){
        //printf(" Id is: %d ,sFlag is: %d\n", p.id, p.flag_p);
                char *result = malloc(sizeof(char) *20); // allocate memory on the heap
        //char result[100];
        
        //printf(" Id is: %d ,pFlag is: %d\n", p.id, p.flag_p);

        if(p.flag_s){
            strcpy(result, "todo: s"); //TODO: Finish implementing
            
        }

        return result;

    }
	char* get_flag_S(struct pid p){

    }
	char* get_flag_U(struct pid p){

    }
	char* get_flag_v(struct pid p){

    }
	char* get_flag_c(struct pid p){

    }



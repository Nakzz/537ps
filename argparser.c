///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	argparser.c
//
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include "argparser.h"

/*
 * this function parses the command line and returns
 * a struct representing each flag and if it's a pid
 * it also stores the PID in a string
 */
node** argParser(int argc, char **argv){
	int size = 0;
	int lastp = -1; //holds last place in array where last 'p'/pid was stored
	int lasts = -1; // holds last place in array where last 's' as stored so it can be ignored if '-s-' follows
	int lastU = -1;
	int lastS = -1;
	int lastv = -1;
	int lastc = -1;
	node **options = malloc(sizeof(node*) * (argc-1));
	if(options == NULL){
		printf("%s\n", "Error: Bad Malloc");
		exit(-1);
	}

	for(int i=0; i<argc-1; i++){

		options[i] = malloc(sizeof(node));

		if(options[i] == NULL){
			printf("%s\n", "Error: Bad Malloc");
			exit(-1);
		}else{
			options[i]->c = '0';
		}
	} 

	int opt;
	while ((opt = getopt(argc, argv, "-:p:s::U::S::v::c::m")) != -1){

		switch (opt) 
		{

		case 'p':
			if(optarg != 0x0 && *optarg == '-'){ // check for wrong argument
				printf("ERROR: no ProcessID provided for p:");
				exit(-1);
			}else{
			(options[size])->c = 'p';
			(options[size])->flag = optarg;
			lastp = size;
			size++;	
			}
		break;

		case 's':
			if(optarg != 0x0 && *optarg - '-' == 0){
				if(lasts > 0){
					(options[lasts])->c = '0';
				}
			}else{
				(options[size])->c = 's'; //sets s only if s is to be turned on
				lasts = size;
				size++;
			}

		break;

		case 'U':

			if(optarg != 0x0 && *optarg - '-' == 0){
					(options[size])->c = 'U'; //sets U only if U is to be turned off
					lastU = size;
					size++;
			}else{
				if(lastU > 0){
					options[lastU]->c = '0';
				}
			}
		break;

		case 'S':
			if(optarg != 0x0 && *optarg - '-' == 0){
				if(lastS > 0){
					(options[lastS])->c = '0';
				}
			}else{
				(options[size])->c = 'S';
				lastS = size;
				size++;
			}
		break;
		case 'v':
			if(optarg != 0x0 && *optarg - '-' == 0){
				if(lastv > 0){
					(options[lastv])->c = '0';
				}
			}else{
				(options[size])->c = 'v';
				lastv = size;
				size++;
			}
		break;
		case 'c':
			if(optarg != 0x0 && *optarg - '-' == 0){
				(options[size])->c = 'c';
				lastc = size;
				size++;
			}else{
				if(lastc > 0){
				(options[lastc])->c = '0';
				}
			}
			break;
		case ':':
			printf("Missing arg");
			exit(-1);
			break;
			default:
			printf("Unknown option:");
			exit(-1);	
		}
	}
return options;
}

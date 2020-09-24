#include "argparser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){

	node **p = argParser(argc, argv);
	int j = 0;
	for(int i=0; i<argc-1; i++){
		if( strcmp(argv[i+1], "-p") == 0 ) {
			if(p[j]->c != 'p'){
				printf("%s\n" , "error");
				exit(-1);
			}
			++j;
			++i;
		}else if( strcmp(argv[i+1], "-s") == 0 ) {
			if(p[j]->c != 's'){
				printf("%s\n" , "error");
				exit(-1);
			}
			++j;
		}else if( strcmp(argv[i+1], "-U-") == 0 ) {
			if(p[j]->c != 'U'){
				printf("%s\n" , "error");
				exit(-1);
			}
			++j;
		}else if( strcmp(argv[i+1], "-S") == 0 ) {
			if(p[j]->c != 'S'){
				printf("%s\n" , "error");
				exit(-1);
			}
			++j;
		}else if( strcmp(argv[i+1], "-c-") == 0 ) {
			if(p[j]->c != 'c'){
				printf("%s\n" , "error");
				exit(-1);
			}
			++j;
		}else if( strcmp(argv[i+1], "-v") == 0 ) {
			if(p[j]->c != 'v'){
				printf("%s\n" , "error");
				exit(-1);
			}
			++j;
		}
	}
	exit(0);
}
	


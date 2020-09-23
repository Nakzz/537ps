#include "argparser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
int main(){

	char *five_three_seven = "537ps";
	char *p_flag = "-p";
	char *s = "-s";
	char *S = "-S";
	char *v = "-v";
	char *U = "-U-";
	char *c = "-c-";
	char *num_one = "18273";
	char *num_two = "123124";

	int argc = 5;
	char *argv[5];

	argv[0] = five_three_seven;
	argv[1] = p_flag;
	argv[2] = num_two;
	argv[3] = U;
	argv[4] = S;

	node **p = argParser( argc, argv );
	
	if (p[0]->c != 'p'){
		printf("%c\n", p[0]->c);
		printf("%s\n", "Error: ArgParser not working");
		exit(-1);
	}
	if (strcmp(p[0]->flag, num_one)){
		printf("%s\n", "Error: ArgParser not working");
		exit(-1);
	}
	exit(0);
}
	

// for(int i=0; i<argc-1; i++){
// 		if( (p[i]->c == 'p' ) ){
// 			printf("%c\n",(p[i]->c));
// 			printf("%s\n", (p[i]->flag));
// 		}else{
// 			printf("%c\n",(p[i]->c));
// 		}
// 	}
// 	exit(0);
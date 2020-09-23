#include "argparser.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	node **p = argParser(argc, argv);
	for(int i=0; i<argc-1; i++){
		if( (p[i]->c == 'p' ) ){
			printf("%c\n",(p[i]->c));
			printf("%s\n", (p[i]->flag));
		}else{
			printf("%c\n",(p[i]->c));
		}
	}
	exit(0);
}
	// char five_three_seven[] = "537ps";
	// char p_flag[] = "-p";
	// char s[] = "-s";
	// char S[] = "-S";
	// char v[] = "-v";
	// char U[] = "-U-";
	// char c[] = "-c-";
	// char num_one = "18273";
	// char num_two = "123124";
	// int argc = 5;
	// char *argv[5];
	// if(argv == NULL){
	// 	printf("%s","%i\n" "errno: ", errno);
	// 	fprintf(stderr, "Error: %s\n", strerror( errno ));
	// 	exit(-1);
	// }
	// argv[0] = five_three_seven;
	// argv[1] = p_flag;
	// argv[2] = num_two;
	// argv[3] = U;
	// argv[5] = S;
	// node **p = argParser( argc, argv );
	
		
	// if (p[0]->c != 'p'){
	// 	printf("%s\n", "Error: ArgParser not working");
	// 	exit(-1);
	// }
	// if (p[0]->flag != '123124'){
	// 	printf("%s\n", "Error: ArgParser not working");
	// 	exit(-1);
	// }
	// for(int i=1; i<argc-1; i++){
	// 	if(p[i]->flag != '0'){
	// 		exit(-1);
	// 	}
	// }
	// exit(0);

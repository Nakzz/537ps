#include "argParser.h"

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
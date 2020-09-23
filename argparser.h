#ifndef ARGPARSER_H
#define ARGPARSER_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
	typedef struct node {
		char c;
		char* flag;
	} node;

	node** argParser(int argc, char** argv); 

#endif
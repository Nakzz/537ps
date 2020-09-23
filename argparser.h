#ifndef ARGPARSER_H
#define ARGPARSER_H

	typedef struct node {
		char c;
		char* flag;
	} node;

	node** argParser(int argc, char** argv); 

#endif
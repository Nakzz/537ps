
#ifndef MAIN_H
#define MAIN_H
	
#include "argparser.h"
#include "pid.h"
#include <stdio.h>
#include <string.h>

	int main(int argc, char ** argv);
	
    int _getAllUserOwnedPID(char ** allUserPID);
int _isAllDigit(char *s);

#endif

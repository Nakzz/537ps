///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	main.h
//
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

#ifndef MAIN_H
#define MAIN_H
	
#include "argparser.h"
#include "pid.h"
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

	int main(int argc, char ** argv);
	
    int _getAllUserOwnedPID(char ** allUserPID);
	int _isAllDigit(char *s);

#endif

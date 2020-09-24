///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	argparser.h
//
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ARGPARSER_H
#define ARGPARSER_H

	/*
	 * holds the flag in a character c
	 * and if the flag is a -p, it holds 
	 * the PID in flag
	 */
	typedef struct node {
		char c;
		char* flag;
	} node;

	node** argParser(int argc, char** argv); 

#endif
///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	pid.h
//                  
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////
#ifndef PID_H
#define PID_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>

typedef int bool;
#define true 1
#define false 0

struct pid{
		char id[20];
		char stat[10];
		char m_addr[100];
		char m_len[10];
		bool exists;
		bool flag_p;
		bool flag_s;
		bool flag_S;
		bool flag_U;
		bool flag_v;
		bool flag_c;
		bool flag_m;
	};
		
struct pid * create_pid(char* id);	// constructor
void get_flag_p(struct pid p, char * result); //TODO: remove, since this can be taken care from printPID function
void get_flag_s(struct pid p, char * result);
void get_flag_S(struct pid p,char * result);
void get_flag_U(struct pid p,char * result);
void get_flag_v(struct pid p, char * result);
void get_flag_c(struct pid p,char * result);
void get_flag_m(struct pid p,char * result);
void printPID(struct pid p);

void freePID(struct pid list[]);	//destructor
	
int _pid_exists(char* pid);
void _getFieldfromStat(char* p, int stat_index, char * result);
void _appendChar(char *array, char c);

#endif
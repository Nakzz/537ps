///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:	pid.h
//                  
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqib, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

typedef int bool;
#define true 1
#define false 0

typedef struct pid{
		int id;
		bool exists;
		bool flag_p;
		bool flag_s;
		bool flag_S;
		bool flag_U;
		bool flag_v;
		bool flag_c;
	}; 
		
struct pid * create_pid(int id);	// constructor
char* get_flag_p(struct pid p);
char* get_flag_s(struct pid p);
char* get_flag_S(struct pid p);
char* get_flag_U(struct pid p);
char* get_flag_v(struct pid p);
char* get_flag_c(struct pid p);
void printPID(struct pid p);

void freePID(struct pid list[]);	//destructor
	
int _pid_exists(int pid);
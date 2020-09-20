///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:		ps.h
//                  
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqqab, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

typedef struct{
		int pid;
		bool flag_p;
		bool flag_s;
		bool flag_S;
		bool flag_U;
		bool flag_v;
		bool flag_c;
	} pid; 
		
		pid* pid_new(int pid);
		char* get_flag_p(const struct pid* p);
		char* get_flag_s(const struct pid* p);
		char* get_flag_S(const struct pid* p);
		char* get_flag_U();
		char* get_flag_v();
		char* get_flag_c();
	
			
		bool _pid_exists(int pid);
		void set_flag_p(bool state);
		void set_flag_s(bool state);
		void set_flag_S(bool state);
		void set_flag_U(bool state);
		void set_flag_v(bool state);
		void set_flag_c(bool state);
		
		void print();
}

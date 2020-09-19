///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:		ps.h
//                  
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqqab, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

class PID_Service{
	private:
		bool _pid_exists(int pid);
		bool flag_p;
		bool flag_s;
		bool flag_S;
		bool flag_U;
		bool flag_v;
		bool flag_c;
		char* get_flag_p();
		char* get_flag_s();
		char* get_flag_S();
		char* get_flag_U();
		char* get_flag_v();
		char* get_flag_c();
	
	public:
		PID_Service(int pid);
		void set_flag_p(bool state);
		void set_flag_s(bool state);
		void set_flag_S(bool state);
		void set_flag_U(bool state);
		void set_flag_v(bool state);
		void set_flag_c(bool state);
		
		void print();
}

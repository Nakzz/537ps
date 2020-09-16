///////////////////////////////////////////////////////////////////////////////
//
// Title:		537ps
// Filename:		ps.h
//                  
// Course:		cs537, Fall 2020
// Authors:		Ajmain Naqqab, Devanshu Mantri
//
///////////////////////////////////////////////////////////////////////////////

class PS_Service{
	private:
		bool _pid_exists(int pid);

	public:
		PS_Service();
		
		//TODO: these wont be void. They should be pointers to the struct D creates.
		void get_flag_p(int pid);
		void get_flag_s(int pid);
		void get_flag_S(int pid);
		void get_flag_U(int pid);
		void get_flag_v(int pid);
		void get_flag_c(int pid);
}

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:	
		std::string fName;
		std::string lName;
		std::string nName;
		std::string numb;
		std::string Secret;

	public:
		Contact();
		~Contact();
		void set_fName();
		void set_lName();
		void set_nName();
		void set_numb();
		void set_secret();
		bool check_field();
		void reset_contact();
};

#endif
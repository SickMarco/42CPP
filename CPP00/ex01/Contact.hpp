#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:	
		std::string contact[5];

	public:
		Contact();
		~Contact();
		void set_contact();
		std::string get_info(int index);
};

#endif
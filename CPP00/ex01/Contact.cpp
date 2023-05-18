#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_contact()
{
	std::string data[5] = {	"First Name",
							"Last Name",
							"Nickname",
							"Number",
							"Secret"};

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Insert " << data[i] << ": ";
		std::getline(std::cin, contact[i]);
		if (contact[i].empty())
		{
			std::cout << "Error: Empty Field\n";
			for (int i = 0; i < 5; i++)
				contact[i].clear();
			break;
		}
	}
}

std::string Contact::get_contact(int index) {return contact[index];}
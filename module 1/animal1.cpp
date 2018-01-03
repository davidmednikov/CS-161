/***********************************************************************
** Author: David Mednikov
** Date: 09/21/2016
** Description: This program will ask the user for their favorite animal.
** It will then return the favorite animal (in a sentence) to the user.
***********************************************************************/


#include <iostream>
#include <string>

// a simple example program
int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." << std::endl;
	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;

	return 0;
}

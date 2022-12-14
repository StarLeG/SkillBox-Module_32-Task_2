
#include "menu.h"


int main()
{
	int input = -1;
	menu();
	std::cout << "Your choice: ";
	std::cin >> input;
	while (input != 0)
	{
		switch (input)
		{
		case 1:
			break;
		default:
			std::cerr << "False!  try again!!!" << std::endl;
		}
		menu();
		std::cout << "Your choice: ";
		std::cin >> input;
	}
	std::cout << "BYE!" << std::endl;
	return 0;
}


#include "menu.h"
#include "base.h"


int main()
{
	std::vector<Movies> base;
	int input = -1;
	menu();
	std::cout << "Your choice: ";
	std::cin >> input;
	while (input != 0)
	{
		switch (input)
		{
		case 1:
			read_json_file();
			break;
		case 2:
			base.emplace_back(addMovies());			
			break;
		case 3:
			break;
		case 4:
			show_json();
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

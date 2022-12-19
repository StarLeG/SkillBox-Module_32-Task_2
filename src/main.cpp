
#include "menu.h"
#include "base.h"


int main()
{
	std::vector<Movies> base;
	std::fstream file_json;
	int input = -1;
	menu();
	std::cout << "Your choice: ";
	std::cin >> input;
	while (input != MenuType::EXIT)
	{
		switch (input)
		{
		case MenuType::SHOW_BASE:
			showMovies(base,file_json);
			break;
		case MenuType::ADD_MOVIES:
			base.emplace_back(addMovies());			
			break;
		case MenuType::SEARCH_ACTOR:
			actorSearch(base,file_json);
			break;
		case MenuType::SHOW_JSON :
			show_json();
			break;
		case MenuType::LOAD:
			load(base,file_json);
			break;
		case MenuType::SAVE:
			save(base,file_json);
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

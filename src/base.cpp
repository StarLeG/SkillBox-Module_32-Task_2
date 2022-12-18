#include "base.h"

void show_json()
{

	std::ifstream file_json("film.json");
	if (!file_json.is_open())
	{
		std::cerr << "*** ERROR Open file!!! ***" << std::endl;
		return;
	}

	nlohmann::json obj;

	file_json >> obj;

	file_json.close();

	std::cout << std::setw(4) << obj << std::endl;
}

void read_json_file()
{
}

Movies addMovies()
{
	Movies movies{};
	bool exit = false;
	int index = 0;

	std::cin.ignore();
	std::cout << "Enter the name of the film: ";
	std::getline(std::cin, movies.name);
	std::cout << "Enter the name of the film company: ";
	std::getline(std::cin, movies.data_Movies.distributed.name);
	std::cout << "Enter the name of the director: ";
	std::getline(std::cin, movies.data_Movies.directed.name);
	std::cout << "Enter the name of the screenwriter: ";
	std::getline(std::cin, movies.data_Movies.written.name);
	std::cout << "Enter the name of the manufacturer's country: ";
	std::getline(std::cin, movies.data_Movies.country);
	std::cout << "Enter the duration of the films: ";
	std::cin >> movies.data_Movies.runningTime;
	std::cout << "Enter a year of film: ";
	std::cin >> movies.data_Movies.productionYear;

	while (!exit)
	{
		movies.data_Movies.starring.resize(movies.data_Movies.starring.size() + 1);
		std::cin.ignore();
		std::cout << "Enter the name of the actor: ";
		std::getline(std::cin, movies.data_Movies.starring[index].name);
		std::cout << "Enter the role of the actor: ";
		std::getline(std::cin, movies.data_Movies.starring[index].characters);

		std::cout << "Want to enter the data of another actor? <0> - no, <1> - yes: ";
		std::cin >> exit;
		if (!exit)
		{
			exit = true;
		}
		else
		{
			exit = false;
			index++;
		}
	}

	return movies;
}

void save(std::vector<Movies> &base, std::fstream &file_json)
{
	file_json.open("film.json", std::ios::out);
	if (!file_json.is_open())
	{
		std::cerr << "*** MISTAKE!!! The file cannot be open.***" << std::endl;
		return;
	}

	nlohmann::json obj;

	for (int i = 0; i < base.size(); i++)
	{
		obj[base[i].name][i];
		obj[base[i].name][i]["data_Movies"]["country"] = base[i].data_Movies.country;
		obj[base[i].name][i]["data_Movies"]["productionYear"] = base[i].data_Movies.productionYear;
		obj[base[i].name][i]["data_Movies"]["runningTime"] = base[i].data_Movies.runningTime;
		obj[base[i].name][i]["data_Movies"]["distributed"]["name"] = base[i].data_Movies.distributed.name;
		obj[base[i].name][i]["data_Movies"]["directed"]["name"] = base[i].data_Movies.directed.name;
		obj[base[i].name][i]["data_Movies"]["written"]["name"] = base[i].data_Movies.written.name;
		for (int j = 0; j < base[i].data_Movies.starring.size(); j++)
		{
			obj[base[i].name][i]["data_Movies"]["starring"][j]["name"] = base[i].data_Movies.starring[j].name;
			obj[base[i].name][i]["data_Movies"]["starring"][j]["characters"] = base[i].data_Movies.starring[j].characters;
		}
	}

	file_json << obj;
	file_json.close();
}
void load(std::vector<Movies> &base, std::fstream &file_json)
{
}
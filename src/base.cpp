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
	std::ifstream file_json("film.json");
	if (!file_json.is_open())
	{
		std::cerr << "*** ERROR Open file!!! ***" << std::endl;
		return;
	}

	nlohmann::json object{};
	Movies movies{};
	file_json >> object;
	file_json.close();

	std::string serializedString = object.dump();

	nlohmann::json object_1 = nlohmann::json::parse(serializedString);


	std::cout << movies.id << std::endl;

}

void addMovies_to_base()
{
	Movies movies{};

	std::cout << "Enter id: ";
	std::cin >> movies.id;
	std::cout << "Enter movie title: ";
	std::cin.ignore();
	std::getline(std::cin, movies.data_Movies.name);
	std::cout << "Enter country name: ";
	std::getline(std::cin, movies.data_Movies.country);
	std::cout << "Enter production year: ";
	std::cin >> movies.data_Movies.productionYear;
	std::cout << "Enter movie duration: ";
	std::cin >> movies.data_Movies.runningTime;
	std::cout << "Enter the name of the film studio";
	std::getline(std::cin, movies.data_Movies.distributed.name);
	std::cout << "Enter director's name";
	std::getline(std::cin, movies.data_Movies.directed.name);
	std::cout << "Enter the wall painter's name";
	std::getline(std::cin, movies.data_Movies.written.name);
	std::cout << "Enter the number of actors: ";
	int numberActors = 0;
	std::cin >> numberActors;

	while (numberActors != 0)
	{
		for (int i = 0; i < numberActors; i++)
		{
			std::cout << "Enter actor first name actor: ";
			std::getline(std::cin, movies.data_Movies.starring[i].firstName);
			std::cout << "Enter actor last name actor: ";
			std::getline(std::cin, movies.data_Movies.starring[i].lastName);
			std::cout << "Enter the actor's birthday in the format <day> <month> <year> separated by a space: ";
			std::cin >> movies.data_Movies.starring[i].birthday_day
					 >> movies.data_Movies.starring[i].birthday_month
					 >> movies.data_Movies.starring[i].birthday_year;
			std::cout << "Enter the role of the actor: ";
			std::getline(std::cin, movies.data_Movies.starring[i].characters);

		}
	}


	std::ofstream file_json("test.json");
	if (!file_json.is_open())
	{
		std::cerr << "*** ERROR Open file!!! ***" << std::endl;
		return;
	}
	nlohmann::json object{};
	object["id"] = movies.id;
	object["data_Movies"] = {{ "name",         movies.data_Movies.name },
							 { "country",      movies.data_Movies.country },
							 { "releaseDates", movies.data_Movies.productionYear },
							 { "runningTime",  movies.data_Movies.runningTime }};
	object["data_Movies"]["distributed"] = {{ "name", movies.data_Movies.distributed.name }};
	object["data_Movies"]["directed"] = {{ "name", movies.data_Movies.directed.name }};
	object["data_Movies"]["written"] = {{ "name", movies.data_Movies.written.name }};
	for (int i = 0; i < numberActors; i++)
	{
		object["data_Movies"]["starring"] = {{ "first name", movies.data_Movies.starring[i].firstName },
											 { "last name", movies.data_Movies.starring[i].lastName },
											 { "birthday_day", movies.data_Movies.starring[i].birthday_day },
											 { "birthday_month", movies.data_Movies.starring[i].birthday_month },
											 { "birthday_year", movies.data_Movies.starring[i].birthday_year },
											 { "characters", movies.data_Movies.starring[i].characters }};
	}


	file_json << object;

	file_json.close();
}
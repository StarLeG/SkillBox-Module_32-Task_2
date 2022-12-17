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
	CinemaBase movies{};
	file_json >> object;
	file_json.close();

	std::string serializedString = object.dump();

	nlohmann::json object_1 = nlohmann::json::parse(serializedString);

}

void addMovies_to_base()
{
	CinemaBase movies{};
	movies.cinemaBase.resize(movies.cinemaBase.size() + 1);
	int index = movies.cinemaBase.size() - 1;

	std::cout << "Enter movie title: ";
	std::cin.ignore();
	std::getline(std::cin, movies.cinemaBase[index].name);

	std::cout << "Enter country name: ";
	std::getline(std::cin, movies.cinemaBase[index].data_Movies.country);

	std::cout << "Enter production year: ";
	std::cin >> movies.cinemaBase[index].data_Movies.productionYear;

	std::cout << "Enter movie duration: ";
	std::cin >> movies.cinemaBase[index].data_Movies.runningTime;

	std::cin.ignore();
	std::cout << "Enter the name of the film studio: ";
	std::getline(std::cin, movies.cinemaBase[index].data_Movies.distributed.name);

	std::cout << "Enter director's name: ";
	std::getline(std::cin, movies.cinemaBase[index].data_Movies.directed.name);

	std::cout << "Enter the wall painter's name: ";
	std::getline(std::cin, movies.cinemaBase[index].data_Movies.written.name);

	movies.cinemaBase[index].data_Movies.starring.resize(movies.cinemaBase[index].data_Movies.starring.size() + 1);
	bool flag = false;
	int cnt = 0;

	while (!flag)
	{

		std::cout << "Enter actor first name actor: ";
		std::getline(std::cin, movies.cinemaBase[index].data_Movies.starring[cnt].firstName);
		std::cout << "Enter actor last name actor: ";
		std::getline(std::cin, movies.cinemaBase[index].data_Movies.starring[cnt].lastName);
		std::cout << "Enter the role of the actor: ";
		std::getline(std::cin, movies.cinemaBase[index].data_Movies.starring[cnt].characters);
		std::cout << "Are there other actors? <0> - no <1> - yes: ";
		int answer = 0;
		std::cin >> answer;


		switch (answer)
		{
		case 0:
			flag = true;
			break;
		case 1:
			movies.cinemaBase[index].data_Movies.starring.resize(
					movies.cinemaBase[index].data_Movies.starring.size() + 1);
			std::cin.ignore();
			cnt++;
			break;
		default:
			flag = true;
		}

	}

	std::ofstream file_json("film.json");
	if (!file_json.is_open())
	{
		std::cerr << "*** ERROR Open file!!! ***" << std::endl;
		return;
	}
	nlohmann::json object{};
	object["name"] = movies.cinemaBase[index].name,
			object["data_Movies"] = {{ "name",         movies.cinemaBase[index].name },
									 { "country",      movies.cinemaBase[index].data_Movies.country },
									 { "releaseDates", movies.cinemaBase[index].data_Movies.productionYear },
									 { "runningTime",  movies.cinemaBase[index].data_Movies.runningTime }};
	object["data_Movies"]["distributed"] = {{ "name", movies.cinemaBase[index].data_Movies.distributed.name }};
	object["data_Movies"]["directed"] = {{ "name", movies.cinemaBase[index].data_Movies.directed.name }};
	object["data_Movies"]["written"] = {{ "name", movies.cinemaBase[index].data_Movies.written.name }};
	for (int i = 0; i < movies.cinemaBase[index].data_Movies.starring.size(); i++)
	{
		object["data_Movies"]["starring"][i] = {{ "first name", movies.cinemaBase[index].data_Movies.starring[i].firstName },
												{ "last name",  movies.cinemaBase[index].data_Movies.starring[i].lastName },
												{ "characters", movies.cinemaBase[index].data_Movies.starring[i].characters }};
	}


	file_json << object;

	file_json.close();
}
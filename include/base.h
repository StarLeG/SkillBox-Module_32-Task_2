#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

#include "nlohmann/json.hpp"

namespace f_n
{
	struct Starring
	{
		std::string firstName;
		std::string lastName;
		std::string characters;
	};

	struct Distributed
	{
		std::string name;
	};

	struct Directed
	{
		std::string name;
	};

	struct Written
	{
		std::string name;
	};

	struct Data_Movies
	{
		std::string country;
		int productionYear;
		int runningTime;
		f_n::Distributed distributed;
		f_n::Directed directed;
		f_n::Written written;
		std::vector<f_n::Starring> starring;
	};

	struct Movie
	{
		std::string name;
		f_n::Data_Movies data_Movies;
	};
}

struct CinemaBase
{
	std::vector<f_n::Movie> cinemaBase;
};

void show_json();

void read_json_file();

void addMovies_to_base();
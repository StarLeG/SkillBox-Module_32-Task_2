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
		int birthday_day;
		int birthday_month;
		int birthday_year;
		std::string characters;
		std::string country;
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
		std::string name;
		std::string country;
		std::string releaseDates;
		int runningTime;
		f_n::Distributed distributed;
		f_n::Directed directed;
		f_n::Written written;
		f_n::Starring starring;

	};
}

struct Movies
{
	std::string name;
	f_n::Data_Movies data_Movies;
};

void show_json();
void read_json_file();
void addMovies_to_base();
#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

#include "nlohmann/json.hpp"

enum MenuType
{
	EXIT,
	SHOW_BASE,
	ADD_MOVIES,
	SEARCH_ACTOR,
	SHOW_JSON,
	LOAD,
	SAVE
};

namespace f_n
{
	struct Starring
	{
		std::string name;		
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

	
}

struct Movies
{
	std::string name;
	f_n::Data_Movies data_Movies;
};

void show_json();

void showMovies(std::vector<Movies>& base,std::fstream& file_json);

Movies addMovies();

void save (std::vector<Movies>& base,std::fstream& file_json);
void load (std::vector<Movies>& base,std::fstream& file_json);
void actorSearch(std::vector<Movies>& base,std::fstream& file_json);
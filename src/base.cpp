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


    std::cout << movies.name << std::endl;

}
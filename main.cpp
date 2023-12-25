#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;

 using json = nlohmann::json;

int main()
{
 
    nlohmann::json movieInfo;

    // Добавляем информацию о фильме
    movieInfo["title"] = "Название фильма";
    movieInfo["country"] = "Страна";
    movieInfo["release_date"] = "Дата выхода";
    movieInfo["studio"] = "Студия";
    movieInfo["screenwriter"] = "Автор сценария";
    movieInfo["director"] = "Режиссер";
    movieInfo["producer"] = "Продюсер";

    // Создаем JSON-массив для актеров
    json actors;
    actors.push_back("Актер 5");
    actors.push_back("Актер 6");
    actors.push_back("Актер 7");

    // Добавляем массив актеров в словарь
    movieInfo["actors"] = actors;

    // Сохраняем JSON-словарь в файл
    ofstream file("movie_info.json");
    file << movieInfo.dump(4); // 4 - количество пробелов для форматирования
    file.close();

    
   
    
    return 0;
}




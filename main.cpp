#include <iostream>
#include <cpr/cpr.h>
#include <map>

using namespace std;


int main()
{
     std::string url = "https://httpbin.org/";
    std::string method;
    std::map<std::string, std::string> arguments;

    // Ввод аргументов
    std::string key, value;
    while (true) {
        std::cout << "Введите название аргумента: ";
        std::cin >> key;
        if (key == "post" || key == "get") {
            method = key;
            break;
        }
        std::cout << "Введите значение аргумента: ";
        std::cin >> value;
        arguments[key] = value;
    }

    // Формирование запроса
    cpr::Parameters params;
    for (const auto& arg : arguments) {
        params.Add(cpr::Parameter{arg.first, arg.second});
    }

    // Выполнение запроса
    cpr::Response response;
    if (method == "post") {
        response = cpr::Post(cpr::Url{url + "post"}, params);
    } else if (method == "get") {
        response = cpr::Get(cpr::Url{url + "get"}, params);
    }

    // Вывод ответа сервера
    std::cout << response.text << std::endl;
  
    return 0;
}
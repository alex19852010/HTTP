#include <iostream>
#include <cpr/cpr.h>
#include <map>

using namespace std;


int main()
{
    string url = "https://httpbin.org/";
    string method;
    map<string, string> arguments;

    // Ввод аргументов
    string key, value;
    while (true) {
        cout << "enter argument name: ";
        cin >> key;
        if (key == "post" || key == "get") {
            method = key;
            break;
        }
        cout << "enter value argument: ";
        cin >> value;
        arguments[key] = value;
    }

    // Формирование запроса
    cpr::Parameters params;
    for (auto arg : arguments) {
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
    cout << response.text << std::endl;
  
    return 0;
}
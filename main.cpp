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

    if(method == "post")
    {
      for (auto arg : arguments) {
          cpr::Response r = cpr::Post(cpr::Url{"http://www.httpbin.org/post"},
          cpr::Payload({{"key",arg.first}, {"value", arg.second}}));
          std::cout << r.text << std::endl;
    }

    }

   
     else if (method == "get")
      {
        for (auto arg : arguments) {
            cpr::Response r = cpr::Get(cpr::Url{"http://www.httpbin.org/get"},
            cpr::Parameters{{"key", arg.first}, {"value", arg.second}});
            std::cout << r.text << std::endl;
     }
     
     }
    

  
    return 0;
}


#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
 
 nlohmann::json moveinfo;

 moveinfo["title"] = "Home alone";  
 moveinfo["country"] = "United States";
 moveinfo["release date"] = "1990";
 moveinfo["studio"] = "20 th Century Fox";
 moveinfo["screemwriter"] = "John Hughes";
 moveinfo["director"] = "Chris Columbus";
 moveinfo["producer"] = "John Hughes";

 json actors;
 actors.push_back("Macaulay Culkin");
 actors.push_back("Joe Pesci");
 actors.push_back("Daniel Stern");
 actors.push_back("Catherine O'Hara");

 moveinfo["actors"] = actors;

 ofstream file("movies_info.json");
 file << moveinfo.dump(1);
 file.close();
    return 0;
}




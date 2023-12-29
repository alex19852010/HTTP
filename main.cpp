#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
 
 json database;
 nlohmann::json movie1;

 movie1["title"] = "Home alone 1";  
 movie1["country"] = "United States";
 movie1["release date"] = "1990";
 movie1["studio"] = "20 th Century Fox";
 movie1["screemwriter"] = "John Hughes";
 movie1["director"] = "Chris Columbus";
 movie1["producer"] = "John Hughes";

 json actors1;
 actors1.push_back("Macaulay Culkin");
 actors1.push_back("Joe Pesci");
 actors1.push_back("Daniel Stern");
 actors1.push_back("Catherine O'Hara");

 movie1["actors"] = actors1;


 nlohmann::json movie2;
 movie2["title"] = "Home alone 2";
 movie2["country"]  = "United States";
 movie2["release date"] = "1992";
 movie2["studio"] = "20 th Century Fox";
 movie2["screemwriter"] = "John Hughes";
 movie2["director"] = "Chris Columbus";
 movie2["producer"] = "John Hughes";

 json actors2;
 actors2.push_back("Macaulay Culkin");
 actors2.push_back("Joe Pesci");
 actors2.push_back("Daniel Stern");
 actors2.push_back("Tim Curry");
 actors2.push_back("Brenda Fricker");

 movie2["actors"] = actors2;

 nlohmann::json movie3;
 movie3["title"] = "terminator 1";
 movie3["country"] = "United States";
 movie2["release date"] = "1984";
 movie3["studio"] = "Orion Pictures";
 movie3["screemwriter"] = "James Cameron";
 movie3["director"] = "James Cameron";
 movie3["producer"] = "Gale Anne Hurd";

 json actors3;
 actors3.push_back("Arnold Schwarzenegger");
 actors3.push_back("Linda Hamilton");
 actors3.push_back("Michael Biehn");
 actors3.push_back("Paul Winfield");

 movie3["actors"] = actors3;

 
 nlohmann::json movie4;
 movie4["title"] = "terminator 2";
 movie4["country"] = "United States";
 movie4["release date"] = "1991";
 movie4["studio"] = "	Orion Pictures";
 movie4["screemwriter"] = "William Wisher";
 movie4["director"] = "James Cameron";
 movie4["producer"] = "Gale Anne Hurd";

 json actors4;
 actors4.push_back("Arnold Schwarzenegger");
 actors4.push_back("Linda Hamilton");
 actors4.push_back("Robert Patrick");
 
 movie4["actors"] = actors4;

 database["Home alone 1"] = movie1;
 database["home alone 2"] = movie2;
 database["terminator 1"] = movie3;
 database["terminator 2"] = movie4;



ofstream file("movies_info.json");
file << database.dump(1);
file.close();

string actorName;
cout << "enter name actors: ";
getline(cin, actorName);


    for (auto& movie : database.items()) {
        json movieInfo = movie.value();
        json actors = movieInfo["actors"];
        for (const auto& actor : actors) {
            if (actor == actorName) {
                cout << "film: " << movie.key() << endl;
                break;
            }
        }
    }

    return 0;
}


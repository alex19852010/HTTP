#include <iostream>
#include <cpr/cpr.h>

using namespace std;


int main()
{
    string command;

    while(command != "exit")
    {
        cout << "enter command: ";
        cin >> command;

        if(command == "get")
        {
        cpr :: Response r = cpr :: Get(cpr :: Url("http://httpbin.org/get"));
        cout << r.text << endl;
        }
        

        else if(command == "post")
        {
         cpr :: Response r = cpr :: Post(cpr :: Url("http://httpbin.org/post"));
         cout << r.text << endl;
        }

        else if(command == "put")
        {
          cpr :: Response r = cpr :: Put(cpr :: Url("http://httpbin.org/put"));
          cout << r.text << endl;  
        }

        else if(command == "delete")
        {
          cpr :: Response r = cpr :: Delete(cpr :: Url("http://httpbin.org/delete"));
          cout << r.text << endl;  
        }
       
        else if(command == "patch")
        {
          cpr :: Response r = cpr :: Patch(cpr :: Url("http://httpbin.org/patch"));
          cout << r.text << endl;  
        }
       
    }
    cout << "input error" << endl;

    return 0;
}
#include <iostream>
#include "clsBankClient.h"
using namespace std;

int main() {

    clsBankClient Client1 = clsBankClient::Find("A101");
    if (!Client1.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }
    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("A101", "1234");
    if (!Client2.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }
    Client2.Print();
  
    //Wrong Client
    clsBankClient Client3 = clsBankClient::Find("A105", "2244");
    if (!Client3.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }
    Client3.Print();

    cout << "\nIs Client Exist? " << clsBankClient::IsClientExist("A101") << endl;


    system("pause > 0");
    return 0;
}

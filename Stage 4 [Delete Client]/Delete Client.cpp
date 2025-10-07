#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void DeleteClient()
{
    string AccountNumber = "";

    cout << "Please enter client account number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient DeletedClient = clsBankClient::Find(AccountNumber);
    DeletedClient.Print();

    cout << "\nDelete Client:";
    cout << "\n____________________\n";

    cout << "\nAre you sure you want to delete this client? [Y/N]: ";
    char Answer = 'N';
    cin >> Answer;

    if (toupper(Answer) == 'Y')
    {
        if (DeletedClient.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            DeletedClient.Print(); //The object will be empty
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }
}

int main() {

    DeleteClient();


    system("pause > 0");
    return 0;
}

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void ReadClientInfo(clsBankClient &Client)
{
    cout << "\nEnter First Name: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "Enter Last Name: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "Enter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "Enter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "Enter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "Enter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadPositiveFloatNumber();
}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease enter client account number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\nUpdate Client Info:";
    cout << "\n____________________\n";

    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError, account was not saved because it's Empty.";
        break;
    }
    }
}

int main() {

    UpdateClient();


    system("pause > 0");
    return 0;
}

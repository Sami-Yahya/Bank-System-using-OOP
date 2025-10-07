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

    cout << "Enter Pin Code: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "Enter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadPositiveFloatNumber();
}

void AddNewClient()
{
    string AccountNumber = "";

    cout << "Please enter client account number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is already used, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNew(AccountNumber);

    cout << "\nAdd New Client:";
    cout << "\n____________________\n";

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        NewClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError, account was not saved because it's Empty.";
        break;
    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError account was not saved because account number is used!";
        break;
    }
    }
}

int main() {

    AddNewClient();


    system("pause > 0");
    return 0;
}

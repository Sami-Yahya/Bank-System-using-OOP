#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(20) << left << Client.Email;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowClientsList()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\tClients List (" << vClients.size() << ") Client(s).";
    cout << "\n------------------------------------------------------";
    cout << "-------------------------------------------\n";

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n------------------------------------------------------";
    cout << "-------------------------------------------\n";

    if (vClients.size() == 0)
    {
        cout << "\n\t\t\tNo Clients Available in the System!" << endl;
    }
    else
    {
        for (clsBankClient const &client : vClients)
        {
            PrintClientRecordLine(client);
            cout << endl;
        }
    }

    cout << "\n------------------------------------------------------";
    cout << "-------------------------------------------\n";

}

int main() {

    ShowClientsList();


    system("pause > 0");
    return 0;
}

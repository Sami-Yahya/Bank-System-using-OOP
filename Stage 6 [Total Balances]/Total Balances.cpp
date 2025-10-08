#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>
using namespace std;

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "| " << setw(16) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n------------------------------------------------------";
    cout << "----------------------\n";

    cout << "| " << left << setw(16) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n------------------------------------------------------";
    cout << "----------------------\n";

    if (vClients.size() == 0)
    {
        cout << "\n\t\t\tNo Clients Available in the System!" << endl;
    }
    else
    {
        for (clsBankClient const& client : vClients)
        {
            PrintClientRecordBalanceLine(client);
            cout << endl;
        }
    }

    cout << "\n------------------------------------------------------";
    cout << "----------------------\n";

    double TotalBalances = clsBankClient::GetTotalBalances();
    cout << "\n\t\t\tTotal Balances = " << TotalBalances << endl;
    cout << "\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;
}

int main() {

    ShowTotalBalances();


    system("pause > 0");
    return 0;
}

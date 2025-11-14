#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsLoginRegister : protected clsScreen
{
private:

    static void _PrintLoginRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(50) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(12) << left << LoginRegisterRecord.Permissions;
    }

public:

    static void ShowUsersList()
    {
        vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "    Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        cout << setw(8) << left << "" << "| " << left << setw(50) << "Date/Time";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        if (vLoginRegisterRecord.size() == 0)
        {
            cout << "\n\t\t\tNo Logins Available in the System!" << endl;
        }
        else
        {
            for (clsUser::stLoginRegisterRecord const& record : vLoginRegisterRecord)
            {
                _PrintLoginRecordLine(record);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";
    }

};

#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "Enter Last Name: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "Enter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "Enter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "Enter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "Enter Permissions: \n";
        User.Permissions = _ReadPermissionToSet();
    }

    static int _ReadPermissionToSet()
    {
        int Permission = 0;
        char Answer = 'N';

        cout << "\nDo you want to give full access? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to: \n";

        cout << "\nShow Client List? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pListClients;
        }

        cout << "\nAdd New Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pUpdateClient;
        }

        cout << "\nFind Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pFindClient;
        }

        cout << "\nTransactions? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pTransactions;
        }

        cout << "\nManage Users? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pManageUsers;
        }

        return Permission;
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n________________________";
        cout << "\nFirst Name  : " << User.FirstName;
        cout << "\nLast Name   : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName();
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n________________________\n";
    }

public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";
        cout << "Please enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        _ReadUserInfo(User1);

        clsUser::enSaveResults SaveResult;
        SaveResult = User1.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Updated Successfully :-)\n";
            _PrintUser(User1);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError, user was not saved because it's Empty.";
            break;
        }
        }
    }

};

#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

	static void _Login()
	{
		string UserName, Password;
		bool LoginFailed = false;

        do
        {
            if (LoginFailed)
                cout << "\nInvalid Username/Password!\n\n";

            cout << "Please enter User Name: ";
            UserName = clsInputValidate::ReadString();
            cout << "Please enter Password: ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        clsMainScreen::ShowMainMenu();
	}

public:

    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t     Login Screen");
        _Login();
    }

};

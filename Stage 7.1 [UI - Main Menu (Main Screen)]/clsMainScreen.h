#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenuOptions { eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eTransactions = 6,
		eManageUsers = 7, eLogout = 8 };

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]: ";
	
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between [1 to 8]: ");

		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menu... ";
		system("pause>0");
        ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		cout << "Client List Screen will be here...\n";
	}

	static void _ShowAddNewClientScreen()
	{
		cout << "Add New Client Screen will be here...\n";
	}

	static void _ShowUpdateClientScreen()
	{
		cout << "Update Client Screen will be here...\n";
	}

	static void _ShowDeleteClientScreen()
	{
		cout << "Delete Client will be here...\n";
	}

	static void _ShowFindClientScreen()
	{
		cout << "Find Client Screen will be here...\n";
	}

	static void _ShowTransactionsMenu()
	{
		cout << "Transactions Menu will be here...\n";
	}

	static void _ShowManageUsersScreen()
	{
		cout << "Manage Users Screen will be here...\n";
	}

	static void _ShowExitScreen()
	{
		cout << "End Screen will be here...\n";
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eShowClientList:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eTransactions:
        {
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eManageUsers:
        {
            system("cls");
            _ShowManageUsersScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eLogout:
        {
            system("cls");
            _ShowExitScreen();
            // Login();
            break;
        }
        }
	}

public:

    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Menu");

        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t\tMain Menu Screen\n";
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "==============================================\n";

        _PerformMainMenuOption((enMainMenuOptions) _ReadMainMenuOption());
    }

};


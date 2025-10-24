#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include <iomanip>
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, 
		eUpdateUser = 4, eFindUser = 5, eBackMainMenu = 6 };

	static short _ReadManageUsersMenu()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]: ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between [1 to 6]: ");
	
		return Choice;
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\nPress any key to go back to Manage Users Menu... ";
		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		cout << "Add new user screen will be here..." << endl;
	}

	static void _ShowDeleteUserScreen()
	{
		cout << "Delete user screen will be here..." << endl;
	}

	static void _ShowUpdateUserScreen()
	{
		cout << "Update user screen will be here..." << endl;
	}

	static void _ShowFindUserScreen()
	{
		cout << "Find user screen will be here..." << endl;
	}

	static void _PerformManageUsersOption(enManageUsersOptions ManageUsersOptions)
	{
		switch (ManageUsersOptions)
		{
		case clsManageUsersScreen::eListUsers:
		{
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case clsManageUsersScreen::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case clsManageUsersScreen::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case clsManageUsersScreen::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case clsManageUsersScreen::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case clsManageUsersScreen::eBackMainMenu:
		{
			//do nothing here the main screen will handle it :-)
			break;
		}
		}
	}

public:

	static void ShowManageUsersMenu()
	{
		system("cls");
		_DrawScreenHeader("\t  Manage Users Screen");

		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menu Screen\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Go Back to Main Menu.\n";
		cout << setw(37) << left << "" << "==============================================\n";

		_PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersMenu());
	}

};

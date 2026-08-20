#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankUser.h"
#include"InputValidation.h"
#include <iomanip>
class ClsAddUserScreen :protected ClsHeaderScreen
{
private:
	static void ReadUserInfo(ClsBankUser& User) {
		cout << "\nEnter FirstName: ";
		User.FirstName = InputValidation::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = InputValidation::ReadString();

		cout << "\nEnter Email: ";
		User.Email = InputValidation::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = InputValidation::ReadString();

		cout << "\nEnter User Password: ";
		string Passowrd = InputValidation::ReadString();
		User.SetPassowrd(Passowrd);

		User.SetPermission(_ReadPermission());
	}

	static int _ReadPermission() {

		int permission = 0;
		char answer = 'n';
		cout << "\nDo you want to give full access? y/n? :";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			return -1;
		else
		{
			cout << "\nDo you want to give access to : \n ";

			cout << "\nShow Client List? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::pListClients;

			}
			cout << "\nAdd New Client? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::pAddNewClient;

			}
			cout << "\nDelete User ? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::pDeleteClient;

			}
			cout << "\nUpdate User ? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::pUpdateClients;

			}
			cout << "\nFind User? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::pFindClient;
			}

			cout << "\nTransactions? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::pTranactions;
			}

			cout << "\nManage Users? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::pManageUsers;
			}

			return permission;

		}




	}

public:

	static void AddNewUser() {
		if (!CheckAccessRights(ClsBankUser::enPermissions::pAddNewClient))
		{
			return;
		}
		ClsHeaderScreen::_DrawScreenHeader("Add New User Screen");
		string username = InputValidation::ReadString("Enter The Username Please :) :");
		while (ClsBankUser::IsUserExist(username))
		{
			cout << "This Username already used Try Another one :) :";
			username = InputValidation::ReadString();
		}
		ClsBankUser user = ClsBankUser::GetAddNewUserObject(username);
		ReadUserInfo(user);
		ClsBankUser::enSaveResult result;
		result = user.Save();
		switch (result) {
		case ClsBankUser::enSaveResult::svsucceeded:
			cout << "The User Added Successfully :)\n";
			break;
		case ClsBankUser::enSaveResult::svfailemptyobject:
			cout << "The User Not Added because it's empty :(\n";
			break;
		case ClsBankUser::enSaveResult::svFailedUsernameExists:
			cout << "The Username Already Used :(\n";
			break;

		}
	}



};
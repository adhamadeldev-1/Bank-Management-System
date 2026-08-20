#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankUser.h"
#include"InputValidation.h"
#include <iomanip>
class ClsUpdateUser :protected ClsHeaderScreen
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
			cout << "\nShow Register Users? y/n? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				permission += ClsBankUser::enPermissions::PShowRegisterUser;
			}

			return permission;

		}

	};

public:
	static void UpdateClient() {
		if (!CheckAccessRights(ClsBankUser::enPermissions::pUpdateClients))
		{
			return;
		}
		ClsHeaderScreen::_DrawScreenHeader("Update User Screen");

		string username;
		cout << "Enter The username :) : ";
		username = InputValidation::ReadString();
		while (!ClsBankUser::IsUserExist(username))
		{
			cout << " username is Not Found, Choose Another username :) : ";
			username = InputValidation::ReadString();

		}
		ClsBankUser User = ClsBankUser::Find(username);
		User.print();
		cout << "Update Account Information :) \n";
		cout << "-----------------------------\n";
		ReadUserInfo(User);

		ClsBankUser::enSaveResult result;
		result = User.Save();

		switch (result)
		{
		case ClsBankUser::enSaveResult::svsucceeded:
			cout << "The User Updated Successfully :)\n";
			User.print();
			break;
		case ClsBankUser::enSaveResult::svfailemptyobject:
			cout << "The User Can't Save Because It's Empty :(\n";
			break;
		}
	}


};
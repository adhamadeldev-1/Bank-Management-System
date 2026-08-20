#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankUser.h"
#include"InputValidation.h"
#include <iomanip>
class ClsFindUser :protected ClsHeaderScreen
{
private:
	static string ReadUsername() {
		return InputValidation::ReadString("Enter The Username : ");
	}

public:
	static void FindUser() {
		if (!CheckAccessRights(ClsBankUser::enPermissions::pFindClient))
		{
			return;
		}
		ClsHeaderScreen::_DrawScreenHeader("Find User Screen");
		ClsBankUser User = User.Find(ReadUsername());
		if (ClsBankUser::IsUserExist(User.GetUserName()) && !User.IsEmpty())
		{
			cout << "The User Found :)\n";
			User.print();
		}
		else
			cout << "The User Not Found :(\n";

	}
};



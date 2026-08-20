#pragma once
#include<iostream>
#include <cstdlib>
#include"ClsHeaderScreen.h"
#include"ClsBankUser.h"
#include"ClsMainScreen.h"
#include"InputValidation.h"
#include"ClsLoginRegister.h"
#include"Global.h"
class ClsLoginScreen :protected ClsHeaderScreen
{

public:
	static bool login() {

		string username, password;
		bool LoginFaild = false;
		short Attemps = 3;

		do {
			if (LoginFaild)
			{
				Attemps--;
				if (Attemps == 0) {
					cout << "You are Locked After 3 Trials :(";
					return false;
				}
				cout << "\nInvalid Username/Password!\n";
				cout << "You Have [" << Attemps << "] Trials To Login\n\n";

			}
			username = InputValidation::ReadString("Enter The UserName : ");
			password = InputValidation::ReadString("Enter The Password : ");
			currentUser = ClsBankUser::Find(username, password);
			LoginFaild = currentUser.IsEmpty();
		} while (LoginFaild);
		ClsLoginRegister::SaveThisRegisterUser();
		return true;
	}
	static bool ShowLoginscreen() {
		system("cls");
		ClsHeaderScreen::_DrawScreenHeader("Login Screen");
		return login();
	}

};


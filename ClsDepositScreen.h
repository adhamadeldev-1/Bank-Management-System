#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include <iomanip>
class ClsDepositScreen : protected ClsHeaderScreen
{

public:
	static void Deposit() {
		ClsHeaderScreen::_DrawScreenHeader("Deposit Screen");
		string AccountNumber = InputValidation::ReadString("Enter Account Number :) : ");
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "AccountNumber [" << AccountNumber << "] Not Found Enter Another One : ";
			AccountNumber = InputValidation::ReadString();

		}
		ClsBankClient client = ClsBankClient::Find(AccountNumber);
		client.print();
		int dep = InputValidation::ReadNumber("Enter Positive Amount :) : ");
		while (dep < 0) {
			cout << "Sorry, You Should Enter A Positive Number :( :";
			dep = InputValidation::ReadNumber();

		}
		cout << "Are You Sure You Want To Deposit [" << dep << "] y|n : ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			client.Deposit(dep);
			cout << "New Balance is : " << client.GetBalance() << endl;
			cout << "Process Successful :) \n";

		}

	}
};


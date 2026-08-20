#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include <iomanip>
class ClsWithdrawScreen : protected ClsHeaderScreen
{
public:
	static void Withdraw() {
		ClsHeaderScreen::_DrawScreenHeader("Withdraw Screen");
		string AccountNumber = InputValidation::ReadString("Enter Account Number :) : ");
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "AccountNumber [" << AccountNumber << "] Not Found Enter Another One : ";
			AccountNumber = InputValidation::ReadString();

		}
		ClsBankClient client = ClsBankClient::Find(AccountNumber);
		client.print();
		int amount = InputValidation::ReadNumber("Enter Positive Amount :) : ");
		while (amount <0 || amount>client.GetBalance()) {
			cout << "Sorry, You Should Enter A Valid Amount :( :";
			amount = InputValidation::ReadNumber("Enter Valid Amount Less Than Your Balance : ");

		}
		cout << "Are You Sure You Want To Withdraw [" << amount << "] y|n : ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			client.Withdraw(amount);
			cout << "New Balance is : " << client.GetBalance() << endl;
			cout << "Process Successful :) \n";

		}

	}
};


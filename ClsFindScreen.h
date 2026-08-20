#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include <iomanip>
class ClsFindScreen : protected ClsHeaderScreen
{
private:
	static string ReadAccountNumber() {
		string accountnumber = InputValidation::ReadString("Enter The AccountNumber To Search :) : ");
		return accountnumber;
	}
public:
	static void FindClient()
	{
		ClsHeaderScreen::_DrawScreenHeader("Find Client Screen");
		ClsBankClient client = client.Find(ReadAccountNumber());
		if (ClsBankClient::IsClientExist(client.GetAccountNumber()) && !client.IsEmpty())
		{
			cout << "The Client Found :)\n";
			client.print();
		}
		else
			cout << "The Client Not Found :(\n";

	}
};


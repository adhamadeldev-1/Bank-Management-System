#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include <iomanip>
class ClsAddNewClientScreen :protected ClsHeaderScreen
{
private:
	static void ReadClientInfo(ClsBankClient& Client) {
		cout << "\nEnter FirstName: ";
		Client.FirstName = InputValidation::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = InputValidation::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = InputValidation::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = InputValidation::ReadString();

		cout << "\nEnter PinCode: ";
		string PinCode = InputValidation::ReadString();
		Client.SetPinCode(PinCode);


		float Balance = InputValidation::ReadFloatNumber("\nEnter Account Balance: ");
		Client.SetBalance(Balance);
	}


public:
	static void AddNewClient() {
		ClsHeaderScreen::_DrawScreenHeader("Add Client Screen", "", currentUser.GetUserName());

		string AccountNumber;
		cout << "Enter The AccountNumber :) : ";
		AccountNumber = InputValidation::ReadString();
		while (ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << " AccountNumber Already Used Choose Another AccountNumber :) : ";
			AccountNumber = InputValidation::ReadString();
		}
		ClsBankClient client = ClsBankClient::GetAddNewClientObject(AccountNumber);
		ReadClientInfo(client);
		ClsBankClient::enSaveResult result;
		result = client.Save();
		switch (result)
		{
		case ClsBankClient::enSaveResult::svsucceeded:
			cout << "The Client Added Successfully :)\n";
			client.print();
			break;
		case ClsBankClient::enSaveResult::svfailemptyobject:
			cout << "The Client Can't Save Because It's Empty :(\n";
			break;
		case ClsBankClient::enSaveResult::svFailedAccountNumberExists:
			cout << "The Client Already Exists :(\n";
			break;

		}
	}

};


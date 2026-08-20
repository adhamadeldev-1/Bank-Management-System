#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include <iomanip>
class ClsUpdateScreen :protected ClsHeaderScreen
{
private:
	static void ReadClientInfo(ClsBankClient& Client) {
		Client.FirstName = InputValidation::ReadString("\nEnter FirstName: ");
		Client.LastName = InputValidation::ReadString("\nEnter LastName: ");
		Client.Email = InputValidation::ReadString("\nEnter Email: ");
		Client.Phone = InputValidation::ReadString("\nEnter Phone: ");
		string PinCode = InputValidation::ReadString("\nEnter PinCode : ");
		Client.SetPinCode(PinCode);
		float Balance = InputValidation::ReadFloatNumber("\nEnter Account Balance: ");
		Client.SetBalance(Balance);
	}

public:
	static void UpdateClient() {
		ClsHeaderScreen::_DrawScreenHeader("Update Screen");
			string AccountNumber;
		cout << "Enter The AccountNumber :) : ";
		AccountNumber = InputValidation::ReadString();
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << " AccountNumber is Not Found, Choose Another AccountNumber :) : ";
			AccountNumber = InputValidation::ReadString();

		}
		ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		Client.print();
		cout << "Update Account Information :) \n";
		cout << "-----------------------------\n";
		ReadClientInfo(Client);

		ClsBankClient::enSaveResult result;
		result = Client.Save();

		switch (result)
		{
		case ClsBankClient::enSaveResult::svsucceeded:
			cout << "The Client Updated Successfully :)\n";
			Client.print();
			break;
		case ClsBankClient::enSaveResult::svfailemptyobject:
			cout << "The Client Can't Save Because It's Empty :(\n";
			break;
		}
	}
};


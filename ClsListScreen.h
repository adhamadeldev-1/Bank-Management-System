#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include <iomanip>


class ClsListScreen : protected ClsHeaderScreen
{
private:
	static void PrintClientRecordLine(ClsBankClient& client)
	{
		;
		cout << "| " << left << setw(15) << client.GetAccountNumber();
		cout << "| " << left << setw(20) << client.FirstName + " " + client.LastName;
		cout << "| " << left << setw(12) << client.Phone;
		cout << "| " << left << setw(20) << client.Email;
		cout << "| " << left << setw(10) << client.GetPinCode();
		cout << "| " << left << setw(12) << client.GetBalance();
	}
public:
	static void ShowListClients()
	{

		vector<ClsBankClient>clients = ClsBankClient::GetListClients();

		string size = "(" + to_string(clients.size()) + ") Clients .";
		ClsHeaderScreen::_DrawScreenHeader("List Clients", size);
		cout << "--------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(15) << "AccountNumber";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance" << endl;
		cout << "--------------------------------------------------------------------------------------------------\n" << endl;
		if (clients.size() == 0)
			cout << "\t\t\tNo Clients Available In The System :(\n";
		else
		{
			for (ClsBankClient& c : clients)
			{
				PrintClientRecordLine(c);
				cout << endl;
			}
			cout << "--------------------------------------------------------------------------------------------------\n" << endl;
		}
	}
};


#pragma once
#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include <iomanip>
using namespace std;
class ClsTotalBalancesScreen :protected ClsHeaderScreen
{
private:
	static void GetClientRecordLine(ClsBankClient& Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.GetFirstName() + " " + Client.GetLastName();
		cout << "| " << setw(12) << left << Client.GetBalance();
	}
public:
	static void ShowTotalBalances() {
		vector<ClsBankClient> clients = ClsBankClient::LoadClientFromFile();
		string TotalClients = to_string(clients.size());
		ClsHeaderScreen::_DrawScreenHeader("Total Balances", TotalClients);
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;
		if (clients.size() == 0)
			cout << "No Clients Available :(\n";
		else
		{
			for (ClsBankClient& client : clients)
			{
				GetClientRecordLine(client);
				cout << endl;
			}
		}
		double TotalBalances = ClsBankClient::GetTotalBalances();
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
	}

};


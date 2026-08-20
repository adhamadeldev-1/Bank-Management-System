#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include"Global.h"
#include <string>
#include <iomanip>
class ClsTransferScreen :protected ClsHeaderScreen
{

public:

	struct sTransActionProcess
	{
		string SourceAcountNumber;
		string DectinationAccountNumber;
		float amount;
		string SourceBalance;
		string DestinationBalance;
		string SourceUsername;
	};


	static	void TransferScreen() {
		ClsHeaderScreen::_DrawScreenHeader("Transfer Screen");
		string accountnumber1 = InputValidation::ReadString("Please Enter The Account Number To Transfer From : ");
		while (!ClsBankClient::IsClientExist(accountnumber1))
		{
			cout << "AccountNumber [" << accountnumber1 << "] Not Found Enter Another One : ";
			accountnumber1 = InputValidation::ReadString();
		}
		ClsBankClient sourceclient = ClsBankClient::Find(accountnumber1);
		printinfo(sourceclient);
		string accountnumber2 = InputValidation::ReadString("Please Enter The Account Number To Transfer To : ");
		while (!ClsBankClient::IsClientExist(accountnumber2))
		{
			cout << "AccountNumber [" << accountnumber2 << "] Not Found Enter Another One : ";
			accountnumber2 = InputValidation::ReadString();
		}
		ClsBankClient destinationClient = ClsBankClient::Find(accountnumber2);
		printinfo(destinationClient);

		float amount = 0;
		amount = InputValidation::ReadNumber("Enter The Amount To Transfer : ");

		while (sourceclient.GetBalance() < amount)
		{
			amount = InputValidation::ReadNumber(" The Amount Exceeds The Available Balance Enter Another Amount : ");
		}


		cout << "Are You Sure You Want To Transfer [" << amount << "] y|n : ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			sourceclient.Withdraw(amount);
			destinationClient.Deposit(amount);
			ClsTransferScreen::sTransActionProcess process;
			process.amount = amount;
			process.SourceAcountNumber = sourceclient.GetAccountNumber();
			process.DectinationAccountNumber = destinationClient.GetAccountNumber();
			process.DestinationBalance = to_string(destinationClient.GetBalance());
			process.SourceBalance = to_string(sourceclient.GetBalance());
			process.SourceUsername = currentUser.GetUserName();
			SaveTransferprocessToFile(process);
			cout << "Transfer Done Successfully  :) \n";


		}
	}

private:
	static void printinfo(ClsBankClient& client) {
		cout << "\nClient Card : " << endl;
		cout << " Full Name : " << client.GetFirstName() + " " + client.GetLastName() << endl;
		cout << "Account Number: " << client.GetAccountNumber() << endl;
		cout << " Balance : " << client.GetBalance() << endl;
		cout << "===========================================\n";
	}

	static string GetDateTime()
	{
		time_t now = time(0);
		tm localTime;

		localtime_s(&localTime, &now);

		return to_string(localTime.tm_mday) + "/" +
			to_string(localTime.tm_mon + 1) + "/" +
			to_string(localTime.tm_year + 1900) + " " +
			to_string(localTime.tm_hour) + ":" +
			to_string(localTime.tm_min) + ":" +
			to_string(localTime.tm_sec);
	}

	static string ConvertUserRegisterIntoLine(sTransActionProcess T, string Seperator = "#//#")
	{
		string data = "";
		data += GetDateTime() + Seperator;
		data += T.SourceAcountNumber + Seperator;
		data += T.DectinationAccountNumber + Seperator;
		data += to_string(T.amount) + Seperator;
		data += T.SourceBalance + Seperator;
		data += T.DestinationBalance + Seperator;
		data += T.SourceUsername;
		return data;
	}
	static void SaveTransferprocessToFile(sTransActionProcess& T)
	{

		fstream File;
		File.open(R"(C:\Users\Adham\Downloads\TransferProces.txt)", ios::out | ios::app);
		string dataLine;
		if (File.is_open())
		{
			File << ConvertUserRegisterIntoLine(T) << endl;
			File.close();

		}
	}
};


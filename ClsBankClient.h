#pragma once
#include<iostream>
#include<vector>
#include"Person.h"
#include "clString.h"
#include "ClsUtil.h"
#include <fstream>
#include <string>


using namespace std;
class ClsBankClient :public Person
{
private:
	string AccountNumber;
	string PinCode;
	float Balance;
	bool MakerDelete = false;
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
	enMode Mode;

	static ClsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{

		vector<string>v;
		v = clsString::Split(Line, Seperator);
		return ClsBankClient(enMode::UpdateMode, v[0], v[1], v[2], v[3], v[4], v[5], stod(v[6]));
	}
	static string ConvertClientsIntoLine(ClsBankClient client, string Seperator = "#//#")
	{
		string data = "";
		data += client.FirstName + Seperator;
		data += client.LastName + Seperator;
		data += client.Email + Seperator;
		data += client.Phone + Seperator;
		data += client.AccountNumber + Seperator;
		data += client.PinCode + Seperator;
		data += to_string(client.Balance);
		return data;
	}
	static ClsBankClient _GetEmptyClientObject()
	{
		return ClsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


	void SaveClientsinFile(vector <ClsBankClient> clients)
	{

		fstream File;
		File.open(R"(C:\Users\Adham\Downloads\Clients.txt)", ios::out);
		string dataLine;
		if (File.is_open())
		{
			for (ClsBankClient& c : clients)
			{
				if (c.MakerDelete == false)
				{

					dataLine = ConvertClientsIntoLine(c);
					File << dataLine << endl;
				}
			}
			File.close();

		}

	}

	void SaveClientToFile(const ClsBankClient& client)
	{

		fstream File;
		File.open(R"(C:\Users\Adham\Downloads\Clients.txt)", ios::out | ios::app);
		string dataLine;
		if (File.is_open())
		{
			File << ConvertClientsIntoLine(client) << endl;
			File.close();

		}

	}
	void Update() {
		vector< ClsBankClient> clients = LoadClientFromFile();
		for (ClsBankClient& c : clients)
		{
			if (c.AccountNumber == AccountNumber)
			{
				c = *this;
				break;
			}
		}
		SaveClientsinFile(clients);
	}

	void AddNew()
	{
		SaveClientToFile(*this);
	}
public:
	ClsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AccountNumber, string PinCode, float Balance) :Person(FirstName, LastName, Email, Phone) {
		this->Mode = Mode;
		this->AccountNumber = AccountNumber;
		this->PinCode = PinCode;
		this->Balance = Balance;
	}

	string GetAccountNumber() {
		return AccountNumber;
	}

	void SetPinCode(string PinCode) {
		this->PinCode = PinCode;
	}
	string GetPinCode() {
		return PinCode;
	}

	void SetBalance(float Balance) {
		this->Balance = Balance;
	}
	float GetBalance() {
		return Balance;
	}
	static vector <ClsBankClient> LoadClientFromFile()
	{
		vector <ClsBankClient> clients;
		fstream File;
		File.open(R"(C:\Users\Adham\Downloads\Clients.txt)", ios::in);
		if (File.is_open())
		{
			string line;
			while (getline(File, line))
			{
				ClsBankClient client = _ConvertLinetoClientObject(line);
				clients.push_back(client);
			}

			File.close();

		}
		return clients;


	}
	void print() {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FirstName + " " + LastName;
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << AccountNumber;
		cout << "\nPassword    : " << PinCode;
		cout << "\nBalance     : " << Balance;
		cout << "\n___________________\n";
	}

	bool IsEmpty() {
		return (Mode == enMode::EmptyMode);
	}

	static ClsBankClient Find(string accountnumber)
	{
		fstream MyFile;
		MyFile.open(R"(C:\Users\Adham\Downloads\Clients.txt)", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsBankClient client = _ConvertLinetoClientObject(Line);
				{
					if (client.AccountNumber == accountnumber)
					{
						MyFile.close();
						return client;
					}
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static ClsBankClient Find(string accountnumber, string pincode)
	{
		fstream MyFile;
		MyFile.open(R"(C:\Users\Adham\Downloads\Clients.txt)", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsBankClient client = _ConvertLinetoClientObject(Line);
				{
					if (client.AccountNumber == accountnumber && client.PinCode == pincode)
					{
						MyFile.close();
						return client;
					}
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string AccountNumber)
	{
		ClsBankClient Client1 = ClsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResult {
		svfailemptyobject = 0, svsucceeded = 1, svFailedAccountNumberExists = 3
	};
	bool DeleteClient()
	{
		vector<ClsBankClient>Clients = LoadClientFromFile();
		for (ClsBankClient& c : Clients)
		{
			if (c.AccountNumber == AccountNumber)
			{
				c.MakerDelete = true;
				break;
			}

		}
		SaveClientsinFile(Clients);
		*this = _GetEmptyClientObject();
		return true;
	}

	enSaveResult Save() {

		switch (Mode)
		{
		case enMode::EmptyMode:
			return enSaveResult::svfailemptyobject;
			break;
		case enMode::UpdateMode:
			Update();
			return enSaveResult::svsucceeded;
			break;
		case enMode::AddNewMode:
			if (IsClientExist(AccountNumber))
			{
				return enSaveResult::svFailedAccountNumberExists;
			}
			AddNew();
			Mode = enMode::UpdateMode;
			return enSaveResult::svsucceeded;
			break;

		}
	}

	static ClsBankClient GetAddNewClientObject(string AccountNumber) {
		return ClsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	static vector<ClsBankClient>GetListClients()
	{
		return LoadClientFromFile();
	}

	static float GetTotalBalances()
	{
		vector<ClsBankClient> clints = LoadClientFromFile();
		float total = 0;
		for (ClsBankClient& C : clints)
		{
			total += C.Balance;
		}
		return total;
	}

	void Deposit(float amount) {
		Balance += amount;
		Save();

	}
	void Withdraw(float amount) {
		Balance -= amount;
		Save();

	}

};


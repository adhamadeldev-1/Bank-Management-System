#pragma once
#include<iostream>
#include<string>
#include"ClsBankUser.h"
#include"Global.h"
#include"ClsHeaderScreen.h"
#include"clString.h"
#include <fstream>
#include <ctime>
using namespace std;

class ClsLoginRegister
{
public:
	struct sRegisterUsers
	{
		string date;
		string Name;
		string Password;
		int Permissions;
	};

private:
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


	static string ConvertUserRegisterIntoLine(ClsBankUser user, string Seperator = "#//#")
	{
		string data = "";
		data += GetDateTime() + Seperator;
		data += user.GetUserName() + Seperator;
		data += user.GetPassword() + Seperator;
		data += to_string(user.GetPermissions());
		return data;
	}
	static void SaveUserRegisterToFile(ClsBankUser& client)
	{

		fstream File;
		File.open(R"(C:\Users\Adham\Downloads\UsersRegister.txt)", ios::out | ios::app);
		string dataLine;
		if (File.is_open())
		{
			File << ConvertUserRegisterIntoLine(client) << endl;
			File.close();

		}
	}









	static sRegisterUsers ConvertLineToObject(string Line, string delim = "#//#") {
		vector<string>V = clsString::Split(Line, delim);
		sRegisterUsers user;
		user.date = V[0];
		user.Name = V[1];
		user.Password = V[2];
		user.Permissions = stoi(V[3]);
		return user;
	}


	static vector<sRegisterUsers>LoadUsersFromFile()
	{
		vector <sRegisterUsers> Users;
		fstream File;
		File.open(R"(C:\Users\Adham\Downloads\UsersRegister.text.txt)", ios::in);
		if (File.is_open())
		{
			string line;
			while (getline(File, line))
			{
				sRegisterUsers user = ConvertLineToObject(line);

				Users.push_back(user);
			}

			File.close();

		}
		return Users;
	}
















public:

	static void SaveThisRegisterUser()
	{
		SaveUserRegisterToFile(currentUser);
	}

	static vector < sRegisterUsers> ListRegisterUsers() {
		return LoadUsersFromFile();
	}



};


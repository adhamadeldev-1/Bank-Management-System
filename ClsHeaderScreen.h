#pragma once
#include<iostream>
#include<ctime>
#include"ClsBankUser.h"
#include"Global.h"
using namespace std;
class ClsHeaderScreen
{


protected:

	static bool CheckAccessRights(ClsBankUser::enPermissions permission)
	{
		if (!currentUser.CheckAccessPermission(permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}

	}

	static void _DrawScreenHeader(string Title, string SubTitle = "", string username = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t\t " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t\t\t " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\t User :  " << currentUser.GetUserName();
		cout << "\n\n\t\t\t\t\t Date :  ";
		DateNow();
		cout << endl;



	}

	static void DateNow() {
		time_t now = time(0);
		tm localTime;

		localtime_s(&localTime, &now);

		cout << localTime.tm_mday << "/"
			<< localTime.tm_mon + 1 << "/"
			<< localTime.tm_year + 1900;
	}


};


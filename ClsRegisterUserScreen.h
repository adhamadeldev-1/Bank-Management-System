#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankUser.h"
#include"ClsLoginRegister.h"
#include <iomanip>
using namespace std;

class ClsRegisterUserScreen : protected ClsHeaderScreen
{
private:

    static void PrintUsertRecordLine(ClsLoginRegister::sRegisterUsers user)
    {
        cout << "| " << left << setw(20) << user.date;
        cout << "| " << left << setw(20) << user.Name;
        cout << "| " << left << setw(15) << user.Password;
        cout << "| " << left << setw(15) << user.Permissions;
        cout << "|";
    }

public:

    static void ShowListRegisterUsers()
    {
        if (!CheckAccessRights(ClsBankUser::PShowRegisterUser))
        {
            return;
        }

        vector<ClsLoginRegister::sRegisterUsers> Users =
            ClsLoginRegister::ListRegisterUsers();

        string size = "(" + to_string(Users.size()) + ") Register User(s).";

        ClsHeaderScreen::_DrawScreenHeader("Register Users", size);

        cout << "\n";
        cout << "        =====================================================================\n";

        cout << "        | " << left << setw(20) << "Date";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(15) << "Permissions";
        cout << "|\n";

        cout << "        =====================================================================\n";

        if (Users.size() == 0)
        {
            cout << "\n\t\t\tNo Register Users Available In The System :(\n";
        }
        else
        {
            for (ClsLoginRegister::sRegisterUsers& c : Users)
            {
                cout << "        ";
                PrintUsertRecordLine(c);
                cout << "\n";
            }

            cout << "        =====================================================================\n";
        }
    }
};
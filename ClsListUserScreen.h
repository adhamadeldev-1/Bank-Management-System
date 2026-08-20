#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankUser.h"
#include"InputValidation.h"
#include <iomanip>
class ClsListUserScreen :protected ClsHeaderScreen
{
private:
    static void PrintUserRecordLine(ClsBankUser& User)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.GetPassword();
        cout << "| " << setw(12) << left << User.GetPermissions();
    }

public:
    static void ShowUsersList()
    {
        if (!CheckAccessRights(ClsBankUser::enPermissions::pListClients))
        {
            return;
        }
        vector <ClsBankUser> vUsers = ClsBankUser::GetUserList();

        string Title = "User List Screen";
        string SubTitle = "(" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In The System!";
        else

            for (ClsBankUser User : vUsers)
            {

                PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};


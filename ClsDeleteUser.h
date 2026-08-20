#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankUser.h"
#include"InputValidation.h"
#include <iomanip>
class ClsDeleteUser :protected ClsHeaderScreen
{
public:
    static void DeletClient()
    {
        if (!CheckAccessRights(ClsBankUser::enPermissions::pDeleteClient))
        {
            return;
        }
        ClsHeaderScreen::_DrawScreenHeader("Delete User Screen");

        string username;
        cout << "Enter The Username To Delete It :) : ";
        username = InputValidation::ReadString();
        while (!ClsBankUser::IsUserExist(username))
        {
            cout << " Username is Not Found, Choose Another Username :) : ";
            username = InputValidation::ReadString();
        }
        ClsBankUser User = ClsBankUser::Find(username);
        User.print();
        cout << "Are You Sure You Want To Delete This User? y|n :";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            if (User.DeleteUser()) {
                cout << " The User Deleted Successfully :)\n ";
            }
            else
                cout << " The User Was Not Deleted :)\n ";
        }
    }

};


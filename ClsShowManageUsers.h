#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidation.h"
#include"ClsListUserScreen.h"
#include"ClsAddUserScreen.h"
#include"ClsDeleteUser.h"
#include"ClsUpdateUser.h"
#include"ClsFindUser.h"
#include"ClsLoginScreen.h"
#include"ClsLoginRegister.h"
#include <iomanip>
class ClsShowManageUsers :protected ClsHeaderScreen
{
private:

    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    static short _ReadManageUserMenueOption() {
        short answer;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        answer = InputValidation::ReadShortNumberBetween(1, 6);
        return answer;
    }
    static void _GoBackManageUserMenue() {
        cout << setw(37) << left << "" << "\nPress any key to go back to Main Menu...\n";
        system("pause>0");
        ShowManageUsers();

    }

    static void ListUser() {
        ClsListUserScreen::ShowUsersList();
    }
    static void AddNewUser() {
        ClsAddUserScreen::AddNewUser();
    }
    static void DeleteUser() {
        ClsDeleteUser::DeletClient();
    }
    static void UpdateUser() {
        ClsUpdateUser::UpdateClient();
    }
    static void FindUser() {
        ClsFindUser::FindUser();
    }

    static void MainMenue() {
    }





    static void _PerfoemMangeUserMenueOption(enManageUsersMenueOptions option) {
        switch (option)
        {
        case enManageUsersMenueOptions::eListUsers:
            system("cls");
            ListUser();
            _GoBackManageUserMenue();
            break;
        case enManageUsersMenueOptions::eAddNewUser:
            system("cls");
            AddNewUser();
            _GoBackManageUserMenue();
            break;
        case enManageUsersMenueOptions::eDeleteUser:
            system("cls");
            DeleteUser();
            _GoBackManageUserMenue();
            break;
        case enManageUsersMenueOptions::eUpdateUser:
            system("cls");
            UpdateUser();
            _GoBackManageUserMenue();
            break;
        case enManageUsersMenueOptions::eFindUser:
            system("cls");
            FindUser();
            _GoBackManageUserMenue();
            break;
        case enManageUsersMenueOptions::eMainMenue:
            system("cls");
            MainMenue();
            break;
        }

    }

public:

    static void ShowManageUsers() {
        system("cls");
        ClsHeaderScreen::_DrawScreenHeader("Manage User Screen", "", currentUser.GetUserName());
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "[1] List Users.\n";
        cout << setw(37) << left << "" << "[2] Add New User.\n";
        cout << setw(37) << left << "" << "[3] Delete User.\n";
        cout << setw(37) << left << "" << "[4] Update User.\n";
        cout << setw(37) << left << "" << "[5] Find User.\n";
        cout << setw(37) << left << "" << "[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfoemMangeUserMenueOption(enManageUsersMenueOptions(_ReadManageUserMenueOption()));

    }

};


#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidation.h"
#include"ClsListScreen.h"
#include"ClsAddNewClientScreen.h"
#include"ClsUpdateScreen.h"
#include"ClsDeleteScreen.h"
#include"ClsFindScreen.h"
#include"ClsTransaction.h"
#include"ClsShowManageUsers.h"
#include"ClsLoginScreen.h"
#include"ClsRegisterUserScreen.h"
#include"clscurrancychange.h"
#include"Global.h"
#include <iomanip>


using namespace std;
class ClsMainScreen :protected ClsHeaderScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eShowRegisterUsers = 8, eShowCurrancyScreen = 9, eExit = 10
    };

    static short _ReadMainMenueOption() {
        short answer;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        answer = InputValidation::ReadShortNumberBetween(1, 10);
        return answer;
    }

    static void _GoToMainScreen() {
        cout << setw(37) << left << "" << "\nPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainScreen();
    }


    static void _ShowAllClientsScreen()
    {
        ClsListScreen::ShowListClients();

    }

    static void _ShowAddNewClientsScreen()
    {
        ClsAddNewClientScreen::AddNewClient();

    }

    static void _ShowDeleteClientScreen()
    {
        ClsDeleteScreen::DeletClient();

    }

    static void _ShowUpdateClientScreen()
    {
        ClsUpdateScreen::UpdateClient();


    }

    static void _ShowFindClientScreen()
    {
        ClsFindScreen::FindClient();

    }

    static void _ShowTransactionsMenue()
    {
        ClsTransaction::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        ClsShowManageUsers::ShowManageUsers();
    }

    static void _ShowRegisterUsers()
    {
        ClsRegisterUserScreen::ShowListRegisterUsers();
    }
    static void _ShowCurrancyExchange()
    {
        clscurrancychange::ShowCurrencirsExchangeMenue();
    }


    static void LogOut()
    {
        currentUser.ClearObject();

    }

    static void _PerfoemMainMenueOption(enMainMenueOptions option) {

        switch (option) {

        case enMainMenueOptions::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoToMainScreen();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoToMainScreen();

            break;

        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoToMainScreen();

            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoToMainScreen();

            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoToMainScreen();

            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoToMainScreen();

            break;
        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoToMainScreen();

            break;
        case enMainMenueOptions::eShowRegisterUsers:
            system("cls");
            _ShowRegisterUsers();
            _GoToMainScreen();

            break;
        case enMainMenueOptions::eShowCurrancyScreen:
            system("cls");
            _ShowCurrancyExchange();
            _GoToMainScreen();

            break;


            break;
        case enMainMenueOptions::eExit:
            system("cls");
            LogOut();
            break;

        }
    }








public:
    static void ShowMainScreen() {
        system("cls");
        _DrawScreenHeader("Main Screen", "", currentUser.GetUserName());
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";

        cout << setw(37) << left << "" << "[1] Show Client List.\n";
        cout << setw(37) << left << "" << "[2] Add New Client.\n";
        cout << setw(37) << left << "" << "[3] Delete Client.\n";
        cout << setw(37) << left << "" << "[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "[5] Find Client.\n";
        cout << setw(37) << left << "" << "[6] Transactions.\n";
        cout << setw(37) << left << "" << "[7] Manage Users.\n";
        cout << setw(37) << left << "" << "[8] Show Register Users.\n";
        cout << setw(37) << left << "" << "[9] Show Currency Screen.\n";
        cout << setw(37) << left << "" << "[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfoemMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

    }

};


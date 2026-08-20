#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"InputValidation.h"
#include"ClsDepositScreen.h"
#include"ClsWithdrawScreen.h"
#include"ClsTotalBalancesScreen.h"
#include"ClsTransferList.h"
#include"ClsTransferScreen.h"
#include <iomanip>
class ClsTransaction :protected ClsHeaderScreen
{
private:
    enum enTransactionMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferList = 5, eShowMainMenue = 6
    };
    static short _ReadTransactionMenueOption() {
        short answer;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        answer = InputValidation::ReadShortNumberBetween(1, 6);
        return answer;
    }
    static void  GoBackToTransactionScreen() {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        ShowTransactionsMenue();
    }

    static void Deposit() {
        ClsDepositScreen::Deposit();
    }
    static void Withdraw() {
        ClsWithdrawScreen::Withdraw();
    }
    static void ShowTotalBalance() {
        ClsTotalBalancesScreen::ShowTotalBalances();
    }
    static void ShowTransferScreen() {
        ClsTransferScreen::TransferScreen();
    }
    static void ListTransferLog() {
        ClsTransferList::ShowTransferLogScreen();
    }
    static void _ShowMainMenue() {
    }






    static void _PerformTransactionsMenueOption(enTransactionMenueOptions option) {

        switch (option) {

        case enTransactionMenueOptions::eDeposit:
            system("cls");
            Deposit();
            GoBackToTransactionScreen();
            break;
        case enTransactionMenueOptions::eWithdraw:
            system("cls");
            Withdraw();
            GoBackToTransactionScreen();
            break;
        case enTransactionMenueOptions::eShowTotalBalance:
            system("cls");
            ShowTotalBalance();
            GoBackToTransactionScreen();
            break;
        case enTransactionMenueOptions::eTransfer:
            system("cls");
            ShowTransferScreen();
            GoBackToTransactionScreen();
            break;
        case enTransactionMenueOptions::eTransferList:
            system("cls");
            ListTransferLog();
            GoBackToTransactionScreen();
            break;
        case enTransactionMenueOptions::eShowMainMenue:
            _ShowMainMenue();
            system("cls");

            break;











        }



    }
public:
    static void ShowTransactionsMenue()
    {
        system("cls");
        _DrawScreenHeader("Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "[1] Deposit.\n";
        cout << setw(37) << left << "" << "[2] Withdraw.\n";
        cout << setw(37) << left << "" << "[3] Total Balances.\n";
        cout << setw(37) << left << "" << "[4] Transfer.\n";
        cout << setw(37) << left << "" << "[5] Transfer List.\n";
        cout << setw(37) << left << "" << "[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption(enTransactionMenueOptions(_ReadTransactionMenueOption()));

    }

};


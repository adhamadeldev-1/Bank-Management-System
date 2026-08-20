#pragma once
#include<iostream>
#include <iomanip>
#include"ClsHeaderScreen.h"
#include"InputValidation.h"
#include"ClsListcurrencies.h"
#include"clsFindCurrency.h"
#include"clsUpdateRate.h"
#include"ClsCurrencyCalculator.h"
using namespace std;
class clscurrancychange :protected ClsHeaderScreen
{
private:
    enum enCurrancyMenueOptions {
        eListCurrancies = 1, eFindCurrancy = 2,
        eUpdateRate = 3, eCurrancyCalculator = 4, eMainMenue = 5
    };
    static short _ReadCurrancyMenueOptions() {
        short answer;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        answer = InputValidation::ReadShortNumberBetween(1, 6);
        return answer;
    }
    static void  GoBackToCurrancyMenueScreen() {
        cout << "\n\nPress any key to go back to Currency Menu...";
        system("pause>0");
        ShowCurrencirsExchangeMenue();
    }

    static void ListCurrancies() {
        ClsListcurrencies::ShowListClients();
    }
    static void FindCurrancy() {
        clsFindCurrency::FindCurrency();
    }
    static void UpdateRate() {
        clsUpdateRate::UpdateRate();
    }
    static void CurrancyCalculator() {
        ClsCurrencyCalculator::ShowCurrencyCalculator();
    }
    static void _ShowMainMenue() {
    }






    static void _PerformTransactionsMenueOption(enCurrancyMenueOptions option) {

        switch (option) {

        case enCurrancyMenueOptions::eListCurrancies:
            system("cls");
            ListCurrancies();
            GoBackToCurrancyMenueScreen();
            break;
        case enCurrancyMenueOptions::eFindCurrancy:
            system("cls");
            FindCurrancy();
            GoBackToCurrancyMenueScreen();
            break;

        case enCurrancyMenueOptions::eUpdateRate:
            system("cls");
            UpdateRate();
            GoBackToCurrancyMenueScreen();
            break;
        case enCurrancyMenueOptions::eCurrancyCalculator:
            system("cls");
            CurrancyCalculator();
            GoBackToCurrancyMenueScreen();
            break;
        case enCurrancyMenueOptions::eMainMenue:
            _ShowMainMenue();
            system("cls");
            break;




        }



    }
public:
    static void ShowCurrencirsExchangeMenue()
    {
        system("cls");
        _DrawScreenHeader("Currency Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "[1] List Currencies.\n";
        cout << setw(37) << left << "" << "[2] Find Currency.\n";
        cout << setw(37) << left << "" << "[3] Update Currency.\n";
        cout << setw(37) << left << "" << "[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption(enCurrancyMenueOptions(_ReadCurrancyMenueOptions()));

    }
};



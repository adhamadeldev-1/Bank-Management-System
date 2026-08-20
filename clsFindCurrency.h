#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsCurrency.h"
#include <iomanip>
class clsFindCurrency :protected ClsHeaderScreen
{
private:
	static void _PrintCurrency(ClsCurrency Currency)
	{
		cout << "\n\n";
		cout << "\t\t=============================================\n";
		cout << "\t\t              CURRENCY CARD\n";
		cout << "\t\t=============================================\n";

		cout << "\t\t Country        : " << Currency.GetCountry() << "\n";
		cout << "\t\t Currency Code  : " << Currency.GetCurrencyCode() << "\n";
		cout << "\t\t Currency Name  : " << Currency.GetCurrencyName() << "\n";
		cout << "\t\t Rate (1 USD)   : " << Currency.GetRate() << "\n";

		cout << "\t\t=============================================\n";
		cout << "\n";
	}
	static string ReadCountry() {
		return InputValidation::ReadString("Enter The Country : ");
	}
	static string ReadCode() {
		return InputValidation::ReadString("Enter The Code : ");
	}

public:
	static void FindCurrency() {

		ClsHeaderScreen::_DrawScreenHeader("Find Currency Screen");
		cout << "Find by : [1] Code [2] Country :) : ";
		short answer;
		cin >> answer;
		if (answer == 1)
		{

			ClsCurrency currency = currency.FindByCode(ReadCode());
			if (ClsCurrency::IsCurrencyExistbycountry(currency.GetCountry()) && !currency.IsEmpty())
			{
				cout << "The Currency Found :)\n";
				_PrintCurrency(currency);
			}
			else
				cout << "The Currency Not Found :(\n";
		}
		else
		{
			ClsCurrency currency = currency.FindByCountry(ReadCountry());
			if (ClsCurrency::IsCurrencyExistbycountry(currency.GetCountry()) && !currency.IsEmpty())
			{
				cout << "The Currency Found :)\n";
				_PrintCurrency(currency);
			}
			else
				cout << "The Currency Not Found :(\n";
		}



	}
};


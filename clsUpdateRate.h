#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsCurrency.h"
#include <iomanip>
class clsUpdateRate :protected ClsHeaderScreen
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
	static float ReadRate() {
		return InputValidation::ReadFloatNumber("Enter The New Rate : ");
	}
public:
	static void UpdateRate() {
		ClsHeaderScreen::_DrawScreenHeader("Update Rate Screen");

		string country;
		cout << "Enter The Country You Want To Update This Rate :) : ";
		country = InputValidation::ReadString();
		while (!ClsCurrency::IsCurrencyExistbycountry(country))
		{
			cout << " Country is Not Found, Enter Correct Country :) : ";
			country = InputValidation::ReadString();

		}
		ClsCurrency currency = ClsCurrency::FindByCountry(country);
		_PrintCurrency(currency);
		float NewRate = ReadRate();
		currency.UpdateRate(NewRate);
		_PrintCurrency(currency);
	}

};


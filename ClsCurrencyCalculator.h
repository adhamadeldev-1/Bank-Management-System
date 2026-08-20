#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsCurrency.h"
#include"InputValidation.h"
#include <iomanip>

class ClsCurrencyCalculator : protected ClsHeaderScreen
{
private:
	static ClsCurrency Readobject(string code) {

		while (!ClsCurrency::IsCurrencyExistbycode(code))
		{
			cout << "Currency Not Found, Enter Correct Code Again :) : ";
			code = InputValidation::ReadString();
		}
		return ClsCurrency::FindByCode(code);

	}
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

	static string ReadCode(string massage)
	{
		return InputValidation::ReadString(massage);
	}

	static float TransFromCurrencyToDollar(ClsCurrency currencey, float amount)
	{
		return amount / currencey.GetRate();
	}

	static float TransFromCurrencyanthorone(
		ClsCurrency currencey1,
		ClsCurrency currencey2,
		float amount)
	{
		float result = 1;

		result *= TransFromCurrencyToDollar(currencey1, amount);
		result *= currencey2.GetRate();

		return result;
	}

public:

	static void ShowCurrencyCalculator()
	{
		char answer = 'y';

		do
		{
			system("cls");
			ClsHeaderScreen::_DrawScreenHeader("Currency Calculator Screen");

			string code1, code2;

			code1 = ReadCode("Enter The Currency 1 Please :) : ");



			ClsCurrency currency1 = Readobject(code1);


			code2 = ReadCode("Enter The Currency 2 Please :) : ");

			ClsCurrency currency2 = Readobject(code2);


			float amount = InputValidation::ReadFloatNumber(
				"Enter The Amount Please : "
			);


			if (currency2.GetCurrencyCode() == "USD")
			{
				_PrintCurrency(currency1);

				cout << "\n\t\t=============================================\n";
				cout << "\t\t             CONVERSION RESULT\n";
				cout << "\t\t=============================================\n";

				cout << "\t\t   "
					<< fixed << setprecision(2)
					<< amount << " " << currency1.GetCurrencyCode()
					<< "  =  "
					<< TransFromCurrencyToDollar(currency1, amount)
					<< " USD\n";

				cout << "\t\t=============================================\n";
			}
			else
			{
				_PrintCurrency(currency1);
				_PrintCurrency(currency2);

				cout << "\n\t\t=============================================\n";
				cout << "\t\t             CONVERSION RESULT\n";
				cout << "\t\t=============================================\n";

				cout << "\t\t   "
					<< fixed << setprecision(2)
					<< amount << " " << currency1.GetCurrencyCode()
					<< "  =  "
					<< TransFromCurrencyanthorone(
						currency1,
						currency2,
						amount
					)
					<< " " << currency2.GetCurrencyCode() << "\n";

				cout << "\t\t=============================================\n";
			}


			cout << "\n\t\tDo You Want To Perform Another Calculation : ";
			cin >> answer;

		} while (answer == 'Y' || answer == 'y');
	}
};
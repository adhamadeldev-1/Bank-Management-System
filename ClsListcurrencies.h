#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsCurrency.h"
#include<iomanip>

using namespace std;

class ClsListcurrencies : protected ClsHeaderScreen
{
private:

	static void PrintcurrencyRecordLine(ClsCurrency& Currency)
	{
		cout << "| " << left << setw(30) << Currency.GetCountry();
		cout << "| " << left << setw(20) << Currency.GetCurrencyCode();
		cout << "| " << left << setw(40) << Currency.GetCurrencyName();
		cout << "| " << left << setw(15) << Currency.GetRate();
		cout << "|";
	}

public:

	static void ShowListClients()
	{
		vector<ClsCurrency> currencies = ClsCurrency::GetCurrwnciesList();

		string size = "(" + to_string(currencies.size()) + ") Currencies.";

		ClsHeaderScreen::_DrawScreenHeader("List Currencies", size);

		cout << "---------------------------------------------------------------------------------------------------------------\n";

		cout << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(20) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(15) << "Rate";
		cout << "|\n";

		cout << "---------------------------------------------------------------------------------------------------------------\n";

		if (currencies.empty())
		{
			cout << "\t\t\tNo Currencies Available In The System :(\n";
		}
		else
		{
			for (ClsCurrency& c : currencies)
			{
				PrintcurrencyRecordLine(c);
				cout << endl;
			}

			cout << "---------------------------------------------------------------------------------------------------------------\n";
		}
	}
};
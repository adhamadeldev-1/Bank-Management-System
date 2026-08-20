#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include"clString.h"
#include <iomanip>
class ClsCurrency
{
private:
	enum eMode { EmptyMode = 0, UpdateMode = 1 };
	string Country;
	string CurrencyCode;
	string CurrencyName;
	float Rate;
	eMode Mode;



	static ClsCurrency _ConvertLineToObject(string Line, string Seperator = "#//#") {

		vector<string>v = clsString::Split(Line, Seperator);
		return ClsCurrency(eMode::UpdateMode, v[0], v[1], v[2], stof(v[3]));
	}

	static ClsCurrency GetEmptyObject() {
		return ClsCurrency(eMode::EmptyMode, "", "", "", 0);


	}
	static vector< ClsCurrency> LoadObjectsFromFile() {

		vector< ClsCurrency>currencies;
		fstream File;
		File.open(R"(C:\Users\Adham\Downloads\Currencies.txt)", ios::in);
		if (File.is_open())
		{
			string line;
			while (getline(File, line))
			{
				ClsCurrency currency = _ConvertLineToObject(line);
				currencies.push_back(currency);
			}

			File.close();

		}
		return currencies;


	}
	static string ConverCurrencyObjectToLine(ClsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.GetCountry() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyCode() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.GetRate());

		return stCurrencyRecord;

	}
	static void SaveCurrencyDataToFile(vector <ClsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open(R"(C:\Users\Adham\Downloads\Currencies.txt)", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (ClsCurrency C : vCurrencys)
			{
				DataLine = ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;



			}

			MyFile.close();

		}
	}


	void _Update()
	{
		vector <ClsCurrency> _vCurrencys;
		_vCurrencys = LoadObjectsFromFile();

		for (ClsCurrency& C : _vCurrencys)
		{
			if (C.GetCurrencyCode() == CurrencyCode)
			{
				C = *this;
				break;
			}

		}

		SaveCurrencyDataToFile(_vCurrencys);

	}









public:
	ClsCurrency(eMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		this->Mode = Mode;
		this->Country = Country;
		this->CurrencyCode = CurrencyCode;
		this->CurrencyName = CurrencyName;
		this->Rate = Rate;
	}
	string GetCountry() {
		return Country;
	}
	string GetCurrencyCode() {
		return CurrencyCode;
	}
	string GetCurrencyName() {
		return CurrencyName;
	}
	float GetRate() {
		return Rate;
	}

	void UpdateRate(float NewRate) {
		Rate = NewRate;
		_Update();
	}
	bool IsEmpty() {
		return (Mode == eMode::EmptyMode);
	}

	static   ClsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open(R"(C:\Users\Adham\Downloads\Currencies.txt)", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsCurrency Currency = _ConvertLineToObject(Line);
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}
		return GetEmptyObject();

	}

	static   ClsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open(R"(C:\Users\Adham\Downloads\Currencies.txt)", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsCurrency Currency = _ConvertLineToObject(Line);
				if (clsString::UpperAllString(Currency.GetCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return GetEmptyObject();

	}
	static bool IsCurrencyExistbycountry(string country)
	{
		ClsCurrency currency = ClsCurrency::FindByCountry(country);
		return (!currency.IsEmpty());
	}
	static bool IsCurrencyExistbycode(string code)
	{
		ClsCurrency currency = ClsCurrency::FindByCode(code);
		return (!currency.IsEmpty());
	}

	static vector< ClsCurrency> GetCurrwnciesList() {
		return LoadObjectsFromFile();
	}



};


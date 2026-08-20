#pragma once
#include<iostream>
#include<string>
using namespace std;
class InputValidation
{
public:
	static bool IsNumberBetween(int num, int from, int to)
	{
		if(from<to)
		return (num >= from || num <= to);
		else
			return (num <= from || num >= to);
	}
	static bool IsNumberBetween(double num, double from, double to)
	{
		if(from<to)
		return (num >= from || num <= to);
		else
			return (num <= from || num >= to);
	}
	static int ReadNumber(string massage="")
	{
		int number;
		if (massage.empty())
			cout << "Please Enter Number : ";
		else
			cout << massage;

		cin >> number;
		while (cin.fail())
		{
          
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << massage;
			cin >> number;

		}
		return number;
	}
	static double ReadDBLNumber(string massage)
	{
		double number;
		cout << "Please Enter Number : ";
		cin >> number;
		while (cin.fail())
		{
          
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << massage;
			cin >> number;

		}
		return number;
	}
	static float ReadFloatNumber(string massage="Enter Valid Number : ")
	{
		float number;
		cout << massage;
		cin >> number;
		while (cin.fail())
		{
          
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << massage;
			cin >> number;

		}
		return number;
	}

	static int ReadNumberBetween(int from, int to, string massage)
	{

		int number;
		cout << "Please Enter Number : ";
		cin >> number;
		while (cin.fail() || number<from || number>to)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << massage;
			cin >> number;

		}
		return number;
	}
	static short ReadShortNumberBetween(int from, int to)
	{

		short number;
		cin >> number;
		while (cin.fail() || number<from || number>to)
		{

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error Enter Number Between " << from << " To " << to << ":";
			cin >> number;

		}
		return number;
	}
	static string ReadString(string massage="")
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		cout << massage;
		getline(cin >> ws, S1);
		return S1;
	}
};


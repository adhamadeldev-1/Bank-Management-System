#pragma once
#include <vector>
#include "clString.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;
class ClsUtil
{
public:
	enum LetterType {
		CapitalLitter = 1,
		SmallLitter = 2,
		MixChar = 3,
		Number=4

	};
public:
	static void sRand() {
		srand(time(0));
	}

	static int RondomNumber(int min, int max)
	{
		return rand() % (max - min+1) + min;
	}

	static char RondomChar(LetterType type)
	{
		switch (type)
		{
		case CapitalLitter:
			return 'A' + rand() % 26;

		case SmallLitter:
			return 'a' + rand() % 26;

		case MixChar:
		{
			int r = RondomNumber(1, 3);

			if (r == 1)
				return 'A' + rand() % 26;
			else if (r == 2)
				return 'a' + rand() % 26;
			else
				return '0' + rand() % 10;
		}

		case Number:
			return '0' + rand() % 10;
		}

		return 'A';
	}

	static string GenerateWord(short length, LetterType type) {
		string word = "";
		for (int i = 0; i < length; i++) {
			word += RondomChar(type);
		}
		return word;
	}

	static void GenerateKeys(short count, LetterType type) {

		string word = "";
		string delim = "_";
		for (int i = 0; i < count; i++) {

			for (int j = 0; j < 4; j++) {

				word += GenerateWord(4, type) + delim;
			}

			if (!word.empty())
			{
				word = word.substr(0, word.length() - delim.length());
			}
			cout << "Key [" << i+1 << "] : " << word<<endl;
			word = "";
		}
	}

	static void Swap(int &x, int& y) {
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	static void Swap(string &x, string & y) {
		string temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void ShuffleArrayofNumbers(int Arr[], int length)
	{
		for (int i = 0; i < length; i++) {
			int RandomIndex = RondomNumber(0, length - 1);
			Swap(Arr[i], Arr[RandomIndex]);
		}
	}
	static void ShuffleArrayofString(string Arr[], int length)
	{
		for (int i = 0; i < length; i++) {
			int RandomIndex = RondomNumber(0, length - 1);
			Swap(Arr[i], Arr[RandomIndex]);
		}
	}
	static void FillArrayWithRandomNumber(int arr[], int length) {
		for (int i = 0; i < length; i++) {
			arr[i] = RondomNumber(0, 100);
		}
	}

	static void Encryption(string& text)
	{
		short key = 5;
		for (char& c : text)
		{
			c += key;
		}
	}

	static void Dencryption(string& text)
	{
		short key = 5;
		for (char& c : text)
		{
			c -= key;
		}

	}


















};


#pragma once
#include<iostream>
using namespace std;

class Person {

public:
	 string FirstName;
	 string LastName;
	string Address;
	string Email;
	string Phone;
public:
	Person(string FirstName, string LastName, string Email , string Phone) {
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->Email = Email;
		this->Phone = Phone;
		
	}

	void SetFirstName(string FirstName) {
		this->FirstName = FirstName;
  }
	string GetFirstName() {
		return FirstName;
	}
	
	void SetLastName(string LastName) {
		this->LastName = LastName;
  }
	string GetLastName() {
		return LastName;
	}
	
	void SetEmail(string Email) {
		this->Email = Email;
  }
	string GetEmail() {
		return Email;
	}
	

	void SetPhone(string Phone) {
		this->Phone = Phone;
  }
	string GetPhone() {
		return Phone;
	}










};


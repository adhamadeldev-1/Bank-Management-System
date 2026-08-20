#pragma once
#include<iostream>
#include<vector>
#include"Person.h"
#include "clString.h"
#include "InputValidation.h"
#include "ClsUtil.h"
#include <fstream>
#include <string>

class ClsBankUser :public Person
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode Mode;
    string UserName;
    string Password;
    int Permissions;
    bool MarkedToDelete = false;

    static ClsBankUser ConvertLineToObject(string Line, string delim = "#//#") {
        vector<string>V = clsString::Split(Line, delim);
        ClsUtil::Dencryption(V[5]);
        return ClsBankUser(enMode::UpdateMode, V[0], V[1], V[2], V[3], V[4], V[5], stod(V[6]));
    }
    static string ConvertUserIntoLine(ClsBankUser user, string Seperator = "#//#")
    {
        string data = "";
        string tempPassord = user.Password;
        data += user.FirstName + Seperator;
        data += user.LastName + Seperator;
        data += user.Email + Seperator;
        data += user.Phone + Seperator;
        data += user.UserName + Seperator;
        ClsUtil::Encryption(tempPassord);
        data += tempPassord + Seperator;
        data += to_string(user.Permissions);
        return data;
    }
    static ClsBankUser _GetEmptyObject() {
        return ClsBankUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    static vector<ClsBankUser>LoadUsersFromFile()
    {
        vector <ClsBankUser> Users;
        fstream File;
        File.open(R"(C:\Users\Adham\Downloads\Users.txt)", ios::in);
        if (File.is_open())
        {
            string line;
            while (getline(File, line))
            {
                ClsBankUser user = ConvertLineToObject(line);

                Users.push_back(user);
            }

            File.close();

        }
        return Users;
    }
    static void SaveObjectsInFile(vector< ClsBankUser>Users) {

        fstream File;
        File.open(R"(C:\Users\Adham\Downloads\Users.txt)", ios::out);
        string dataLine;
        if (File.is_open())
        {
            for (ClsBankUser& c : Users)
            {
                if (c.MarkedToDelete == false)
                {

                    dataLine = ConvertUserIntoLine(c);
                    File << dataLine << endl;
                }
            }
            File.close();

        }
    }

    void Update() {
        vector< ClsBankUser> Users = LoadUsersFromFile();
        for (ClsBankUser& c : Users)
        {
            if (c.UserName == UserName)
            {
                c = *this;
                break;
            }
        }
        SaveObjectsInFile(Users);
    }
    void SaveUserToFile(ClsBankUser& client)
    {

        fstream File;
        File.open(R"(C:\Users\Adham\Downloads\Users.txt)", ios::out | ios::app);
        string dataLine;
        if (File.is_open())
        {
            File << ConvertUserIntoLine(client) << endl;
            File.close();

        }

    }
    void AddNew()
    {
        SaveUserToFile(*this);
    }


public:
    ClsBankUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions) :Person(FirstName, LastName, Email, Phone)
    {

        this->Mode = Mode;
        this->UserName = UserName;
        this->Password = Password;
        this->Permissions = Permissions;

    }

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, PShowRegisterUser = 128
    };
    void SetUserName(string username) {
        UserName = username;
    }
    void SetPassowrd(string password) {
        Password = password;
    }
    void SetPermission(int permission) {
        Permissions = permission;
    }
    string  GetUserName() const {
        return UserName;
    }
    string  GetPassword() const {
        return Password;
    }
    string  FullName() const {
        return FirstName + " " + LastName;
    }
    int  GetPermissions() const {
        return Permissions;
    }

    bool IsEmpty() const {
        return (Mode == enMode::EmptyMode);
    }

    static ClsBankUser Find(string username)
    {
        fstream File;
        File.open(R"(C:\Users\Adham\Downloads\Users.txt)", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {

                ClsBankUser user = ConvertLineToObject(Line);
                if (user.UserName == username)
                {
                    File.close();
                    return user;
                }

            }
            File.close();

        }
        return _GetEmptyObject();
    }
    static ClsBankUser Find(string username, string Password)
    {
        fstream File;
        File.open(R"(C:\Users\Adham\Downloads\Users.txt)", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {

                ClsBankUser user = ConvertLineToObject(Line);
                if (user.UserName == username && user.Password == Password)
                {
                    File.close();
                    return user;
                }

            }
            File.close();

        }
        return _GetEmptyObject();
    }
    static bool IsUserExist(string Username)
    {
        ClsBankUser user = ClsBankUser::Find(Username);
        return (!user.IsEmpty());
    }

    bool DeleteUser() {
        vector< ClsBankUser>users = LoadUsersFromFile();
        for (ClsBankUser& user : users)
        {
            if (user.UserName == UserName)
            {
                user.MarkedToDelete = true;
                break;
            }
        }
        SaveObjectsInFile(users);
        *this = _GetEmptyObject();
        return true;
    }

    enum enSaveResult {
        svfailemptyobject = 0, svsucceeded = 1, svFailedUsernameExists = 3
    };

    enSaveResult Save() {

        switch (Mode)
        {
        case enMode::EmptyMode:
            return enSaveResult::svfailemptyobject;
            break;
        case enMode::UpdateMode:
            Update();
            return enSaveResult::svsucceeded;
            break;
        case enMode::AddNewMode:
            if (IsUserExist(UserName))
            {
                return enSaveResult::svFailedUsernameExists;
            }
            AddNew();
            Mode = enMode::UpdateMode;
            return enSaveResult::svsucceeded;
            break;

        }
        return enSaveResult::svfailemptyobject;
    }
    static ClsBankUser GetAddNewUserObject(string Username) {
        return ClsBankUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
    }

    static vector<ClsBankUser>GetUserList()
    {
        return LoadUsersFromFile();
    }
    void print() {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\n Username : " << UserName;
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FirstName + " " + LastName;
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nPassword    : " << Password;
        cout << "\nPermissions     : " << Permissions;
        cout << "\n___________________\n";
    }
    void ClearObject() {
        *this = ClsBankUser::_GetEmptyObject();
    }


    bool CheckAccessPermission(enPermissions Permisssion)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;
        if ((Permisssion & this->Permissions) == Permisssion)
            return true;
        else
            return false;
    }
};
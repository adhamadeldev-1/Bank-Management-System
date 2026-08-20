#pragma once
#include<iostream>
#include"ClsHeaderScreen.h"
#include"ClsBankClient.h"
#include"InputValidation.h"
#include <iomanip>
class ClsDeleteScreen :protected ClsHeaderScreen
{

public:
    static void DeletClient()
    {
        ClsHeaderScreen::_DrawScreenHeader("Delete Client Screen");

        string AccountNumber;
        cout << "Enter The AccountNumber To Delete It :) : ";
        AccountNumber = InputValidation::ReadString();
        while (!ClsBankClient::IsClientExist(AccountNumber))
        {
            cout << " AccountNumber is Not Found, Choose Another AccountNumber :) : ";
            AccountNumber = InputValidation::ReadString();
        }
        ClsBankClient client = ClsBankClient::Find(AccountNumber);
        client.print();
        cout << "Are You Sure You Want To Delete This Client? y|n :";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            if (client.DeleteClient()) {
                cout << " The Client Deleted Successfully :)\n ";
            }
            else
                cout << " The Client Was Not Deleted :)\n ";
        }
    }
};


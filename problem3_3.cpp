#include <iostream>
#include <vector>
using namespace std;

class Bank_account
{
    int Account_number;
    string Account_holder_name;
    double Balance;

    public :
    void Add_account(int Temp_account_number);
    void Deposit();
    void Withdraw();
    int Search(int Temp_account_number);
    void Display_details()
    {
        cout << "\nAccount holder name : " << Account_holder_name << endl;
        cout << "Account Number : " << Account_number << endl;
        cout << "Account balance : " << Balance << endl;
    }
};
int main()
{
    int Choice, Account_count = 0, Temp_account_number, i;
    vector<Bank_account>Account;
    Bank_account a;
    do
    {
        cout << "\nEnter 1 to Add account" << endl;
        cout << "Enter 2 to Deposit amount" << endl;
        cout << "Enter 3 to Withdraw amount" << endl;
        cout << "Enter 4 to Display Account details" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Enter your Choice : ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            if(Account_count == 0)
            {
                cout << "Enter your Account number : ";
                cin >> Temp_account_number;
                a.Add_account(Temp_account_number);
                Account_count++;
                Account.push_back(a);
            }
            else
            {
                cout << "Enter your Account number : ";
                cin >> Temp_account_number;
                for(i=0;i<Account_count;i++)
                {
                    if(Account[i].Search(Temp_account_number))
                    {
                        cout<<"ERROR : ACCOUNT ALREADY EXIST"<<endl;
                        break;
                    }
                    else if(i == Account_count-1)
                    {
                        a.Add_account(Temp_account_number);
                        Account_count++;
                        Account.push_back(a);
                        cout<<"Account added sucessfully"<<endl;
                    }
                }
            }
            break;
        case 2:
            cout << "Enter account number : ";
            cin >> Temp_account_number;
            for (i = 0; i < Account_count; i++)
            {
                if (Account[i].Search(Temp_account_number))
                {
                    Account[i].Deposit();
                    break;
                }
                else if (i == Account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        case 3:
            cout << "Enter account number : ";
            cin >> Temp_account_number;
            for (i = 0; i < Account_count; i++)
            {
                if (Account[i].Search(Temp_account_number))
                {
                    Account[i].Withdraw();
                    break;
                }
                else if (i == Account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        case 4:
            cout << "Enter account number : ";
            cin >> Temp_account_number;
            for (i = 0; i < Account_count; i++)
            {
                if (Account[i].Search(Temp_account_number))
                {
                    Account[i].Display_details();
                    break;
                }
                else if (i == Account_count - 1)
                {
                    cout << "ERROR : INVALID ACCOUNT NUMBER" << endl;
                }
            }
            break;
        case 0:
            cout<<"THANKS FOR VISITING"<<endl;
            break;
        default:
            cout<<"INVALID CHOICE"<<endl;
        }

    } while (Choice != 0);
    return 0;
}

void Bank_account :: Add_account(int Temp_account_number)
{
    Account_number = Temp_account_number;
    cout << "Enter Accoutn holder name : ";
    cin >> Account_holder_name;
    cout << "Enter balance : ";
    cin >> Balance;
}
void Bank_account :: Deposit()
{
    float Temp_amount;
    cout << "Enter amount to be deposited : ";
    cin >> Temp_amount;
    Balance = Balance + Temp_amount;
    cout << "Amount deposited successfuly" << endl;
}

void Bank_account :: Withdraw()
{
    float Temp_amount;
        cout << "Enter amount to withdrawn : ";
        cin >> Temp_amount;
        if (Balance - Temp_amount >= 0)
        {
            Balance = Balance - Temp_amount;
            cout << "RS." << Temp_amount << " withdrawm successffuly" << endl;
        }
        else
        {
            cout << "ERROR : INSUFFICENT BALANCE " << endl;
        }
}
int Bank_account :: Search(int Temp_account_number)
{
    if (Account_number == Temp_account_number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


#include <iostream>
using namespace std;

class Bank_account {
private:
    double Balance;

public:
    Bank_account() { Balance = 0; }

    void Deposit(double Amount) {
        if (Amount > 0) {
            Balance += Amount;
            cout << "Deposit successful! New Balance: " << Balance << endl;
        } else {
            cout << "Invalid Deposit Amount!" << endl;
        }
    }

    void Withdraw(double Amount) {
        if (Amount > 0 && Amount <= Balance) {
            Balance -= Amount;
            cout << "Withdrawal successful! New Balance: " << Balance << endl;
        } else {
            cout << "Error: Either invalid Amount or insufficient Balance!" << endl;
        }
    }

    void Check_balance() {
        cout << "account Balance: " << Balance << endl;
    }
};

int main() {
    Bank_account account;
    double Amount;
    int Choice;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nEnter Choice: ";
        cin >> Choice;

        switch (Choice) {
            case 1:
                cout << "Enter Deposit Amount: ";
                cin >> Amount;
                account.Deposit(Amount);
                break;
            case 2:
                cout << "Enter Withdrawal Amount: ";
                cin >> Amount;
                account.Withdraw(Amount);
                break;
            case 3:
                account.Check_balance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Choice! Try again." << endl;
        }
    } while (Choice != 4);

    return 0;
}

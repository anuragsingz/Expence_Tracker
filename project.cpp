#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Expense {
public:
    string date;
    string category;
    float amount;
    string note;

    void input() {
        cout << "\nEnter Date (DD-MM-YYYY): ";
        cin >> date;

        cout << "Enter Category (Food/Travel/Shopping/etc): ";
        cin >> category;

        cout << "Enter Amount: ";
        cin >> amount;

        cin.ignore();
        cout << "Enter Note: ";
        getline(cin, note);
    }

    void display() {
        cout << "\nDate: " << date;
        cout << "\nCategory: " << category;
        cout << "\nAmount: Rs. " << amount;
        cout << "\nNote: " << note << endl;
    }
};

void addExpense() {
    Expense e;
    ofstream file("expenses.txt", ios::app);

    e.input();

    file << e.date << " "
         << e.category << " "
         << e.amount << " "
         << e.note << endl;

    file.close();

    cout << "\nExpense Added Successfully!\n";
}

void viewExpenses() {
    ifstream file("expenses.txt");

    string date, category, note;
    float amount;

    cout << "\n===== All Expenses =====\n";

    while (file >> date >> category >> amount) {
        file.ignore();
        getline(file, note);

        cout << "\nDate: " << date;
        cout << "\nCategory: " << category;
        cout << "\nAmount: Rs. " << amount;
        cout << "\nNote: " << note << endl;
    }

    file.close();
}

void totalExpense() {
    ifstream file("expenses.txt");

    string date, category, note;
    float amount, total = 0;

    while (file >> date >> category >> amount) {
        file.ignore();
        getline(file, note);
        total += amount;
    }

    file.close();

    cout << "\nTotal Spending: Rs. " << total << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Total Spending\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                totalExpense();
                break;

            case 4:
                cout << "\nThank You!\n";
                return 0;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}

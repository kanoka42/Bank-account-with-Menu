// BankAccount.cpp : Defines the entry point for the console application.
// Getting cents from an ATM?
// Destry Amiott

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

unsigned long long enteredAccount;
unsigned long long accounts[5];
unsigned long long accountMoney[5];
unsigned long long initialDeposit[5];
string answer;
int money;
char choice;
int checked;
void accountNew();
void depositNew();
void withdrawNew();
void balanceNew();
void entered(string);
void menu();
int i = 0;

//Account class declaration
class bank
{
	private:
		int id;
		double balance_one;
		double balance_two;
		double depMoney;
		double withNew;
		double depMoneyTwo;
		double moneyTwo;
	public:
		void Account(int, double);
		void setId(int);
		void setBalance(double);
		void setSecBalance(double);
		void withdraw(double);
		void withdrawTwo(double);
		void deposit(double);
		double totalOne() const;
		void depositTwo(double);
		double totalTwo() const;
		int getId() const;

		
};



void bank::Account(int newID, double initialBalance)
{
	id = newID;
	balance_one = initialBalance;
}

void bank::setId(int setID)
{
	id = setID;
}

void bank::setBalance(double a)
{
	balance_one = a;

}

void bank::setSecBalance(double b)
{
	balance_two = b;
}

void bank::withdraw(double w)
{
	withNew = (w * -1);
}

void bank::withdrawTwo(double x)
{
	moneyTwo = (x * -1);
}

void bank::deposit(double d)
{
	depMoney = d;
}

void bank::depositTwo(double y)
{
	depMoneyTwo = y;
}

double bank::totalOne() const
{
	return (balance_one + depMoney + withNew);
}

double bank::totalTwo() const
{
	return (balance_two + depMoneyTwo + moneyTwo);
}

int bank::getId() const
{
	return id;
}

int main()
{
	bank box; // Define bank class
	int id; // local int for id
	double balance_one;
	double balance_two;
	double deposit;
	double depositTwo;
	double withdraw;
	double withdrawTwo;

	// ************** Start the program ******************

	cout << "\t\tWelcome to the worlds simplest bank!";
	cout << "\n\n\n";
	cout << "We can process 4 different commands: account, deposit, withdraw, and balance." << endl;
	cout << "Why don't you go ahead and open a new account! ";
	cin >> answer;
	if (answer == "account") {
		accountNew();
	}
	else if (answer == "deposit") {
		depositNew();
	}
	else if (answer == "withdraw") {
		withdrawNew();
	}
	else if (answer == "balance") {
		balanceNew();
	}
	else { menu(); }


	system("CLS");
	system("PAUSE");
    return 0;
}

void menu()
{
	system("CLS");
	cout << "You are back at the main menu, enter any of the commands" << endl;
	cout << "to go to that section: ";
	cin >> answer;

	if (answer == "account")
	{
		accountNew();
	}

	else if (answer == "deposit")
	{
		depositNew();
	}
	else if (answer == "withdraw") {
		withdrawNew();
	}
	else if (answer == "balance") {
		balanceNew();
	}
}

void accountNew()
{
	bool letter = false;
	bool called = true;
	system("CLS");


	if (i == 5) {
		cout << "I am sorry, but we cannot hold anymore accounts. Try editing the ones you have.";
		menu();
	}

	else {
		cout << "We can store and access up to 5 accounts at once, and the best part is you" << endl;
		cout << " get to come up with the account number! It can be from 1-9 numbers in length" << endl;
		cout << " so what is that account number? ";
		cin >> enteredAccount;

		if (enteredAccount > 999999999) {
			cout << "You need to enter an account from 1 to 9 digits!" << endl;
			system("PAUSE");
			accountNew();
		}

		if (called == true)
		{
			i = i++;
		}

		accounts[i] = enteredAccount;

		if (cin.fail()) {
			cin.clear();
			cout << "Please enter a number!";
			system("CLS");
			accountNew();
		}

		else {
			cout << "Great your new account number " << accounts[i] << " is all set up!" << endl;
			cout << "Would you like to deposit money in it now? ";
			cin >> answer;

			if (answer.length() < 2)
			{
				cout << "Your answer must be at least 3 letters long! Try again: ";
				cin >> answer;
			}

			answer = answer.at(0);


			if (answer == "y" || answer == "Y")
			{
				depositNew();
			}

			else if (answer == "n" || answer == "N") {
				cout << "Thank you for using the worlds simplest bank!" << endl;
				menu();
			}

			else
			{
				cout << "Those are not one of the choices! Try again: " << endl;
				cin >> answer;

				if (answer == "y" || answer == "Y")
				{
					depositNew();
				}

				else if (answer == "n" || answer == "N") {
					cout << "Thank you for using the worlds simplest bank!" << endl;
				}

				else {
					cout << "I am sorry we are unable to complete your request, good bye!";
					return;
				}
			}
		}
	}
}

void depositNew() {

	bool swap = false;
	system("CLS");
	cout << "Great so you want to add money to  your accounts? " << endl;
	cout << "Which account do you want to add to? Please enter a number between 1 and 5: ";
	cin >> checked;

	if (accounts[checked] != NULL) {

		while (checked > 5 || checked == '0') {
			cout << "You must enter a number between 1 and 5: ";
			cin >> checked;

			if (checked > 0 && checked < 5) {
				cout << "Okay so account " << accounts[checked] << " ?";
			}
		}

		if (checked > 0 && checked < 5) {
			cout << "Okay you have chosen to add money to account: " << accounts[checked] << " ." << endl;
			cout << "How much do you wish to  deposit? ";
			cin >> initialDeposit[checked];
			cout << "So the balance of account " << accounts[checked] << " is $" << initialDeposit[checked] << endl;
			cout << "Would you like to deposit more, withdraw some, see your balance or open an account? ";
			cin >> answer;

			if (answer == "account") {
				accountNew();
				swap = true;
			}

			else if (answer == "deposit") {
				depositNew();
				swap = true;
			}
			else if (answer == "withdraw") {
				withdrawNew();
				swap = true;
			}
			else if (answer == "balance") {
				balanceNew();
				swap = true;
			}

			else {
				cout << "That is not a recognized commamd, please try again.";
				while (swap = false) {
					cout << "Returning to the main menu....";
					menu();
				}
			}
		}

	}
	else {
		cout << "There is no account open there! Use the account command to open one! ";
		cin >> answer;
		if (answer == "account") {
			accountNew();
		}
		else {
			cout << "Returning to the main menu";
			menu();
		}
	}

}


void withdrawNew() {
	system("CLS");
	bool swap = false;
	cout << "Okay, so you want to withdraw money. " << endl;
	cout << "Enter a number between 1 and 5 for your account: ";
	cin >> checked;

	if (accounts[checked] != NULL) {

		while (checked > 5 || checked == '0') {
			cout << "You must enter a number between 1 and 5: ";
			cin >> checked;

			if (checked > 0 && checked < 5) {
				cout << "Okay so account " << accounts[checked] << " ?";
			}
		}

		if (checked > 0 && checked < 5) {
			cout << "Okay you have chosen to withdraw money from account: " << accounts[checked] << " .";
			cout << "How much do you wish to withdraw? ";
			cin >> accountMoney[checked];
			cout << "So the balance of account " << accounts[checked] << " is $" << (initialDeposit[checked] - accountMoney[checked]) << endl;
			cout << "Would you like to deposit more, withdraw some, see your balance or open an account? ";
			cin >> answer;

			if (answer == "account") {
				accountNew();
				swap = true;
			}

			else if (answer == "deposit") {
				depositNew();
				swap = true;
			}
			else if (answer == "withdraw") {
				withdrawNew();
				swap = true;
			}
			else if (answer == "balance") {
				balanceNew();
				swap = true;
			}

			else {
				cout << "That is not a recognized command, please try again.";
				while (swap = false) {
					cout << "Returning to the main menu....";
					menu();
				}
			}
		}

	}
	else {
		cout << "There is no account open there! Use the account command to open one! ";
		cin >> answer;
		if (answer == "account") {
			accountNew();
		}
		else {
			cout << "Returning to the main menu";
			menu();
		}
	}


}


void balanceNew() {
	system("CLS");
	bool swap = false;
	cout << "Okay, what account do you want to see the balance of? " << endl;
	cout << "Please enter a number between 1 and 5 ";
	cin >> checked;

	if (accounts[checked] != NULL) {

		while (checked > 5 || checked == '0') {
			cout << "You must enter a number between 1 and 5: ";
			cin >> checked;

			if (checked > 0 && checked < 5) {
				cout << "Okay so account " << accounts[checked] << " ?" << endl;
				cout << "The balance is: " << (initialDeposit[checked] - accountMoney[checked]);
			}
		}

		if (checked > 0 && checked < 5) {
			cout << "So the balance of account " << accounts[checked] << " is $" << (initialDeposit[checked] - accountMoney[checked]) << endl;
			cout << "Would you like to deposit more, withdraw some, see a new balance or open an account? ";
			cin >> answer;

			if (answer == "account") {
				accountNew();
				swap = true;
			}

			else if (answer == "deposit") {
				depositNew();
				swap = true;
			}
			else if (answer == "withdraw") {
				withdrawNew();
				swap = true;
			}
			else if (answer == "balance") {
				balanceNew();
				swap = true;
			}

			else {
				cout << "That is not a recognized command, please try again.";
				while (swap = false) {
					cout << "Returning to the main menu....";
					menu();
				}
			}
		}
		else if (checked == NULL) {
			cout << "There is no account open there! Use the account command to open one! ";
			cin >> answer;
			if (answer == "account") {
				accountNew();
			}
			else {
				cout << "Returning to the main menu";
				menu();
			}
			system("PAUSE");
		}
	}
}
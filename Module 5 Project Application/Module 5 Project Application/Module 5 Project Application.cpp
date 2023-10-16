#include <iostream>
#include <iomanip>
#include "Data.h"
using namespace std;

void PrintMenu() { //Prints Menu without Inputed Values
	cout << setfill('*') << setw(30) << "" << endl;
	cout << setfill('*') << setw(9) << "" << " Data Input " << setfill('*') << setw(9) << "" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	cout << "Enter All Values Above.Then Enter any Key and Click 'Enter'" << endl;
}

void PrintMenuInput(double amount, double deposit, int interest, int years) { //Prints Menu with Inputed Values
	cout << fixed << setprecision(2);
	cout << setfill('*') << setw(30) << "" << endl;
	cout << setfill('*') << setw(9) << "" << " Data Input " << setfill('*') << setw(9) << "" << endl;
	cout << "Initial Investment Amount: $" << amount << endl;
	cout << "Monthly Deposit: $" << deposit << endl;
	cout << "Annual Interest: %" << interest << endl;
	cout << "Number of Years: " << years << endl;
	cout << "Click any Key then Enter to Continue." << endl;
}

void calcWithoutDeposit(int year, double amount, double interest) { //Calculates  Yearly End Balance WITHOUT Deposit
	double endBalance;
	interest = interest * .01;
	for (int i = 1; i <= year; ++i) {
		endBalance = amount + (amount * interest);
		cout << fixed << setprecision(2);
		cout << i << "			$" << endBalance << "				  $" << endBalance - amount << endl;
		amount = endBalance;
	}
	
}

void calcWithDeposit(int years, double initialAmount, double monthlyDeposit, double annualInterestRate) { //Calculates  Yearly End Balance WITH Deposit
	double balance = initialAmount;
	double monthlyInterestRate = annualInterestRate / 12 / 100;

	for (int year = 1; year <= years; ++year) {
		double interestEarned = 0;

		for (int month = 1; month <= 12; ++month) {
			balance += monthlyDeposit;
			interestEarned += balance * monthlyInterestRate;
			balance += balance * monthlyInterestRate;
		}
		cout << fixed << setprecision(2);
		cout << setfill(' ') << year << setw(23) << "$" << balance << "				  $" << interestEarned << endl;
	}
}



void PrintWithoutDeposit(int year, double amount, double interest) { //Prints Balance and Interest WITHOUT Deposit
	cout << "	" << "Balance and Interest Without Additional Monthly Deposits" << "	" << endl;
	cout << setfill('=') << setw(75) << "" << endl;
	cout << setfill(' ');
	cout << "Year " << setw(14) << "" << "Year End Balance " << setw(14) << "" << "Year End Earned Interest" << setw(14) << "" << endl;
	cout << setfill('-') << setw(75) << "" << endl;
	calcWithoutDeposit(year, amount, interest);
}

void PrintWithDeposit(int year, double amount, double deposit, double interest) { //Prints Balance and Interest WITH Deposit
	cout << "	" << "Balance and Interest With Additional Monthly Deposits" << "	" << endl;
	cout << setfill('=') << setw(75) << "" << endl;
	cout << setfill(' ');
	cout << "Year " << setw(14) << "" << "Year End Balance " << setw(14) << "" << "Year End Earned Interest" << setw(14) << "" << endl;
	cout << setfill('-') << setw(75) << "" << endl;
	calcWithDeposit(year, amount, deposit, interest);
}

int contKey() { //Continue Command
	char x;
	if (cin >> x) {
		return 0;
	}
}





int main() {
	double amount; //Input Values
	double deposit;
	int interest;
	int years;
	Data dataSet;

	PrintMenu(); //Print Initial Menu and Assigm Inputs
	cin >> amount;
	cin >> deposit;
	cin >> interest;
	cin >> years;

	dataSet.SetInitialAmount(amount); //Put inputs into class for easy access and mutation
	dataSet.SetMonthlyDeposit(deposit);
	dataSet.SetAnnualInterest(interest);
	dataSet.SetNumberYears(years);
	
	contKey(); //Continue Command
	PrintMenuInput(dataSet.GetInitialAmount(), dataSet.GetMonthlyDeposit(), dataSet.GetAnnualInterest(), dataSet.GetNumberYears()); //Print Menu With Inputs
	contKey();
	PrintWithoutDeposit(dataSet.GetNumberYears(), dataSet.GetInitialAmount(), dataSet.GetAnnualInterest()); //Print Both Instances 
	PrintWithDeposit(dataSet.GetNumberYears(), dataSet.GetInitialAmount(), dataSet.GetMonthlyDeposit(), dataSet.GetAnnualInterest());
}



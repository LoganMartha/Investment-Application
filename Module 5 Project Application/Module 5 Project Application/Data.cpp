#include <iostream>
#include <iomanip>
#include "Data.h"
using namespace std;
//Mutators
void Data::SetInitialAmount(double amount) {
	initialAmount = amount;
}

void Data::SetMonthlyDeposit(double deposit) {
	monthlyDeposit = deposit;
}

void Data::SetAnnualInterest(int interest) {
	annualInterest = interest;
}

void Data::SetNumberYears(int years) {
	numberOfYears = years;
}

//Accessors
double Data::GetInitialAmount() const {
	return initialAmount;
}

double Data::GetMonthlyDeposit() const {
	return monthlyDeposit;
}

int Data::GetAnnualInterest() const {
	return annualInterest;
}

int Data::GetNumberYears() const {
	return numberOfYears;
}


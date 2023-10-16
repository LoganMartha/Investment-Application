#pragma once
class Data {
	public: //Public Objects for Class
		void SetInitialAmount(double amount); 
		void SetMonthlyDeposit(double deposit);
		void SetAnnualInterest(int interest);
		void SetNumberYears(int years);
		double GetInitialAmount() const;
		double GetMonthlyDeposit() const;
		int GetAnnualInterest() const;
		int GetNumberYears() const;

	private: //Private Objects for Class
		double initialAmount;
		double monthlyDeposit;
		int annualInterest;
		int numberOfYears;
};


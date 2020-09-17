//write include statements
#include<iostream>
#include "variables.h"

//write namespace using statement for cout
using std::cin;
using std::cout;

int main()
{
	double mealAmount;
	double tipRate;
	double tipAmount;
	double taxAmount;
	double total;

	cout<<"Enter Meal Amount:\n";
	cin>>mealAmount;

	cout<<"Enter Tip Rate:\n";
	cin>>tipRate;

	taxAmount = get_sales_tax_amount(mealAmount);
	tipAmount = get_tip_amount(mealAmount, tipRate);
	total = mealAmount + taxAmount + tipAmount;

	cout<<"ORDER RECEIPT\n";
	cout<<"Meal Amount: " << mealAmount << "\n";
	cout<<"Sales Tax: " << taxAmount << "\n";
	cout<<"Tip Amount: "<< tipAmount << "\n";
	cout<<"---------------" << "\n";
	cout<<"Total: " << total;

	return 0;
}

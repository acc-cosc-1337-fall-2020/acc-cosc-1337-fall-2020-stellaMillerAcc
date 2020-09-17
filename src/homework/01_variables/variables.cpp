#include "variables.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//Homework 1
const double TAX_RATE = .0675;

double get_sales_tax_amount(double mealAmount)
{
	return mealAmount*TAX_RATE;
}

double get_tip_amount(double mealAmount, double tipRate)
{
	return mealAmount*tipRate;
}


//Write the include statement for types.h here
#include "types.h";
//Write include for capturing input from keyboard and displaying output to screen
#include<iostream>;

using std::cin;
using std::cout;

int main() 
{
	int num;

	cout<<"Enter a Number: \n";
	cin>>num;

	int result = multiply_numbers(num);
	cout<<"Result: \n";
	cout<<result;

	int num1 = 4;
	result = multiply_numbers(num1);

	cout<<"\nResult 2: \n";;
	cout<<result;

	return 0;
}


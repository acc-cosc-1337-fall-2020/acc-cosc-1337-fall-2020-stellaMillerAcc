//write includes statements
#include<iostream>
#include<limits>
#include "loops.h"
//write using statements for cin and cout
using std::cout;
using std::cin;
/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int prompt;
	char tryAgain;

	// Validation fails and program exits when you enter a valid integer followed by nonsense strings, or when you enter a decimal.
	// Apparently, the fix to this is lengthy, and so was not tackled as a part of this assignment.
	do {
		while (cout<<"Please enter a number between 1 and 10.\n" && (!(cin>>prompt) || prompt < 1 || prompt > 10)) {
			cout<<"Invalid input. Please try again. \n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		};

		int result = factorial(prompt);

		cout<<"Result is: " << result << " \n";
		cout<<"Try Again? (enter y to continue, or any other character to exit.) \n";
		cin>>tryAgain;
	}
	while(tryAgain == 'y');

	return 0;
}
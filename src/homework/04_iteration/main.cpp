//write include statements
#include<iostream>
#include"dna.h"
//write using statements
using std::cin;
using std::cout;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int prompt;
	char doAnother;

	do {
		string menu = "Make a selection\n----------------\n1: Get GC Content of Dna Strand\n2: Get DNA reverse complement.\n";
		string dnaInput;
		string dnaResult;
		double gcContentResult;

		while (cout<<menu && (!(cin>>prompt) || (prompt != 1 && prompt !=2))) {
			cout<<"Invalid input. Please try again. \n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		};

		cout<<"Please enter a dna sequence (please use capital letters for accurate results): \n";
		cin>>dnaInput;

		if (prompt == 1) {
			gcContentResult = get_gc_content(dnaInput);
			cout<<"Result is: " << gcContentResult << " \n";
		} else if (prompt == 2) {
			dnaResult = get_dna_complement(dnaInput);
			cout<<"Result is: " << dnaResult << " \n";
		}

		cout<<"Do another? (enter y to continue, or any other character to exit.) \n";
		cin>>doAnother;
	}
	while(doAnother == 'y' || doAnother == 'Y');

	return 0;
}
//Write the include statement for decisions.h here
#include "decision.h"
#include<iostream>
//Write namespace using statements for cout and cin
using std::cin;
using std::cout;

int main() 
{
	int grade;

	do {
		cout<<"Please enter a grade between 0 and 100: \n";
		cin>>grade;
		if (grade > 100 || grade < 0){
			cout<<"Grade out of range. Please try again.\n";
		}
	}
	while (grade > 100 || grade < 0);

	string ifLetterGrade = get_letter_grade_using_if(grade);
	string switchLetterGrade = get_letter_grade_using_switch(grade);

	cout<<"Letter Grade (From if/else function): " + ifLetterGrade + "\n";
	cout<<"Letter Grade (From switch function): " + switchLetterGrade + "\n";

	return 0;
}


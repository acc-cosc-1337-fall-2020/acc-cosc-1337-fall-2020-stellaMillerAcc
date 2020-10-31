#include"tic_tac_toe.h"
#include<iostream>
#include<sstream>

using std::cout;
using std::cin;
using std::string;
using std::stringstream;

int main() 
{
	string firstPlayer;
	TicTacToe game;
	string positionString;
	int position;
	char doAnother;
	bool invalid = false;

	do {
		cout<<"---Welcome to Tic Tac Toe!---\n";
		cout<<"---Press Q at any time to quit---\n";

		do {
			cout<<"Enter first player (X or O): ";
			cin>>firstPlayer;
			if (firstPlayer != "O" && firstPlayer != "X" && firstPlayer != "Q")
			{
				invalid = true;
				cout<<"Invalid input. Please try again. \n";
				cin.clear();
			}

		}while (invalid);

		if (firstPlayer == "Q")
			break;

		game.start_game(firstPlayer);

		while (!game.game_over()) {
			game.display_board();
			cout<<"Enter board positon: ";
			cin>>positionString;
			if (positionString == "Q")
				break;

			stringstream ss(positionString);
			ss >> position;
			game.mark_board(position);
		}

		cout<<" \n";
		cout<<"Game Over! Final Board: \n";
		game.display_board();
		cout<<"The winner was: "<<game.get_winner();
		cout<<"\n";

		cout<<"Play Again? (enter y to continue, or any other character to exit.) \n";
		cin>>doAnother;
	} while(doAnother == 'y');

	return 0;
}
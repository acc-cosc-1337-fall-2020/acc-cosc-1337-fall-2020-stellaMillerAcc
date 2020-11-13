#include"tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
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
	TicTacToeManager manager;
	char doAnother;
	bool invalid = false;

	do {
		cout<<"---Welcome to Tic Tac Toe!---\n";

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
			cin>>game;
			cout<<game;
		}

		cout<<" \n";
		cout<<"Game Over! Final Board: \n";
		cout<<game;
		cout<<"The winner was: "<<game.get_winner();
		cout<<"\n";
		manager.save_game(game);

		cout<<"Play Again? (enter y to continue, or any other character to exit.) \n";
		cin>>doAnother;
	} while(doAnother == 'y');

	cout<<manager;
	return 0;
}
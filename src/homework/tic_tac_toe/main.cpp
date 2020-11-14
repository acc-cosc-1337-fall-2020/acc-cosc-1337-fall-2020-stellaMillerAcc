#include"tic_tac_toe.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
#include<sstream>
#include<memory>

using std::cout;
using std::cin;
using std::string;
using std::stringstream;
using std::unique_ptr;

int main() 
{
	unique_ptr<TicTacToe> game;
	TicTacToeManager manager;
	char doAnother;
	bool invalid = false;
	string firstPlayer;

	do {
		cout<<"---Welcome to Tic Tac Toe!---\n";
		
		int size;
		while (size != 3 && size != 4) {
			cout<<"Type 3 to play a 3x3, or 4 to play a 4x4\n";
			cin>>size;
		}

		if (size == 3) {
			game = std::make_unique<TicTacToe3>();
		}
		else {
			game = std::make_unique<TicTacToe4>();
		}

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

		game->start_game(firstPlayer);

		while (!game->game_over()) {
			cin>>*game;
			cout<<*game;
		}

		cout<<" \n";
		cout<<"Game Over! Final Board: \n";
		cout<<*game;
		cout<<"The winner was: "<<game->get_winner();
		cout<<"\n";
		manager.save_game(game);

		cout<<"Play Again? (enter y to continue, or any other character to exit.) \n";
		cin>>doAnother;
	} while(doAnother == 'y');

	cout<<manager;
	return 0;
}
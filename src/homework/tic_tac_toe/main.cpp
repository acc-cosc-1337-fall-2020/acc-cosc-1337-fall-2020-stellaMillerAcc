#include"tic_tac_toe.h"
#include<iostream>

using std::cout;
using std::cin;
using std::string;

int main() 
{
	string firstPlayer;
	TicTacToe game;
	int position;

	cout<<"---Welcome to Tic Tac Toe!---\n";
	cout<<"Enter first player (X or O): ";
	cin>>firstPlayer;

	game.start_game(firstPlayer);

	while (!game.game_over()) {
		game.display_board();
		cout<<"Enter board positon: ";
		cin>>position;
		game.mark_board(position);
	}

	cout<<" \n";
	cout<<"Game Over! Final Board: \n";
	game.display_board();

	return 0;
}
//cpp
#include<string>
#include<iostream>
#include<algorithm>
#include"tic_tac_toe.h"

using std::string;
using std::vector;
using std::find;
using std::fill;
using std::cout;

bool TicTacToe::game_over() {
    return check_board_full();
}

void TicTacToe::start_game(string first_player) {
    if (first_player != "X" && first_player != "O") {
        cout<<"Player may only be 'X' or 'O'";
        return;
    }
    player = first_player;
}

void TicTacToe::mark_board(int position) {
    pegs[position-1] = player;
    set_next_player();
}

string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    cout<<"\n";
    cout<<" ------------ \n";
    cout<<"| "<<pegs[0]<<" | "<<pegs[1]<<" | "<<pegs[2]<<" |\n";
    cout<<" ------------ \n";
    cout<<"| "<<pegs[3]<<" | "<<pegs[4]<<" | "<<pegs[5]<<" |\n";
    cout<<" ------------ \n";
    cout<<"| "<<pegs[6]<<" | "<<pegs[7]<<" | "<<pegs[8]<<" |\n";
    cout<<" ------------ \n";
    cout<<"\n";
}

void TicTacToe::set_next_player() {
    if (player == "X") {
        player = "O";
    }

    else player = "X";
}

bool TicTacToe::check_board_full() {
    return find(pegs.begin(), pegs.end(), " ") == pegs.end();
}

void TicTacToe::clear_board() {
    fill(pegs.begin(), pegs.end(), " ");
}
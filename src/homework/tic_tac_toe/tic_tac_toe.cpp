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
using std::stringstream;

bool TicTacToe::game_over() {

    bool isWinner = check_column_win() || check_row_win() || check_diagonal_win();

    if (isWinner) {
        set_winner();
        return true;
    }

    else if (check_board_full()) {
        winner = "C";
        return true;
    }

    return false;
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

bool TicTacToe::check_column_win() {
    if (pegs[0] != " " && pegs[0] == pegs[3] && pegs[3] == pegs[6])
        return true;

    if (pegs[1] != " " && pegs[1] == pegs[4] && pegs[4] == pegs[7])
        return true;

    if (pegs[2] != " " && pegs[2] == pegs[5] && pegs[5] == pegs[8])
        return true;

    return false;
}

bool TicTacToe::check_row_win() {
    if (pegs[0] != " " && pegs[0] == pegs[1] && pegs[1] == pegs[2])
        return true;

    if (pegs[3] != " " && pegs[3] == pegs[4] && pegs[4] == pegs[5])
        return true;

    if (pegs[6] != " " && pegs[6] == pegs[7] && pegs[7] == pegs[8])
        return true;

    return false;
}

bool TicTacToe::check_diagonal_win() {
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8])
        return true;

    if (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6])
        return true;

    return false;
}

void TicTacToe::set_winner() {
    if (player == "X") {
        winner = "O";
    }

    else winner = "X";
}

string TicTacToe::get_winner() const {
    return winner;
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    cout<<" -------- \n";
    for(std::size_t i=0; i < game.pegs.size(); i += 3)
    {
        cout<<game.pegs[i]<<" | "<<game.pegs[i+1]<<" | "<<game.pegs[i+2]<<"\n";
        cout<<" -------- \n";
    }

    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    std::cout<<"Enter position: ";
    in>>position;
    game.mark_board(position);

    return in;
}
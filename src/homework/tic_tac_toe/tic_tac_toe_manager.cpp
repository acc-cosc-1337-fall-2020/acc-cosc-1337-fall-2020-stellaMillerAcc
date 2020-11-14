//cpp
#include "tic_tac_toe_manager.h"
#include<memory>

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game)
{
    update_winner_account(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::update_winner_account(std::string winner)
{
    if(winner == "X")
    {
        x_wins++;
    }
    else if(winner == "O")
    {
        o_wins++;
    }
    else
    {
        ties++;
    }
}

void TicTacToeManager::get_winner_totals(int& x, int& o, int& t)
{
    x = x_wins;
    o = o_wins;
    t = ties;
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    std::cout<<"\n";
    std::cout<<"O Wins: "<<manager.o_wins<<"  X Wins: "<<manager.x_wins<<"  Ties: "<<manager.ties;
    return out;
}
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<memory>

using std::unique_ptr;
using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Should_game_over_after_9_selections") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(2); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(6); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(7); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == false);
	game->mark_board(9); //X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Should start game with X") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Should start game with O") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("O");

	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Should win by first column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(4); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(7); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by second column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(2); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(5); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(8); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by third column") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(3); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(9); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by first row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(2); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(3); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by second row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(4); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(5); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(6); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by third row") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(7); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(8); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(9); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by first diagonal") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(5); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(9); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by second diagonal") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(7); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(5); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(3); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should_game_over_after_16_selections - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(3); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(7); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(8); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(9); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(11);
	REQUIRE(game->game_over() == false);
	game->mark_board(10); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(12); 
	REQUIRE(game->game_over() == false);
	game->mark_board(14); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(13);
	REQUIRE(game->game_over() == false);
	game->mark_board(16); //X
	REQUIRE(game->game_over() == false);
	game->mark_board(15);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Should start game with X - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Should start game with O - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("O");

	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Should win by first column - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(5); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(9); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(13); //X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by second column - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(2); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(6); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(10); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(9); 
    REQUIRE(game->game_over() == false);
	game->mark_board(14); //X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by third column - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(3); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(7); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(11); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(9); 
	REQUIRE(game->game_over() == false);
	game->mark_board(15); //X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by fourth column - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(4); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(8); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(12); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(9); 
	REQUIRE(game->game_over() == false);
	game->mark_board(16); //X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by first row - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(2); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(3); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(7); 
	REQUIRE(game->game_over() == false);
	game->mark_board(4); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by second row - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(5); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(6); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(7); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(8); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by third row - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(9); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(10); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(11); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(12); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by fourth row - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(13); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(14); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(15); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(16); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by first diagonal - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(6); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(11); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(16); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Should win by second diagonal - 4x4") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(4); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(7); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(10); // X
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(13); // X

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");
}
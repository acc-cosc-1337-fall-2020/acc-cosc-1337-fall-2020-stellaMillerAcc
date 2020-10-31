#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Should_game_over_after_9_selections") {
	TicTacToe game;
	game.start_game("X");
	game.mark_board(2); //X
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(5); //X
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(6); //X
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(7); //X
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(9); //X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Should start game with X") {
	TicTacToe game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Should start game with O") {
	TicTacToe game;
	game.start_game("O");

	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Should win by first column") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X
	game.mark_board(2);
	game.mark_board(4); // X
	game.mark_board(3);
	game.mark_board(7); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}


TEST_CASE("Should win by second column") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(2); // X
	game.mark_board(3);
	game.mark_board(5); // X
	game.mark_board(4);
	game.mark_board(8); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}


TEST_CASE("Should win by third column") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3); // X
	game.mark_board(2);
	game.mark_board(6); // X
	game.mark_board(4);
	game.mark_board(9); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Should win by first row") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X
	game.mark_board(4);
	game.mark_board(2); // X
	game.mark_board(5);
	game.mark_board(3); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Should win by second row") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(4); // X
	game.mark_board(1);
	game.mark_board(5); // X
	game.mark_board(2);
	game.mark_board(6); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Should win by third row") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7); // X
	game.mark_board(1);
	game.mark_board(8); // X
	game.mark_board(2);
	game.mark_board(9); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Should win by first diagonal") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X
	game.mark_board(3);
	game.mark_board(5); // X
	game.mark_board(2);
	game.mark_board(9); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Should win by second diagonal") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7); // X
	game.mark_board(4);
	game.mark_board(5); // X
	game.mark_board(6);
	game.mark_board(3); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
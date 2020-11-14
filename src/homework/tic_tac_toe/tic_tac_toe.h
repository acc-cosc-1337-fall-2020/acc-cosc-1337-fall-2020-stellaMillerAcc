//h
#include<string>
#include<vector>

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


class TicTacToe {
    public:
        TicTacToe(int size): pegs(size*size, " ") {};
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        std::string get_player() const;
        std::string get_winner() const;
        friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
        friend std::istream& operator>>(std::istream& in, TicTacToe& game);
    private:
        std::string player;
        std::string winner;
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
    protected:
        std::vector<std::string> pegs;
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();
};

#endif
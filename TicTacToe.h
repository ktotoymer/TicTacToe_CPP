//
// Created by Mikhail Alexeev on 09.05.2024.
//

#ifndef TICTACTOE_CPP_TICTACTOE_H
#define TICTACTOE_CPP_TICTACTOE_H

enum {
    bsize = 3,
    draw = -1,
    vacant,
    crosses,
    zeroes,
    correct = 4,
    outside,
    occupied,
};

namespace std {

    class TicTacToe {
    public:
        void playGame();

    private:
        char board[bsize][bsize] = {0};
        int player = crosses;
        int res = vacant;

        void isGameOver();

        int check_position(int x, int y);

        void winner();

        void displayBoard();

        void getMove();
    };

} // std

#endif //TICTACTOE_CPP_TICTACTOE_H

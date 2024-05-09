//
// Created by Mikhail Alexeev on 09.05.2024.
//

#include <iostream>
#include "TicTacToe.h"

namespace std {
    void TicTacToe::playGame() {
        while (this->res == 0) {
            displayBoard();
            getMove();
            isGameOver();
        }
        system("clear");
        winner();
    }

    void TicTacToe::getMove() {
        int x, y;
        cin >> x >> y;
        if (this->player == crosses) {
            switch (check_position(x, y)) {
                case correct:
                    board[x - 1][y - 1] = crosses;
                    system("clear");
                    player = zeroes;
                    break;
                case outside:
                    system("clear");
                    printf("Выход за пределы поля\n");
                    break;
                case occupied:
                    system("clear");
                    printf("Нельзя поставить крестик в эту клеточку\n");
                    break;
                default:
                    break;
            }
        } else if (this->player == zeroes) {
            switch (check_position(x, y)) {
                case correct:
                    board[x - 1][y - 1] = zeroes;
                    system("clear");
                    player = crosses;
                case outside:
                    system("clear");
                    printf("Выход за пределы поля\n");
                    break;
                case occupied:
                    system("clear");
                    printf("Нельзя поставить нолик в эту клеточку\n");
                    break;
                default:
                    break;
            }
        }
    }

    void TicTacToe::isGameOver() {
        for (int i = 0; i < bsize; i++) {
            if (board[i][0] == crosses && board[i][1] == crosses && board[i][2] == crosses) {
                this->res = crosses;
            }

            if (board[i][0] == zeroes && board[i][1] == zeroes && board[i][2] == zeroes) {
                this->res = zeroes;
            }

            if (board[0][i] == crosses && board[1][i] == crosses && board[2][i] == crosses) {
                this->res = crosses;
            }

            if (board[0][i] == zeroes && board[1][i] == zeroes && board[2][i] == zeroes) {
                this->res = zeroes;
            }

        }
        if ((board[0][0] == crosses && board[1][1] == crosses && board[2][2] == crosses) ||
            (board[0][2] == crosses && board[1][1] == crosses && board[2][0] == crosses)) {
            this->res = crosses;
        }

        if ((board[0][0] == zeroes && board[1][1] == zeroes && board[2][2] == zeroes) ||
            (board[0][2] == zeroes && board[1][1] == zeroes && board[2][0] == zeroes)) {
            this->res = zeroes;
        }

        bool check = true;
        for (auto &row: board) {
            for (auto &elem: row) {
                if (elem == vacant) check = false;
            }
        }

        if (check) this->res = draw;
        else return;
    }

    void TicTacToe::winner() {
        switch (this->res) {
            case crosses:
                displayBoard();
                cout << "Победили крестики" << endl;
                break;
            case zeroes:
                displayBoard();
                cout << "Победили нолики" << endl;
                break;
            case draw:
                displayBoard();
                cout << "Ничья" << endl;
                break;
            default:
                cout << "Игра не окончена" << endl;
        }
    }

    void TicTacToe::displayBoard() {
        for (auto &row: board) {
            for (auto &elem: row) {
                switch (elem) {
                    case crosses:
                        cout << "X ";
                        break;
                    case zeroes:
                        cout << "O ";
                        break;
                    default:
                        cout << "# ";
                }
            }
            cout << endl;
        }
    }

    int TicTacToe::check_position(int x, int y) {
        if (this->board[x - 1][y - 1] == vacant) return correct;
        else if (x < 1 || x > 3 || y < 1 || y > 3) return outside;
        else return occupied;
    }

} // std
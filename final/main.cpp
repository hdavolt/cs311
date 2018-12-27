/*
    Harel Davolt
    h643b754
    Final Project - Chess Game

    This is the main program for the chess game. This will set up the chess 
    board, players, and pieces. It will then run a chess game in which it asks 
    each player for a move. It will also track captured pieces, which will add 
    to the player score.

    Initialize chess board array and matching player array
    Create piece objects in the proper place in the array
    Loop
        Print chess board to screen
        Ask different players for piece and move
        Move piece or return invalid move
*/

#include <iostream>
#include <string>
#include "chess_errors.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

using namespace std;

int main()
{
    // Board type array (row, column)
    // k = king, q = queen, b = bishop, n = knight, r = rook, p = pawn
    char tbd[8][8] = {0};
    // Player array, to keep track of each player's pieces 
    // (1 = player 1 (top of board), 2 = player 2 (bottomo of board))
    int pbd[8][8] = {0};
    // Id array, to track different pieces of the same type
    int dbd[8][8] = {0};

    // Create chess pieces in proper places
    Rook r11(tbd, pbd, dbd, 0, 0, 1, 1);
    Knight n11(tbd, pbd, dbd, 0, 1, 1, 1);
    Bishop b11(tbd, pbd, dbd, 0, 2, 1, 1);
    Queen q11(tbd, pbd, dbd, 0, 3, 1, 1);
    King k11(tbd, pbd, dbd, 0, 4, 1, 1);
    Bishop b12(tbd, pbd, dbd, 0, 5, 1, 1);
    Knight n12(tbd, pbd, dbd, 0, 6, 1, 1);
    Rook r12(tbd, pbd, dbd, 0, 7, 1, 1);
    Pawn p11(tbd, pbd, dbd, 1, 0, 1, 1);
    Pawn p12(tbd, pbd, dbd, 1, 1, 1, 2);
    Pawn p13(tbd, pbd, dbd, 1, 2, 1, 3);
    Pawn p14(tbd, pbd, dbd, 1, 3, 1, 4);
    Pawn p15(tbd, pbd, dbd, 1, 4, 1, 5);
    Pawn p16(tbd, pbd, dbd, 1, 5, 1, 6);
    Pawn p17(tbd, pbd, dbd, 1, 6, 1, 7);
    Pawn p18(tbd, pbd, dbd, 1, 7, 1, 8);
    Rook r21(tbd, pbd, dbd, 7, 0, 2, 1);
    Knight n21(tbd, pbd, dbd, 7, 1, 2, 1);
    Bishop b21(tbd, pbd, dbd, 7, 2, 2, 1);
    Queen q21(tbd, pbd, dbd, 7, 3, 2, 1);
    King k21(tbd, pbd, dbd, 7, 4, 2, 1);
    Bishop b22(tbd, pbd, dbd, 7, 5, 2, 1);
    Knight n22(tbd, pbd, dbd, 7, 6, 2, 1);
    Rook r22(tbd, pbd, dbd, 7, 7, 2, 1);
    Pawn p21(tbd, pbd, dbd, 6, 0, 2, 1);
    Pawn p22(tbd, pbd, dbd, 6, 1, 2, 2);
    Pawn p23(tbd, pbd, dbd, 6, 2, 2, 3);
    Pawn p24(tbd, pbd, dbd, 6, 3, 2, 4);
    Pawn p25(tbd, pbd, dbd, 6, 4, 2, 5);
    Pawn p26(tbd, pbd, dbd, 6, 5, 2, 6);
    Pawn p27(tbd, pbd, dbd, 6, 6, 2, 7);
    Pawn p28(tbd, pbd, dbd, 6, 7, 2, 8);

    bool game = 1;
    int player = 1;
    int p1_score = 0;
    int p2_score = 0;
    cout << "Welcome to a game with some chess rules!" << endl;
    // No but seriously, I couldn't get all the rules in to make it a real game
    do
    {
        // Column Numbers
        cout << "    ";
        for (int i = 0; i < 8; i++)
            cout << i << "   ";
        cout << endl;
        // Top line
        cout << "  ";
        for (int i = 0; i < 33; i++)
            cout << "-";
        cout << endl;
        // Board with Pieces and row numbers
        for (int i = 0; i < 8; i++)
        {
            cout << i << " ";
            for (int j = 0; j < 8; j++)
            {
                if (pbd[i][j] != 0)
                    cout << "|" << pbd[i][j] << tbd[i][j] << dbd[i][j];
                else
                    cout << "|   ";
            }
            cout << "|" << endl;
            // lines under rows
            cout << "  ";
            for (int i = 0; i < 33; i++)
                cout << "-";
            cout << endl;
        }

        // Ask player for move or quit
        cout << "Player " << player << " make your move:" << endl;
        if (player == 1)
            cout << "Your score is: " << p1_score << endl;
        else if (player == 2)
            cout << "Your score is: " << p2_score << endl;

        cout << "Enter piece or \"quit\"(Ex: \"1p1\"): ";
        string source;
        getline(cin, source);

        int i_row, i_col;
        if (source != "quit")
        {
            cout << "Enter move (row column) (Ex: \"3 0\"): ";
            cin >> i_row;
            cin.ignore();
            cin >> i_col;
            cin.ignore();
        }
        
        try
        {
            if (player == 1 && game == 1)
            {
                try
                {
                    if (source == "1r1")
                    {
                        r11.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1n1")
                    {
                        n11.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1b1")
                    {
                        b11.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1q1")
                    {
                        q11.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1k1")
                    {
                        k11.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1b2")
                    {
                        b12.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1n2")
                    {
                        n12.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1r2")
                    {
                        r12.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p1")
                    {
                        p11.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p2")
                    {
                        p12.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p3")
                    {
                        p13.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p4")
                    {
                        p14.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p5")
                    {
                        p15.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p6")
                    {
                        p16.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p7")
                    {
                        p17.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "1p8")
                    {
                        p18.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "quit")
                    {
                        game = 0;
                    }
                    else
                    {
                        throw Invalid_move();
                    }
                }
                catch(Piece_captured &c)
                {
                    cerr << "Piece captured!" << endl;
                    p1_score += c.prev;
                    if (c.prev == 20)
                    {
                        cerr << "Game over. Player 2 wins!" << endl;
                        game = 0;
                    }
                }
                catch(King_check &k)
                {
                    cerr << "Player " << k.plr << " your king is in check!" << endl;
                }
            }
            if (player == 2 && game == 1)
            {
                try
                {
                    if (source == "2r1")
                    {
                        r21.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2n1")
                    {
                        n21.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2b1")
                    {
                        b21.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2q1")
                    {
                        q21.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2k1")
                    {
                        k21.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2b2")
                    {
                        b22.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2n2")
                    {
                        n22.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2r2")
                    {
                        r22.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p1")
                    {
                        p21.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p2")
                    {
                        p22.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p3")
                    {
                        p23.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p4")
                    {
                        p24.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p5")
                    {
                        p25.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p6")
                    {
                        p26.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p7")
                    {
                        p27.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "2p8")
                    {
                        p28.move(tbd, pbd, dbd, i_row, i_col);
                    }
                    else if (source == "quit")
                    {
                        game = 0;
                    }
                    else
                    {
                        throw Invalid_move();
                    }
                }
                catch(Piece_captured &c)
                {
                    cerr << "Piece captured!" << endl;
                    p2_score += c.prev;
                    if (c.prev == 20)
                    {
                        cerr << "Game over. Player 2 wins!" << endl;
                        game = 0;
                    }
                }
                catch(King_check &k)
                {
                    cerr << "Player " << k.plr << " your king is in check!" << endl;
                }
            }
            if (player == 1)
                player = 2;
            else
                player = 1;
        }
        catch(Invalid_move &i)
        {
            cerr << i.what() << endl;
        }
    } while (game == 1);

    cout << "Player 1 score: " << p1_score << endl;
    cout << "Player 2 score: " << p2_score << endl;
    
    return 0;
}
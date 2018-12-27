/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    These are the functions for the Pawn piece.
*/

#include "pawn.hpp"
#include "piece.hpp"
#include "chess_errors.hpp"
//#define DEBUG
#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

// Blank default constructor
Pawn::Pawn() : Piece()
{
}

// Constructor that calls Piece and sets the value, type, and moves
Pawn::Pawn(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id) : Piece::Piece(t, p, d, row, col, pl, id)
{    
    type = 'p';
    t[row][col] = type;
    #ifdef DEBUG
    cout << "Location" << endl;
    cout << in_row << " " << in_col << endl;
    #endif
}

// Redefined move for Pawn
void Pawn::move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col)
{
    bool moved = 0;
    calc_avail(t, p, row, col);
    for (int i = 0; i < MOVES; i++)
    {
        if ((row == avail[i][0] && col == avail[i][1]) && !(row == in_row && col == in_col))
        {
            if (t[row][col] != 0)
            {
                switch (t[row][col])
                {
                    case 'p':
                        prev_val = 1;
                        break;
                    case 'r':
                        prev_val = 5;
                        break;
                    case 'n':
                        prev_val = 3;
                        break;
                    case 'b':
                        prev_val = 3;
                        break;
                    case 'q':
                        prev_val = 10;
                        break;
                    case 'k':
                        prev_val = 20;
                        break;
                    default:
                        break;
                }
            }
            t[row][col] = type;
            p[row][col] = player;
            d[row][col] = id;
            t[in_row][in_col] = 0;
            p[in_row][in_col] = 0;
            d[in_row][in_col] = 0;
            in_row = row;
            in_col = col;
            ++counter;
            moved = 1;
        }
    }
    #ifdef DEBUG
    cout << "Location of piece" << endl;
    cout << in_row << " " << in_col << endl;
    #endif
    if (moved == 0)
        throw Invalid_move();
    if (prev_val > 0)
        throw Piece_captured(prev_val);
    // Check if king ca be captured
    calc_avail(t, p, row, col);
    for (int i = 0; i < MOVES; i++)
    {
        int t_row = avail[i][0];
        int t_col = avail[i][1];
        if (t[t_row][t_col] == 'k' && p[t_row][t_col] != player && p[t_row][t_col != 0])
            throw King_check(player);
    }
}

void Pawn::calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col)
{
    // Get all relative moves allowed
    // Since a Pawn's moves are player dependent, two sets of available moves 
    // are needed.
    if (player == 1)
    {
        // On first move, a pawn can move one or two spaces
        if (counter == 0)
        {
            //cout << "First move" << endl;
            rule[0][0] = 1; 
            rule[1][0] = 2;
            #ifdef DEBUG
            cout << "Relative moves are " << endl;
            cout << rule[0][0] << " " << rule[0][1] << endl;
            cout << rule[1][0] << " " << rule[1][1] << endl;
            #endif
        }
        // Otherwise, a pawn can only move one space forward, or diagonal to capture
        else
        {
            rule[0][0] = 1;
            rule[0][1] = -1;
            rule[1][0] = 1;
            rule[1][1] = 0;
            rule[2][0] = 1;
            rule[2][1] = 1;
            #ifdef DEBUG
            cout << "Relative moves are " << endl;
            cout << rule[0][0] << " " << rule[0][1] << endl;
            cout << rule[1][0] << " " << rule[1][1] << endl;
            cout << rule[2][0] << " " << rule[2][1] << endl;
            #endif
        }
    }
    if (player == 2)
    {
        // On first move, a pawn can move one or two spaces
        if (counter == 0)
        {
            rule[0][0] = -1; 
            rule[1][0] = -2;
            /*
            cout << "Relative moves are " << endl;
            cout << rule[0][0] << " " << rule[0][1] << endl;
            cout << rule[1][0] << " " << rule[1][1] << endl;
            */
        }
        // Otherwise, a pawn can only move one space forward, or diagonal to 
        // capture
        else
        {
            rule[0][0] = -1;
            rule[0][1] = -1;
            rule[1][0] = -1;
            rule[1][1] = 0;
            rule[2][0] = -1;
            rule[2][1] = 1;
            #ifdef DEBUG
            cout << "Relative moves are " << endl;
            cout << rule[0][0] << " " << rule[0][1] << endl;
            cout << rule[1][0] << " " << rule[1][1] << endl;
            cout << rule[2][0] << " " << rule[2][1] << endl;
            #endif
        }
    }

    // Translate relative rules into actual moves
    for (int i = 0; i < MOVES; i++)
    {
        avail[i][0] = in_row + rule[i][0];
        avail[i][1] = in_col + rule[i][1];
    }
    #ifdef DEBUG
    cout << "Actual moves are " << endl;
    for (int i = 0; i < MOVES; i++)
    {
        cout << avail[i][0] << " " << avail[i][1] << endl;
    }
    #endif

    // Trim out of bounds moves
    for (int i = 0; i < MOVES; i++)
    {
        if (avail[i][0] < 0 || avail[i][0] > 7)
            avail[i][0] = in_row;
        if (avail[i][1] < 0 || avail[i][1] > 7)
            avail[i][1] = in_col;
    }
    #ifdef DEBUG
    cout << "In bounds moves are " << endl;
    for (int i = 0; i < MOVES; i++)
    {
        cout << avail[i][0] << " " << avail[i][1] << endl;
    }
    #endif
    
    // Catch blocking moves. These won't happen on first move.
    if (counter != 0)
    {
        // 1. Blocked by piece in front
        if (player == 1 && t[in_row + 1][in_col] != 0)
        {
            // Forward move was second available move
            avail[1][0] = in_row;
            avail[1][1] = in_col;
        }
        if (player == 2 && t[in_row + 1][in_col] != 0)
        {
            // Forward move was second available move
            avail[1][0] = in_row;
            avail[1][1] = in_col;
        }
        #ifdef DEBUG
        cout << "Blocking moves 1 are " << endl;
        for (int i = 0; i < MOVES; i++)
        {
        cout << avail[i][0] << " " << avail[i][1] << endl;
        }
        #endif

        // 2. Can't move sideways to empty space
        if (player == 1 && t[in_row + 1][in_col - 1] == 0)
        {
            avail[0][0] = in_row;
            avail[0][1] = in_col;
        }
        if (player == 1 && t[in_row + 1][in_col + 1] == 0)
        {
            avail[2][0] = in_row;
            avail[2][1] = in_col;
        }
        if (player == 2 && t[in_row - 1][in_col - 1] == 0)
        {
            avail[0][0] = in_row;
            avail[0][1] = in_col;
        }
        if (player == 2 && t[in_row - 1][in_col + 1] == 0)
        {
            avail[2][0] = in_row;
            avail[2][1] = in_col;
        }
        #ifdef DEBUG
        cout << "Blocking moves 2 are " << endl;
        for (int i = 0; i < MOVES; i++)
        {
        cout << avail[i][0] << " " << avail[i][1] << endl;
        }
        #endif

        // 3. Can't move sideways over own piece
        if (player == 1)
        {
            if (p[in_row  + 1][in_col - 1] == player)
            {
                avail[0][0] = in_row;
                avail[0][1] = in_col;
            }
            if (p[in_row + 1][in_col + 1] == player)
            {
                avail[2][0] = in_row;
                avail[2][1] = in_col;
            }
        }
        if (player == 2)
        {
            if (p[in_row  - 1][in_col - 1] == player)
            {
                avail[0][0] = in_row;
                avail[0][1] = in_col;
            }
            if (p[in_row - 1][in_col + 1] == player)
            {
                avail[2][0] = in_row;
                avail[2][1] = in_col;
            }
        }
        #ifdef DEBUG
        cout << "Blocking moves 3 are " << endl;
        for (int i = 0; i < MOVES; i++)
        {
        cout << avail[i][0] << " " << avail[i][1] << endl;
        }
        #endif
    }
}
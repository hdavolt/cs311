/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    These are the functions for the Rook piece.
*/

#include "rook.hpp"
#include "piece.hpp"
#include "chess_errors.hpp"
//#define DEBUG
#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

// Blank default constructor
Rook::Rook() : Piece()
{
}

// Constructor that calls Piece and sets the value, type, and moves
Rook::Rook(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id) : Piece::Piece(t, p, d, row, col, pl, id)
{    
    type = 'r';
    t[row][col] = type;
    #ifdef DEBUG
    cout << "Location" << endl;
    cout << in_row << " " << in_col << endl;
    #endif
}

// Movement function
void Rook::move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col)
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

void Rook::calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col)
{
    // Get all relative moves allowed
    // Rook movements are independent of player
    rule[0][1] = 1;
    rule[1][1] = 2;
    rule[2][1] = 3;
    rule[3][1] = 4;
    rule[4][1] = 5;
    rule[5][1] = 6;
    rule[6][1] = 7;
    rule[7][1] = -1;
    rule[8][1] = -2;
    rule[9][1] = -3;
    rule[10][1] = -4;
    rule[11][1] = -5;
    rule[12][1] = -6;
    rule[13][1] = -7;
    rule[14][0] = 1;
    rule[15][0] = 2;
    rule[16][0] = 3;
    rule[17][0] = 4;
    rule[18][0] = 5;
    rule[19][0] = 6;
    rule[20][0] = 7;
    rule[21][0] = -1;
    rule[22][0] = -2;
    rule[23][0] = -3;
    rule[24][0] = -4;
    rule[25][0] = -5;
    rule[26][0] = -6;
    rule[27][0] = -7;
    #ifdef DEBUG
    cout << "Relative moves are" << endl;
    for (int i = 0; i < MOVES; i++)
    {
        cout << rule[i][0] << " " << rule[i][1] << endl;
    }
    #endif
    
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

    // Blocking condition
    // Can't move past another piece of same player. Other player's pieces 
    // can be captured.
    
    // Create an array of blocks that match the available moves.
    int block[MOVES][2] = {0};
    for (int i = 0; i < MOVES; i++)
    {
        int test_row = avail[i][0];
        int test_col = avail[i][1];
        if (!(test_row == in_row && test_col == in_col))
        {
            if (p[test_row][test_col] != 0)
            {
                block[i][0] = test_row;
                block[i][1] = test_col;
                #ifdef DEBUG
                cout << "Blocking value ";
                cout << block[i][0] << " " << block[i][1] << endl;
                #endif
            }
            else
            {
                block[i][0] = in_row;
                block[i][1] = in_col;
            }    
        }
        else
        {
            block[i][0] = in_row;
            block[i][1] = in_col;
        }
    }
    #ifdef DEBUG
    cout << "Blocking spaces are " << endl;
    for (int i = 0; i < MOVES; i++)
    {
        cout << block[i][0] << " " << block[i][1] << endl;
    }
    #endif
    

    // Now find min/max values
    int bl_row_min = 7;
    int bl_row_max = 0;
    int bl_col_min = 7;
    int bl_col_max = 0;
    bool bl_row_min_found = 0;
    bool bl_row_max_found = 0;
    bool bl_col_min_found = 0;
    bool bl_col_max_found = 0;
    for (int i = 0; i < MOVES; i++)
    {
        if (!(block[i][0] == in_row && block[i][1] == in_col))
        {
            if (block[i][0] <= bl_row_min && block[i][0] < in_row && block[i][1] == in_col)
            {
                bl_row_min = block[i][0];
                bl_row_min_found = 1;
            }
            else if (block[i][0] >= bl_row_max && block[i][0] > in_row && block[i][1] == in_col)
            {
                bl_row_max = block[i][0];
                bl_row_max_found = 1;
            }
            if (block[i][1] <= bl_col_min && block[i][1] < in_col && block[i][1] == in_row)
            {
                bl_col_min = block[i][1];
                bl_col_min_found = 1;
            }
            else if (block[i][1] >= bl_col_max && block[i][1] > in_col && block[i][1] == in_row)
            {
                bl_col_max = block[i][1];
                bl_col_max_found = 1;
            }
        }
    }
    if (bl_row_min_found == 0)
        bl_row_min = 0;
    if (bl_row_max_found == 0)
        bl_row_max = 7;
    if (bl_col_min_found == 0)
        bl_col_min = 0;
    if (bl_col_max_found == 0)
        bl_col_max = 7;
    #ifdef DEBUG
    cout << "Min row value" << endl;
    cout << bl_row_min << endl;
    cout << "Max row value" << endl;
    cout << bl_row_max << endl;
    cout << "Min col value" << endl;
    cout << bl_col_min << endl;
    cout << "Max col value" << endl;
    cout << bl_col_max << endl;
    #endif
    
    // Filter available array based on min/max
    for (int i = 0; i < MOVES; i++)
    {
        int t_row = avail[i][0];
        int t_col = avail[i][1];
        if (avail[i][0] <= bl_row_min && avail[i][1] == in_col && bl_row_min_found == 1)
        {
            #ifdef DEBUG
            cout << "bl_row_min" << avail[i][0] << " " << avail[i][1] << endl;
            #endif
            if (p[t_row][t_col] == player)
                avail[i][0] = bl_row_min + 1;
            else if (p[t_row][t_col] != player && p[t_row][t_col] != 0)
                avail[i][0] = bl_row_min;
            else
                avail[i][0] = in_row;
        }
        else if (avail[i][0] >= bl_row_max && avail[i][1] == in_col && bl_row_max_found == 1)
        {
            #ifdef DEBUG
            cout << "bl_row_max" << avail[i][0] << " " << avail[i][1] << endl;
            #endif
            if (p[t_row][t_col] == player)
                avail[i][0] = bl_row_max - 1;
            else if (p[t_row][t_col] != player && p[t_row][t_col] != 0)
                avail[i][0] = bl_row_max;
            else
                avail[i][0] = in_row;
        }
        if (avail[i][1] <= bl_col_min && avail[i][1] == in_row && bl_col_min_found == 1)
        {
            #ifdef DEBUG
            cout << "bl_col_min" << avail[i][0] << " " << avail[i][1] << endl;
            #endif
            if (p[t_row][t_col] == player)
                avail[i][1] = bl_col_min + 1;
            else if (p[t_row][t_col] != player && p[t_row][t_col] != 0)
                avail[i][1] = bl_col_min;
            else
                avail[i][1] = in_col;     
        }
        else if (avail[i][1] >= bl_col_max && avail[i][1] == in_row && bl_col_max_found == 1)
        {
            #ifdef DEBUG
            cout << "bl_col_max" << avail[i][0] << " " << avail[i][1] << endl;
            #endif
            if (p[t_row][t_col] == player)
                avail[i][1] = bl_col_max - 1;
            else if (p[t_row][t_col] != player && p[t_row][t_col] != 0)
                avail[i][1] = bl_col_max;
            else
                avail[i][1] = in_col;
        }
    }
    
    #ifdef DEBUG
    cout << "Blocking moves are " << endl;
    for (int i = 0; i < MOVES; i++)
    {
        cout << avail[i][0] << " " << avail[i][1] << endl;
    }
    #endif
}
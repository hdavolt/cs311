/*
    Harel Davolt
    h643b754
    Final Project - Chess Game

    These are the functions for the piece class.
*/

#include "piece.hpp"

// Default Constructor shouldn't get called
Piece::Piece() : player(0), in_row(0), in_col(0)
{
}

// Main constructor, used to place pieces on the board
Piece::Piece(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id) : player(pl), in_row(row), in_col(col), id(id)
{
    p[row][col] = player;
    d[row][col] = id;
}

void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col)
{

}

void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col)
{
    
}
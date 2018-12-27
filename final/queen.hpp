/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    This is the Queen piece. This extends the base piece class with movement 
    rules for queens. A queen can move any amount diagonally, horizontally, or 
    vertically until it captures another piece or is stopped by its own piece.
*/

#include "piece.hpp"

#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

class Queen : public Piece
{
    public:
        Queen();
        Queen(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id); 
        void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col);
        void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col);
    private:
        const int MOVES = 56;
        int rule[56][2] = {0};
        int avail[56][2] = {0};
};

#endif
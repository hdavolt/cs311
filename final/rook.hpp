/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    This is the Rook piece. This extends the base piece class with movement 
    rules for rooks. A rook can move any amount vertically or horizontally 
    until it captures another piece or is stopped by its own piece.
*/

#include "piece.hpp"

#ifndef __ROOK_HPP__
#define __ROOK_HPP__

class Rook : public Piece
{
    public:
        Rook();
        Rook(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id); 
        void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col);
        void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col);
    private:
        const int MOVES = 28;
        int rule[28][2] = {0};
        int avail[28][2] = {0};
};

#endif
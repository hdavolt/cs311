/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    This is the Bishop piece. This extends the base piece class with movement 
    rules for bishops. A bishop can move any amount diagonally until it 
    captures another piece or is stopped by its own piece.
*/

#include "piece.hpp"

#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

class Bishop : public Piece
{
    public:
        Bishop();
        Bishop(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id); 
        void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col);
        void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col);
    private:
        const int MOVES = 28;
        int rule[28][2] = {0};
        int avail[28][2] = {0};
};

#endif
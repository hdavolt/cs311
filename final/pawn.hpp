/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    This is the Pawn piece. This extends the base piece class with movement 
    rules for pawns. On the first move, a pawn can move two spaces forward; on 
    subsequent moves, a pawn can only move one space forward, unless capturing 
    another piece, in which case a pawn can move diagonally forward by one 
    space.

    A pawn which reaches the opposite end of the board becomes a queen. This 
    will be accomodated in a special case in the move function.
*/

#include "piece.hpp"

#ifndef __PAWN_HPP__
#define __PAWN_HPP__

class Pawn : public Piece
{
    public:
        Pawn();
        Pawn(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id); 
        void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col);
        void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col);
    private:
        const int MOVES = 3;
        int rule[3][2] = {0};
        int avail[3][2] = {0};
};

#endif
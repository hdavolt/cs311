/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    This is the King piece. This extends the base piece class with movement 
    rules for kings. A king can move one space in any direction unless blocked 
    by another piece of the same player. Also, for purposes of checking for a 
    "check" condition, the King's location is set to a static Piece variable.
*/

#include "piece.hpp"

#ifndef __KING_HPP__
#define __KING_HPP__

class King : public Piece
{
    public:
        King();
        King(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id); 
        void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col);
        void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col);
    private:
        const int MOVES = 8;
        int rule[8][2] = {0};
        int avail[8][2] = {0};
};

#endif
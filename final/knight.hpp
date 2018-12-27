/*
    Harel Davolt
    h643b754
    Final Program - Chess Game

    This is the Knight piece. This extends the base piece class with movement 
    rules for knights. A knight has special movements and is only blocked by 
    another piece of the same player.
*/

#include "piece.hpp"

#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

class Knight : public Piece
{
    public:
        Knight();
        Knight(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id); 
        void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col);
        void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col);
    private:
        const int MOVES = 8;
        int rule[8][2] = {0};
        int avail[8][2] = {0};
};

#endif
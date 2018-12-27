/*
    Harel Davolt
    h643b754
    Final Project - Chess Game

    This is the piece base class. This will include functions that are relevent 
    to all the chess pieces. This class is virtual as all pieces need to have a 
    type. The constructor will take a reference to a location on the pboard and 
    tboard arrays. The class will have a function to move a piece, which will 
    include a function to find all available moves, as well as a capture 
    function to replace an existing piece.

    Data:
        Type (char)
        Value (int)
        Player (int)
        Move counter (int)
        Location Row & Column (int)
        Piece ID (Int)
        King Location (Int Array)
    Functions:
        Constructor (Takes location)
        Move Piece (Takes original and future location)
        Find available moves (Takes location)
*/

#ifndef __PIECE_HPP__
#define __PIECE_HPP__

class Piece
{
    public:
        Piece();
        Piece(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col, int pl, int id); 
        // Every piece has different available moves based on rules; pieces 
        // that can be captured will be returned as availabe; the actual 
        // capturing will be done by main()
        void move(char (&t)[8][8], int (&p)[8][8], int (&d)[8][8], int row, int col); 
        void calc_avail(char (&t)[8][8], int (&p)[8][8], int row, int col);
        int get_prev_val() { return prev_val; };
    protected:
        char type;
        int player;
        int counter = 0;
        int in_row, in_col;
        int id;
        static int k_loc[2][2];
        int prev_val = 0;
};

#endif
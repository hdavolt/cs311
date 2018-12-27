/*
    Harel Davolt
    h643b754
    Final Project - Chess Game

    This is the error handling for the chess game. This will catch invalid 
    moves and captured pieces.
*/

class Invalid_move
{
    public:
        const char * what() const throw()
        {
            return "Invalid Move!";
        }
};

struct Piece_captured
{
    int prev;
    Piece_captured(int pv)
    {
        prev = pv;
    }
};

struct King_check
{
    int plr;
    King_check(int pl)
    {
        if (pl == 1)
            plr = 2;
        else
            plr = 1;
    }
};
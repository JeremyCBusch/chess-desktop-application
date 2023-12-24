

/***********************************************************************
 * Source File:
 *    Rook : Represents a Rook that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of Rook
 ************************************************************************/


#include "rook.h"
#include "uiDraw.h"


using namespace std;
char Rook::getLetter()
{
   return isWhite() ? 'r' : 'R';
}

void Rook::display(ogstream& gout)
{
   if (!isDead)
      gout.drawRook(position.getLocation(), !fWhite);
}


unordered_map<int, Move>* Rook::getPossibleMoves(Position posFrom, Board* board, int currentMove)
{
    unordered_map<int, Move>* moves = new unordered_map<int, Move>();

    if ((currentMove % 2 == 1 && isWhite() == false) || currentMove % 2 == 0 && isWhite() == true) {
        return moves;
    }

    int r;
    int c;

    // MOVES THAT ROOK CAN TAKE
    Delta delta[] = {
                {0,1},
        {-1,0},        {1,0},
                {0,-1}
    };

    moves = getPossibleLinearMoves(delta, posFrom, board);
    return moves;
}

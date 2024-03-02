/***********************************************************************
 * Source File:
 *    Queen : Represents a Queen that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of Queen
 ************************************************************************/




#include "queen.h"



char Queen::getLetter()
{
   return isWhite() ? 'q' : 'Q';
}

void Queen::display(ogstream& gout)
{
   if (!isDead)
      gout.drawQueen(position.getLocation(), !fWhite);
}


unordered_map<int, Move> Queen::getPossibleMoves(Position posFrom, Board* board, int currentMove)
{
    unordered_map<int, Move> moves = unordered_map<int, Move>();

   if ((currentMove % 2 == 1 && isWhite() == false) || currentMove % 2 == 0 && isWhite() == true) {
      return moves;
   }

   int r;
   int c;

   Delta  delta[] =
   {
      {-1,  1}, {0,  1}, {1,  1},
      {-1,  0},          {1,  0},
      {-1, -1}, {0, -1}, {1, -1}
   };

   moves = getPossibleLinearMoves(delta, posFrom, board);
   return moves;
}

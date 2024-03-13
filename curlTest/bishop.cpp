/***********************************************************************
 * Source File:
 *    Bishop : Represents a Bishop that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of Bishop
 ************************************************************************/



#include "bishop.h"


char Bishop::getLetter()
{
   return isWhite() ? 'b' : 'B';
}

void Bishop::display(ogstream& gout)
{
   if (!isDead)
      gout.drawBishop(position.getLocation(), !fWhite);
}


unordered_map<int, Move> Bishop::getPossibleMoves(Position posFrom, Board* board, int currentMove, bool isPlayerWhite)
{
    unordered_map<int, Move> moves = unordered_map<int, Move>();
   if (!isPlayersTurn(isPlayerWhite, currentMove) || isPlayerWhite != isWhite())
      return moves;
   

   Delta delta[] =
   {
          {-1,  1}, {1,  1},
          {-1, -1}, {1, -1}
   };

   moves = getPossibleLinearMoves(delta, posFrom, board);
   return moves;
}

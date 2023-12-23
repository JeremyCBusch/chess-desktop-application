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


unordered_map<int, Move>* Queen::getPossibleMoves(Position posFrom, Board* board, int currentMove)
{
    unordered_map<int, Move>* moves = new unordered_map<int, Move>();

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

   for (int i = 0; i < 8; i++)
   {
      r = getPosition().getRow() + delta[i].dRow;
      c = getPosition().getCol() + delta[i].dCol;

      while (r >= 0 && r < 8 && c >= 0 && c < 8 && board->getPiece(r * 8 + c)->getLetter() == '_')
      {
          moves->insert({ r * 8 + c,Move(posFrom, Position(r * 8 + c)) });
         r += delta[i].dRow;
         c += delta[i].dCol;
      }


      // Black Knight
      if (!isWhite() && board->isNotBlack(r, c))
          moves->insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });


      // White Knight
      if (isWhite() && board->isNotWhite(r, c))
          moves->insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });
   }
   return moves;
}

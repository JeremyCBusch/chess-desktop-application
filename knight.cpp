/***********************************************************************
 * Source File:
 *    Knight : Represents a Knight that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of Knight
 ************************************************************************/



#include "knight.h"

char Knight::getLetter()
{
   return isWhite() ? 'n' : 'N';
}

void Knight::display(ogstream& gout)
{
   if (!isDead)
      gout.drawKnight(position.getLocation(), !fWhite);
}


unordered_map<int, Move>* Knight::getPossibleMoves(Position posFrom, Board* board, int currentMove)
{
    unordered_map<int, Move>* moves = new unordered_map<int, Move>();

   if ((currentMove % 2 == 1 && isWhite() == false) || currentMove % 2 == 0 && isWhite() == true) {
      return moves;
   }

   int r;
   int c;

   Delta delta[] =
   {
                 {-1,  2}, { 1,  2},
        {-2,  1},                    { 2,  1},
        {-2, -1},                    { 2, -1},
                 {-1, -2}, { 1, -2}
   };

   for (int i = 0; i < 8; i++)
   {

      r = getPosition().getRow() + delta[i].dRow;
      c = getPosition().getCol() + delta[i].dCol;

      // Black Knight
      if (!isWhite() && board->isNotBlack(r, c))
          moves->insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });

      // White Knight
      if (isWhite() && board->isNotWhite(r, c))
          moves->insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });

   }
   return moves;
}

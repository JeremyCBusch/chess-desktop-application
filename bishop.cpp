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


unordered_map<int, Move>* Bishop::getPossibleMoves(Position posFrom, Board* Board, int currentMove)
{
    unordered_map<int, Move>* moves = new unordered_map<int, Move>();
   if ((currentMove % 2 == 1 && isWhite() == false) || currentMove % 2 == 0 && isWhite() == true) {
      return moves;
   }

   //int r;
   //int c;

   //Delta delta[] =
   //{
   //       {-1,  1}, {1,  1},
   //       {-1, -1}, {1, -1}
   //};

   //for (int i = 0; i < 4; i++)
   //{
   //   r = getPosition().getRow() + delta[i].dRow;
   //   c = getPosition().getCol() + delta[i].dCol;

   //   while (r >= 0 && r < 8 && c >= 0 && c < 8 && Board.getPiece(r * 8 + c)->getLetter() == '_')
   //   {
   //      moves->insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });
   //      r += delta[i].dRow;
   //      c += delta[i].dCol;
   //   }

   //   //// Black Knight
   //   //if (!isWhite() && Board.isNotBlack(r, c))
   //   //    moves->insert(Move(posFrom, Position(r * 8 + c)));
   //   //   moves->insert(r * 8 + c);

   //   //// White Knight
   //   //if (isWhite() && Board.isNotWhite(r, c))
   //   //   moves->insert(r * 8 + c);

   //}
   return moves;
}

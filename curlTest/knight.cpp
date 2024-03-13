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


unordered_map<int, Move> Knight::getPossibleMoves(Position posFrom, Board* board, int currentMove, bool isPlayerWhite)
{
    unordered_map<int, Move> moves = unordered_map<int, Move>();

   if (!isPlayersTurn(isPlayerWhite, currentMove) || isPlayerWhite != isWhite()) {
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
      
      if (r * 8 + c > 0 && r * 8 + c < 64 && c < 8 && c >= 0) {

          if (board->getPiece(r, c)->getLetter() == '_')
              moves.insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });

          else if (!board->isSameColor(this, board->getPiece(r, c))) {
              Move move = Move(posFrom, Position(r * 8 + c));
              move.setStandardCapture(true);
              moves.insert({ r * 8 + c, move });
          }
      }


   }
   return moves;
}

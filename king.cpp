/***********************************************************************
 * Source File:
 *    King : Represents a King that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of King
 ************************************************************************/



#include "king.h"

char    King::getLetter()
{
   return isWhite() ? 'k' : 'K';
}

void King::display(ogstream& gout)
{
   if (!isDead)
      gout.drawKing(position.getLocation(), !fWhite);
}


unordered_map<int, Move>* King::getPossibleMoves(Position posFrom, Board* board, int currentMove)
{
    unordered_map<int, Move>* moves = new unordered_map<int, Move>();
   
   if ((currentMove % 2 == 1 && isWhite() == false) || currentMove % 2 == 0 && isWhite() == true) {
      return moves;
   }

   int r;
   int c;

   int space_1;
   int space_2;
   int space_3;
   int space_4;

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

      // Black King
      if (r * 8 + c > 0 && r * 8 + c < 64) {
          if (!board->isSameColor(this, board->getPiece(r * 8 + c)) || board->getPiece(r * 8 + c)->getLetter() == '_')
              moves->insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });
      }
       
         
   }
   int row = getPosition().getRow();
   int col = getPosition().getCol();

   
   // Black King Check Castling 
   if (!isWhite() && row == 0)
   {
      // King Side Castle

      space_1 = getPosition().getCol() + 1;
      space_2 = getPosition().getCol() + 2;
      space_3 = getPosition().getCol() + 3;

      if (
          board->getPiece(row, space_1)->getLetter() == '_' &&
          board->getPiece(row, space_2)->getLetter() == '_' &&
          board->getPiece(row, space_3)->getLetter() == 'R' &&
            
          board->getPiece(row, col)->getNMoves() == 0 &&
          board->getPiece(row, space_3)->getNMoves() == 0
         )
      {
          moves->insert({ r * 8 + space_2, Move(posFrom, Position(r * 8 + space_2),false, true, false, false, false)});
      }

      // Queen Side Castle
      space_1 = getPosition().getCol() - 1;
      space_2 = getPosition().getCol() - 2;
      space_3 = getPosition().getCol() - 3;
      space_4 = getPosition().getCol() - 4;

      if (
         board->getPiece(row, space_1)->getLetter() == '_' &&
         board->getPiece(row, space_2)->getLetter() == '_' &&
         board->getPiece(row, space_3)->getLetter() == '_' &&
         board->getPiece(row, space_4)->getLetter() == 'R' &&
         
         board->getPiece(row, col)->getNMoves() == 0 &&
         board->getPiece(row, space_4)->getNMoves() == 0
         )
      {
          moves->insert({ r * 8 + space_3, Move(posFrom, Position(r * 8 + space_3), false, false, true, false, false) });
      }
   }
   
   // White King Check Castling 
   if (isWhite() && row == 7)
   {
      space_1 = getPosition().getCol() + 1;
      space_2 = getPosition().getCol() + 2;
      space_3 = getPosition().getCol() + 3;
      if (
         board->getPiece(row, space_1)->getLetter() == '_' &&
         board->getPiece(row, space_2)->getLetter() == '_' &&
         board->getPiece(row, space_3)->getLetter() == 'r' &&
         
         board->getPiece(row, col)->getNMoves() == 0 &&
         board->getPiece(row, space_3)->getNMoves() == 0
         )
      {
          moves->insert({ r * 8 + space_2, Move(posFrom, Position(r * 8 + space_2), false, true, false, false, false) });
      }

      // Queen Side Castle
      space_1 = getPosition().getCol() - 1;
      space_2 = getPosition().getCol() - 2;
      space_3 = getPosition().getCol() - 3;
      space_4 = getPosition().getCol() - 4;

      if (
         board->getPiece(row, space_1)->getLetter() == '_' &&
         board->getPiece(row, space_2)->getLetter() == '_' &&
         board->getPiece(row, space_3)->getLetter() == '_' &&
         board->getPiece(row, space_4)->getLetter() == 'r' &&
         
         board->getPiece(row, col)->getNMoves() == 0 &&
         board->getPiece(row, space_4)->getNMoves() == 0
         )
      {
          moves->insert({ r * 8 + space_3, Move(posFrom, Position(r * 8 + space_3), false, false, true, false, false) });
      }
   }
   return moves;
}

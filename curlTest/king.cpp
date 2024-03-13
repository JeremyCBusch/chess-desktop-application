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


unordered_map<int, Move> King::getPossibleMoves(Position posFrom, Board* board, int currentMove, bool isPlayerWhite)
{
    unordered_map<int, Move> moves = unordered_map<int, Move>();
   
   if (!isPlayersTurn(isPlayerWhite, currentMove) || isPlayerWhite != isWhite()) {
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

          if (board->getPiece(r * 8 + c)->getLetter() == '_')
              moves.insert({ r * 8 + c, Move(posFrom, Position(r * 8 + c)) });
          
          else if (!board->isSameColor(this, board->getPiece(r * 8 + c)))
          {
              Move move = Move(posFrom, Position(r * 8 + c));
              move.setStandardCapture(true);
              moves.insert({ r * 8 + c, move });
          }

      }
       
         
   }


   int row = getPosition().getRow();
   int col = getPosition().getCol();

   bool thing;
   bool thing1;
   bool thing3;
   bool thing4;
   bool thing5;
   bool thing6;
   bool thing7;


   // Black King Check Castling 
   if ((isWhite() && row == 7) || (!isWhite() && row == 0))
   {
      // King Side Castle

      space_1 = getPosition().getCol() + 1;
      space_2 = getPosition().getCol() + 2;
      space_3 = getPosition().getCol() + 3;

      thing =  board->getPiece(row, space_1)->getLetter() == '_';
      thing1 = board->getPiece(row, space_2)->getLetter() == '_';
      thing3 = board->isSameColor(this, board->getPiece(row, space_3));
      thing4 = tolower(board->getPiece(row, space_3)->getLetter()) == 'r';
      thing5 = !board->getPiece(row, col)->hasMoved();
      thing6 = !board->getPiece(row, space_3)->hasMoved();


      if (
          board->getPiece(row, space_1)->getLetter() == '_' &&
          board->getPiece(row, space_2)->getLetter() == '_' &&
          board->isSameColor(this, board->getPiece(row, space_3)) &&
          tolower(board->getPiece(row, space_3)->getLetter()) == 'r' &&
          !board->getPiece(row, col)->hasMoved() &&
          !board->getPiece(row, space_3)->hasMoved()
         )
      {
          moves.insert({ row * 8 + space_2, Move(posFrom, Position(row * 8 + space_2),false, true, false, false, false)});
      }

      // Queen Side Castle
      space_1 = getPosition().getCol() - 1;
      space_2 = getPosition().getCol() - 2;
      space_3 = getPosition().getCol() - 3;
      space_4 = getPosition().getCol() - 4;


      Position position = board->getPiece(row, space_4)->getPosition();
      int location = board->getPiece(row, space_4)->getPosition().getLocation();
      bool iswhittee = board->getPiece(row, space_4)->isWhite();

      thing = board->getPiece(row, space_1)->getLetter() == '_';
      thing1 = board->getPiece(row, space_2)->getLetter() == '_';
      thing3 = board->getPiece(row, space_3)->getLetter() == '_';
      thing4 = board->isSameColor(this, board->getPiece(row, space_4));
      thing5 = tolower(board->getPiece(row, space_4)->getLetter()) == 'r';
      thing6 = !board->getPiece(row, col)->hasMoved();
      thing7 = !board->getPiece(row, space_3)->hasMoved();

      //TEST



      //TODO black queen side castling is throwing an error. find out why

      if (
         board->getPiece(row, space_1)->getLetter() == '_' &&
         board->getPiece(row, space_2)->getLetter() == '_' &&
         board->getPiece(row, space_3)->getLetter() == '_' &&
         board->isSameColor(this, board->getPiece(row, space_4)) &&
         tolower(board->getPiece(row, space_4)->getLetter()) == 'r' &&
         !board->getPiece(row, col)->hasMoved() &&
         !board->getPiece(row, space_3)->hasMoved()
         )
      {
          moves.insert({ row * 8 + space_3, Move(posFrom, Position(row * 8 + space_3), false, false, true, false, false) });
      }
   }
   
   
   return moves;
}

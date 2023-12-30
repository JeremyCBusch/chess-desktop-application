/***********************************************************************
 * Source File:
 *    Pawn : Represents a Pawn that inherits from piece
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    All traits of Pawn
 ************************************************************************/


#include "pawn.h"


using namespace std;
char Pawn::getLetter()
{
   if (isWhite())
      return 'p'; // lowercase
   else
      return 'P'; //upppercase
}

void Pawn::display(ogstream& gout)
{
   gout.drawPawn(position.getLocation(), !fWhite);
}

unordered_map<int, Move>* Pawn::getPossibleMoves(Position posFrom, Board* board, int currentMove)
{
    unordered_map<int, Move>* moves = new unordered_map<int, Move>();

   int PawnRow = getPosition().getRow();
   int PawnCol = getPosition().getCol();
   Piece* selectedPawn = board->getPiece(PawnRow, PawnCol);
   Piece* preyPawn;
   Piece* PieceBehindPreyPawn;


   int location = getPosition().getLocation();
   int forwardDirection = (isWhite()) ? -1 : 1;

   if ((currentMove % 2 == 1 && isWhite() == false) || currentMove % 2 == 0 && isWhite() == true) {
      return moves;
   }

   
   // FORWARD TWO BLANK SPACE
   if (Board::isValidboardIndex((PawnRow + (forwardDirection * 2)) * 8 + PawnCol)) {
       if (board->getPiece((PawnRow + (forwardDirection * 2)) * 8 + PawnCol)->getLetter() == '_' && !selectedPawn->hasMoved())
       {
           Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 2)) * 8 + PawnCol));
           moves->insert({ (PawnRow + (forwardDirection * 2)) * 8 + PawnCol,  move });
       }
   }

   // FORWARD ONE BLANK SPACE
   if (Board::isValidboardIndex((PawnRow + (forwardDirection * 1)) * 8 + PawnCol)) {
       if (board->getPiece((PawnRow + (forwardDirection * 1)) * 8 + PawnCol)->getLetter() == '_')
       {
           Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol));
           moves->insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol, move });
       }
   }
   


   // ATTACK LEFT
   if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol - 1)) {
       preyPawn = board->getPiece(PawnRow + forwardDirection, PawnCol - 1);

       if (!Board::isSameColor(selectedPawn, preyPawn) && preyPawn->getLetter() != '_' && selectedPawn->getPosition().getRow() + forwardDirection == preyPawn->getPosition().getRow()) {
           Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1), false, false, false, false, true);
           moves->insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1, move });
       }
   }

   

   // ATTACK RIGHT
   if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol + 1)) {
       preyPawn = board->getPiece(PawnRow + forwardDirection, PawnCol + 1);

       if (!Board::isSameColor(selectedPawn, preyPawn) && preyPawn->getLetter() != '_' && selectedPawn->getPosition().getRow() + forwardDirection == preyPawn->getPosition().getRow()) {
           Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol + 1), false, false, false, false, true);
           moves->insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol + 1, move });
       }
   }


   // ENPASSANT DIAGONAL LEFT
   if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol - 1)) {
       preyPawn = board->getPiece(PawnRow, PawnCol - 1);
       PieceBehindPreyPawn = board->getPiece(PawnRow + forwardDirection, PawnCol - 1);

       if (preyPawn->justMoved(board->getCurrentMoveIndex()) &&
           preyPawn->getNMoves() == 1 &&
           !Board::isSameColor(selectedPawn, preyPawn) &&
           PieceBehindPreyPawn->getLetter() == '_')
       {
           Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1), true, false, false, false, false);
           moves->insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1, move });
       }
   }

   
   // ENPASSANT DIAGONAL RIGHT
   if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol + 1)) {
       preyPawn = board->getPiece(PawnRow, PawnCol + 1);
       PieceBehindPreyPawn = board->getPiece(PawnRow + forwardDirection, PawnCol + 1);

       if (preyPawn->justMoved(board->getCurrentMoveIndex()) &&
           preyPawn->getNMoves() == 1 &&
           !Board::isSameColor(selectedPawn, preyPawn) &&
           PieceBehindPreyPawn->getLetter() == '_')
       {
           Position posTo = Position(PieceBehindPreyPawn->getPosition().getLocation());
           Move move = Move(posFrom, posTo, true, false, false, false, false);
           moves->insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol + 1, move });
       }
   }
       
    
   for (auto it = moves->begin(); it != moves->end(); it++) {
       if (it->second.getDestination().getRow() == 0 || it->second.getDestination().getRow() == 7)
           it->second.setPromotion(true);
   }

   return moves;
}

void Pawn::markMovesAsCheck(unordered_map<int, Move>* moves, const int board[])
{
    //Iterate through all of the moves
    for (auto it = moves->begin(); it != moves->end(); it++) {
        // Set the stage: AKA create a new board based on the current move
         
        //  get the possible moves for that piece
    }
    
}

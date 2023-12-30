
#include "board.h"
#include "pawn.h"
#include "space.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"



void Board::incrementCurrentMoveIndex()
{
   currentMoveIndex++;
}



void Board::reset()
{

   // Black Down
   for (int i = 8; i < 16; i++)
   {
      Pawn* pawn = new Pawn(0, i, false);
      board[i] = pawn;
   }

   //white UP
   int count = 0;
   for (int i = 48; i < 56; i++)
   {
      Pawn* pawn = new Pawn((i / 8), count, true);
      board[i] = pawn;
      count++;
   }


   //instantiate spaces
   for (int i = 2; i < 6; i++)
   {
      for (int x = 0; x < 8; x++)
      {
         Space* space = new Space(i, x, true);
         board[(i * 8) + x] = space;
      }
   }

   // Black is DOWN
   Rook* rookLeft = new Rook(0, 0, false);
   Rook* rookRight = new Rook(0, 7, false);
   board[0] = rookLeft;
   board[7] = rookRight;




   Knight* knightLeft = new Knight(0, 1, false);
   Knight* knightRight = new Knight(0, 6, false);

   board[1] = knightLeft;
   board[6] = knightRight;

   Bishop* bishopLeft = new Bishop(0, 2, false);
   Bishop* bishopRight = new Bishop(0, 5, false);



   board[2] = bishopLeft;
   board[5] = bishopRight;

   Queen* queen = new Queen(0, 3, false);
   board[3] = queen;

   King* king = new King(0, 4, false);
   board[4] = king;



    // ASSIGN WHITE TO BOARD
   Rook* rookLeftWhite = new Rook(7, 0, true);
   Rook* rookRightWhite = new Rook(7, 7, true);
   board[56] = rookLeftWhite;
   board[63] = rookRightWhite;


   Knight* knightLeftWhite = new Knight(7, 1, true);
   Knight* knightRightWhite = new Knight(7, 6, true);
   board[57] = knightLeftWhite;
   board[62] = knightRightWhite;

   Bishop* bishopLeftWhite = new Bishop(7, 2, true);
   Bishop* bishopRightWhite = new Bishop(7, 5, true);
   board[58] = bishopLeftWhite;
   board[61] = bishopRightWhite;

   Queen* queenWhite = new Queen(7, 3, true);
   board[59] = queenWhite;

   King* kingWhite = new King(7, 4, true);
   board[60] = kingWhite;

}


Board::Board() : currentMoveIndex(1)
{
   reset();
}

// BlACK IS UPPER CASE
bool Board::isNotBlack(int row, int col)
{
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;

   char letter = board[row * 8 + col]->getLetter();

   return letter == '_' || (letter >= 'a' && letter <= 'z');
}

// WHITE IS LOWER CASE
bool Board::isNotWhite(int row, int col)

{
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;

   char letter = board[row * 8 + col]->getLetter();

   return letter == '_' || (letter >= 'A' && letter <= 'Z');
}

void Board::display(int posHover, int posSel)
{
   gout.drawBoard();
   gout.drawHover(posHover);
   gout.drawSelected(posSel);


   // If the selected Position was valid draw the possible moves;
   if (posSel >= 0 && posSel < 64)
   {
       unordered_map<int, Move>* possibleMoves = new unordered_map<int, Move>();
       possibleMoves = getPiece(posSel)->getPossibleMoves(board[posSel]->getPosition(), this, currentMoveIndex);


      for (auto itr = possibleMoves->begin(); itr != possibleMoves->end(); ++itr)
          gout.drawPossible(itr->second);

   }

   for (auto it: board)
       it->display(gout);

   gout.drawTurn(currentMoveIndex);
}

void Board::executeMove(Move move)
{
    //Get the pieces associated with the move
    Piece* sourcePiece = board[move.getSource().getLocation()];
    Piece* destinationPiece = board[move.getDestination().getLocation()];
    

    swap(sourcePiece, destinationPiece);

    sourcePiece->setLastMoveIndex(getCurrentMoveIndex());
    incrementCurrentMoveIndex();
    board[sourcePiece->getPosition().getLocation()]->setNMoves(1);
    

    // Standard Capture
    if (move.getIsStandardCapture()) 
    {
        int destinationLocation = destinationPiece->getPosition().getLocation();
        int row = destinationPiece->getPosition().getRow();
        int col = destinationPiece->getPosition().getCol();
        Space* newSpace = new Space(row, col, true);
        board[(row * 8 + col)] = newSpace;
        destinationPiece->setIsDead(true);
        delete destinationPiece;
;    }

    // Enpassant
    if (move.getEnPassant()) 
    {  
        int pawnDirection = (sourcePiece->isWhite()) ? 1 : -1; //TODO:  This could use a different name because the values are switched
        Piece* capturedPawn = board[sourcePiece->getPosition().getLocation() + (pawnDirection * 8)];
        int capturedPawnLocation = capturedPawn->getPosition().getLocation();
        int row = capturedPawn->getPosition().getRow();
        int col = capturedPawn->getPosition().getCol();

        Space* space = new Space(row, col, true);
        board.at(row * 8 + col) = space;

        delete capturedPawn;
    }

    // Castling
    if (move.getKingSideCastle() || move.getQueenSideCastle()) 
    {
        int rookColMovement = (move.getKingSideCastle()) ? 1 : -1;
        Piece *  kingSideRook = board[sourcePiece->getPosition().getLocation() + rookColMovement];   // one tile to the right from where the king moves

        swap(kingSideRook, sourcePiece);
    }

    // Promotion
    if (move.getPromotion()) 
    { 
        Position positionOfPieceThatMoved = sourcePiece->getPosition();
        board[positionOfPieceThatMoved.getLocation()] = new Queen(positionOfPieceThatMoved.getRow(), positionOfPieceThatMoved.getCol(), sourcePiece->isWhite());
        delete sourcePiece;
    }
}



void Board::swap(Piece* piece1, Piece* piece2)
{
    Piece* tempP = board[piece2->getPosition().getLocation()];
    Piece* p1 = board[piece1->getPosition().getLocation()];
    Piece* p2 = board[piece2->getPosition().getLocation()];

    // Update board
    board[p2->getPosition().getLocation()] = p1;
    board[p1->getPosition().getLocation()] = tempP;


    // Update the Pieces Position
    Position  temp = p1->getPosition();
    p1->getPosition() = p2->getPosition();
    p2->getPosition() = temp;

}
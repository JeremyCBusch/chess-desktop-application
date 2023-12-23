/***********************************************************************
 * Source File:
 *    Piece : Represents an abstract type piece in the chess game
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Abstract type, where other classes inherit from
 ************************************************************************/



#include "piece.h"


Piece::Piece(int row, int col, bool isWhite) : position(row, col)
{
   fWhite = isWhite;
   nMoves = 0;
   lastMoveIndex = -1;
}

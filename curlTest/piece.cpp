/***********************************************************************
 * Source File:
 *    Piece : Represents an abstract type piece in the chess game
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Abstract type, where other classes inherit from
 ************************************************************************/



#include "piece.h"
#include "board.h"


Piece::Piece(int row, int col, bool isWhite) : position(row, col)
{
   fWhite = isWhite;
   nMoves = 0;
   lastMoveIndex = -1;
   originalLocation = row * 8 + col;
}


unordered_map<int, Move> Piece::getPossibleLinearMoves(Delta delta[], Position posFrom, Board* board)
{
    unordered_map<int, Move> moves = unordered_map<int, Move>();

    int r;
    int c;

    int numberOfDeltas = sizeof(delta);

    for (int i = 0; i < numberOfDeltas; i++)
    {
        r = getPosition().getRow() + delta[i].dRow;
        c = getPosition().getCol() + delta[i].dCol;

        Piece* currentPiece;
        Piece* previousPiece = nullptr;

        while (r >= 0 && r < 8 && c >= 0 && c < 8 && (previousPiece == nullptr || previousPiece->getLetter() == '_'))
        {
            currentPiece = board->getPiece(r * 8 + c);
            if (currentPiece->getLetter() == '_' || (currentPiece->getLetter() != '_' && !board->isSameColor(this, currentPiece))) {
                Move move = Move(posFrom, Position(r * 8 + c));
                if (currentPiece->getLetter() != '_' && !board->isSameColor(this, currentPiece))
                    move.setStandardCapture(true);
                moves.insert({ r * 8 + c, move });


            }
            previousPiece = board->getPiece(r * 8 + c);
            r += delta[i].dRow;
            c += delta[i].dCol;
        }
    }
    return moves;
}



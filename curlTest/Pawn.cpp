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

unordered_map<int, Move> Pawn::getPossibleMoves(Position posFrom, Board* board, int currentMove, bool isPlayerWhite)
{
    return getPossibleMovesSimpleBoard(posFrom, currentMove, board->getSimpleBoardCopy(), true, isPlayerWhite);
}






unordered_map<int, Move> Pawn::getPossibleMovesSimpleBoard(Position posFrom, int currentMove, vector<char>* board, bool checkForCheck, bool isPlayerWhite)
{
    unordered_map<int, Move> moves = unordered_map<int, Move>();

    int PawnRow = posFrom.getRow();
    int PawnCol = posFrom.getCol();
    Piece* selectedPawn = this;
    char preyPawn;
    char PieceBehindPreyPawn;


    int location = posFrom.getLocation();
    int forwardDirection = (isWhite()) ? -1 : 1;


    if (!isPlayersTurn(isPlayerWhite, currentMove) || isPlayerWhite != isWhite()) {
        return moves;
    }


    // FORWARD TWO BLANK SPACE
    if (Board::isValidboardIndex((PawnRow + (forwardDirection * 2)) * 8 + PawnCol)) {
        if (board->at(((PawnRow + (forwardDirection * 2)) * 8 + PawnCol)) == '_' && !selectedPawn->hasMoved())
        {
            Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 2)) * 8 + PawnCol));
            moves.insert({ (PawnRow + (forwardDirection * 2)) * 8 + PawnCol,  move });
        }
    }

    // FORWARD ONE BLANK SPACE
    if (Board::isValidboardIndex((PawnRow + (forwardDirection * 1)) * 8 + PawnCol)) {
        if (board->at(((PawnRow + (forwardDirection * 1)) * 8 + PawnCol)) == '_')
        {
            Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol));
            moves.insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol, move });
        }
    }



    // ATTACK LEFT
    if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol - 1)) {
        preyPawn = board->at(((PawnRow + forwardDirection) * 8) + PawnCol - 1);

        if (Board::areOpposingColors(selectedPawn->getLetter(), preyPawn) && preyPawn != '_' && PawnRow + forwardDirection == PawnRow + forwardDirection) {
            Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1), false, false, false, false, true);
            moves.insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1, move });
        }
    }

    // ATTACK RIGHT
    if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol + 1)) {
        preyPawn = board->at(((PawnRow + forwardDirection) * 8) + PawnCol + 1);

        if (Board::areOpposingColors(selectedPawn->getLetter(), preyPawn) && preyPawn != '_' && PawnRow + forwardDirection == PawnRow + forwardDirection) {
            Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol + 1), false, false, false, false, true);
            moves.insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol + 1, move });
        }
    }


    // ENPASSANT DIAGONAL LEFT
    if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol - 1)) {
        preyPawn = board->at((PawnRow * 8) + PawnCol - 1);
        PieceBehindPreyPawn = board->at(((PawnRow + forwardDirection) * 8) + PawnCol - 1);
        if (((preyPawn == 'p' && PawnRow == 4) || (preyPawn == 'P' && PawnRow == 3)) && //Note: This assumes that the pawn just moved two spaces forward
            Board::areOpposingColors(selectedPawn->getLetter(), preyPawn) &&
            PieceBehindPreyPawn == '_')
        {
            Move move = Move(posFrom, Position((PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1), true, false, false, false, false);
            moves.insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol - 1, move });
        }
    }


    // ENPASSANT DIAGONAL RIGHT
    if (Board::isValidboardIndex(PawnRow + forwardDirection, PawnCol + 1)) {
        preyPawn = board->at((PawnRow * 8) + PawnCol + 1);
        PieceBehindPreyPawn = board->at(((PawnRow + forwardDirection) * 8 ) + PawnCol + 1);

        if (((preyPawn == 'p' && PawnRow == 4) || (preyPawn == 'P' && PawnRow == 3)) && //Note: This assumes that the pawn just moved two spaces forward
            Board::areOpposingColors(selectedPawn->getLetter(), preyPawn) &&
            PieceBehindPreyPawn == '_')
        {
            Move move = Move(posFrom, Position(PawnRow + forwardDirection, PawnCol + 1), true, false, false, false, false);
            moves.insert({ (PawnRow + (forwardDirection * 1)) * 8 + PawnCol + 1, move });
        }
    }


    for (auto it = moves.begin(); it != moves.end(); it++) {
        if (it->second.getDestination().getRow() == 0 || it->second.getDestination().getRow() == 7)
            it->second.setPromotion(true);

        if (checkForCheck) {
            if (isCheckMove(it->second, board, currentMove, isPlayerWhite))
                it->second.setisCheck(true);
        }
    }


    return moves;
}



bool Pawn::isCheckMove(Move move, vector<char>* board, int currentMove, bool isPlayerWhite)
{
    Board::executeMoveOnFakeBoard(move, board);

    Position newPosFrom = move.getDestination();

    unordered_map<int, Move> possibleMoves = getPossibleMovesSimpleBoard(newPosFrom, currentMove + 2 /*plus two for colors next move*/, board, false, isPlayerWhite);

    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); it++) {
        if (board->at(it->second.getDestination().getLocation()) == 'k' || board->at(it->second.getDestination().getLocation()) == 'K')
        {
            return true;
        }
    }

    return false;
}




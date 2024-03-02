/***********************************************************************
 * Header File:
 *    Rook : The representation of a Pawn
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Everything we need to know about a rook on the screen
 ************************************************************************/




#include "piece.h"
#include "board.h"
#include <set>
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "uiDraw.h"

using namespace std;

#pragma once

class Rook : public Piece
{
public:
   Rook() {};
   Rook(int r, int c, bool b) : Piece(r, c, b) {};
   char getLetter();
   void display(ogstream& gout);
   unordered_map<int, Move> getPossibleMoves(Position posFrom, Board* board, int currentMove);

};

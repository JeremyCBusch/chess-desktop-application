/***********************************************************************
 * Header File:
 *    Bishop : The representation of a Bishop
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Everything we need to know about a Bishop on the screen
 ************************************************************************/


#include "piece.h"
#include "board.h"
#include <set>
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "uiDraw.h"

using namespace std;

#pragma once

class Bishop : public Piece
{
public:
   Bishop() {};
   Bishop(int r, int c, bool b) : Piece(r, c, b) {};
   char getLetter();
   void display(ogstream& gout);
   unordered_map<int, Move>* getPossibleMoves(Position posFrom, Board* board, int currentMove);
};


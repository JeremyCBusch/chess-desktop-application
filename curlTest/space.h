/***********************************************************************
 * Header File:
 *    Space : The representation of a Space
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Everything we need to know about a Space on the screen
 ************************************************************************/



#include "board.h"
#include <fstream>        // for IFSTREAM
#include <string>
#include <set>
#include "uiDraw.h"
using namespace std;

#pragma once
class Space : public Piece
{
public:
   Space() {};
   Space(int r, int c, bool b) : Piece(r, c, b) {};
   char getLetter();
   void display(ogstream& gout);
   unordered_map<int, Move> getPossibleMoves(Position posFrom, Board* board, int currentMove, bool isPlayerWhite);
};

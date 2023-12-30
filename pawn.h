/***********************************************************************
 * Header File:
 *    Pawn : The representation of a Pawn
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Everything we need to know about a pawn on the screen
 ************************************************************************/



#include "piece.h"
#include "board.h"
#include <set>
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "uiDraw.h"

using namespace std;

#pragma once
class Pawn : public Piece
{
public:
   Pawn() {};
   Pawn(int r, int c, bool b) : Piece{ r,c,b } { };
   virtual ~Pawn()
   {

       
   };

   char getLetter();
   void display(ogstream& gout);
   unordered_map<int, Move>* getPossibleMoves(Position posFrom, Board* board, int currentMove);
   void markMovesAsCheck(unordered_map<int, Move>* moves, const int board[]);
   
};


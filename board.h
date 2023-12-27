#include "piece.h"
#include <unordered_set>
#include "move.h"
#include "position.h"
#include "uiInteract.h"
#include <vector>
#include<iterator>




using namespace std;

#pragma once


class Board
{
private:
   //member variables
   vector<Piece*> board = vector<Piece*>(64);
   ogstream gout;
   void assertBoard();
   int currentMoveIndex; 
   void incrementCurrentMoveIndex();
public:
   Board();
   Board(ogstream gout);
   int getCurrentMoveIndex() { return currentMoveIndex; }
   bool whiteTurn() { return currentMoveIndex % 2 == 0; } 
   void display(int posHover, int posSel);
   Piece* get(Position pos) { return board[pos.getLocation()]; }
   Piece* getPiece(int pos) { return board[pos]; };
   bool isSameColor(Piece* piece1, Piece* piece2) { return piece1->isWhite() == piece2->isWhite(); }
   void executeMove(Move move);
   bool isValidboardIndex(int index) { return index > 0 && index < 64; }
   bool isValidboardIndex(int row, int col) { return row * 8 + col > 0 && row * 8 + col < 64; }


   //Piece** getBoard() { return board; };

   Piece* getPiece(int row, int col)
   {
       return (row * 8 + col >= 0 && row * 8 + col < 64) ? board[row * 8 + col] : nullptr;
   }



   bool isNotBlack(int row, int col);
   bool isNotWhite(int row, int col);


   void reset();
   void move(int posFrom, int posTo);
   void displayPieces();

   void promoteQ(int r, int c, bool white);



   void swap(Piece* piece1, Piece* piece2);

   void castleK(int from, int To);

   void castleQ(int posFrom, int posTo);


   // Assignment Operator

   // Subscript Operator
   Piece* operator [] (int index)
   {
      return board[index];
   }


};

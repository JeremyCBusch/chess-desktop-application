#include "piece.h"
#include <unordered_set>
#include "move.h"
#include "position.h"
#include "uiInteract.h"
#include "serverConnector.h"
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
   bool playerIsWhitePieces;
   int gameID;
   string userName;
public:
   Board();
   Board(bool isWhite, int gameID, string userName);
   Board(ogstream gout);
   int getCurrentMoveIndex() { return currentMoveIndex; }
   bool whiteTurn() { return currentMoveIndex % 2 == 0; } 
   void display(int posHover, int posSel);
   Piece* get(Position pos) { return board[pos.getLocation()]; }
   Piece* getPiece(int pos) { return board[pos]; };
   static bool isSameColor(Piece* piece1, Piece* piece2) { return piece1->isWhite() == piece2->isWhite(); }
   void executeMove(Move move);
   static void executeMoveOnFakeBoard(Move move, vector<char>* fakeBoard);
   static bool isValidboardIndex(int index) { return index > 0 && index < 64; }
   static bool isValidboardIndex(int row, int col);
   vector<char>* getSimpleBoardCopy();
   static bool areOpposingColors(char firstPiece, char secondPiece);
   void setPlayerIsWhitePieces(bool isWhite) { playerIsWhitePieces = isWhite; }
   bool getPlayerIsWhitePieces() { return playerIsWhitePieces; }
   //Piece** getBoard() { return board; };
   int getGameID() { return gameID; }
   string getUserName(){ return userName; }

   bool getPlayerWhitePieces() { return playerIsWhitePieces;  }
   Piece* getPiece(int row, int col)
   {
       return (row * 8 + col >= 0 && row * 8 + col < 64) ? board[row * 8 + col] : nullptr;
   }



   bool isNotBlack(int row, int col);
   bool isNotWhite(int row, int col);


   void reset();




   void swap(Piece* piece1, Piece* piece2);




   // Assignment Operator

   // Subscript Operator
   Piece* operator [] (int index)
   {
      return board[index];
   }


};

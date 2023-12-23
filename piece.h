#include"position.h"
#include "uiDraw.h"
#include "move.h"
#include <unordered_map>
#include <set>
#pragma once


using namespace std;


class Move;
class Board;

class Piece
{
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMoveIndex;
   bool isDead = false;

public:
   // Constructors
    Piece() {};
   Piece(int r, int c, bool white = true);

   Piece(const Piece& piece) { *this = piece; }

   //TODO: implement destuctor somehow
   virtual ~Piece() 
   {

   };


   bool isWhite() const { return this->position.isValid() ? fWhite : false; }
   int getLastMoveIndex() const { return lastMoveIndex; }
   int getNMoves()const { return nMoves; }
   bool hasMoved() const { return nMoves > 0; }
   bool getIsDead() { return isDead; }

   Position& getPosition() { return position; }

   bool justMoved(int currentMove) const
   {
      return (currentMove - 1 == lastMoveIndex);
   }

   void setNMoves(int nMove) { nMoves += nMove; }
   void setLastMoveIndex(int currentMoveIndex) { lastMoveIndex = currentMoveIndex; }
   void setIsDead(bool newIsDead) { isDead = newIsDead; }

   // Virtual Methods
   virtual char getLetter() = 0;
   virtual void display(ogstream& gout) = 0;
   virtual unordered_map<int, Move>* getPossibleMoves(Position posFrom, Board* board, int currentMove) = 0;

   // Operators
   bool operator == (char letter) { return getLetter() == letter; }
   bool operator != (char letter) { return getLetter() != letter; }



   // Assignment Operator Position
   const Piece& operator = (const Position& rhs)
   {
      // Increase the Move for the Piece
      nMoves++;
      position = rhs;
      return *this;
   }

   // Assignment Operator Piece
   //const Piece& operator = (const Piece& rhs);

};


#include <string>
#include "position.h"
#include <set>
using namespace std;

#pragma  once


class Move
{
private:
   Position source;
   Position destination;

   bool enPassant;
   bool kingSideCastle;
   bool queenSideCastle;
   bool promotion;
   bool standardCapture;
   bool isCheck;

public:

   // CONSTRUCTORS
   Move(Position source, Position destination, bool enPassant = false, bool kingSideCastle = false, bool queenSideCastle = false, bool promotion = false, bool standardCapture = false);
 

   // GETTERS
   Position getSource() { return source; }
   Position getDestination() { return destination; }
   bool getEnPassant() { return enPassant; }
   bool getKingSideCastle() { return kingSideCastle; }
   bool getQueenSideCastle() { return queenSideCastle; }
   bool getPromotion() { return promotion; }
   bool getIsStandardCapture() { return standardCapture; }
   bool getisCheck() { return isCheck; }

   // SETTERS
   void setSource(Position& pos) { source = pos; }
   void setDestination(Position& pos) { destination = pos; }
   void setEnPassant(bool enPassant) { this->enPassant = enPassant; }
   void setKingSideCastle(bool kingSideCastle) { this->kingSideCastle = kingSideCastle; }
   void setQueenSideCastle(bool queenSideCastle) { this->queenSideCastle = queenSideCastle; }
   void setPromotion(bool promotion) { this->promotion = promotion; }
   void setStandardCapture(bool capture) { this->standardCapture = capture; }
   void setisCheck(bool newIsCheck) { isCheck = newIsCheck; }
};

#include <string>
#include "position.h"
#include "json.hpp"
#include <set>
using namespace std;
using json = nlohmann::json;

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

   string playerUserName;

public:

   // CONSTRUCTORS
   Move(Position source, Position destination, bool enPassant = false, bool kingSideCastle = false, bool queenSideCastle = false, bool promotion = false, bool standardCapture = false);
   Move(json jsonMove);
 

   // GETTERS
   Position getSource() { return source; }
   Position getDestination() { return destination; }
   bool getEnPassant() { return enPassant; }
   bool getKingSideCastle() { return kingSideCastle; }
   bool getQueenSideCastle() { return queenSideCastle; }
   bool getPromotion() { return promotion; }
   bool getIsStandardCapture() { return standardCapture; }
   bool getisCheck() { return isCheck; }
   string getPlayerUserName() { return playerUserName; }

   // SETTERS
   void setSource(Position& pos) { source = pos; }
   void setDestination(Position& pos) { destination = pos; }
   void setEnPassant(bool enPassant) { this->enPassant = enPassant; }
   void setKingSideCastle(bool kingSideCastle) { this->kingSideCastle = kingSideCastle; }
   void setQueenSideCastle(bool queenSideCastle) { this->queenSideCastle = queenSideCastle; }
   void setPromotion(bool promotion) { this->promotion = promotion; }
   void setStandardCapture(bool capture) { this->standardCapture = capture; }
   void setisCheck(bool newIsCheck) { isCheck = newIsCheck; }
   void setPlayerUserName(string newUserName) { playerUserName = newUserName; }

   //JSON
   string toJSONString();
   string strBool(bool value) { return (value) ? "true" : "false"; }

};

/***********************************************************************
 * Source File:
 *    Move : Represents how a piece moves on the game
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    How move is done, how capture, castling and enpassant move are performed
 ************************************************************************/
#include <stdio.h>
#include "move.h"



Move::Move(Position source, Position destination, bool enPassant, bool kingSideCastle, bool queenSideCastle, bool promotion, bool standardCapture)
{
	this->source = source;
	this->destination = destination;
	this->enPassant = enPassant;
	this->kingSideCastle = kingSideCastle;
	this->queenSideCastle = queenSideCastle;
	this->promotion = promotion;
	this->standardCapture = standardCapture;
	this->isCheck = false;
}

Move::Move(json jsonMove)
{
	this->enPassant = jsonMove.at("IsEnPassant");
	this->kingSideCastle = jsonMove.at("IsKingSideCastle");
	this->queenSideCastle = jsonMove.at("IsQueenSideCastle");
	this->promotion = jsonMove.at("IsPromotion");
	this->standardCapture = jsonMove.at("IsStandardCapture");
	this->isCheck = jsonMove.at("IsCheck");

	int intposFrom =  std::uint64_t(jsonMove.at("PositionFrom"));
	int intposTo = std::uint64_t(jsonMove.at("PositionTo"));
	Position posFrom = Position();
	Position posTo = Position();
	posFrom.set(intposFrom);
	posTo.set(intposTo);

	this->source = posFrom;
	this->destination = posTo;
}

string Move::toJSONString()
{
	/*
	{
    "isEnPassant": true,
	"isKingSideCastle": false,
	"isQueenSideCastle": false,
	"isPromotion": false,
	"isStandardCapture": false,
	"isCheck": false,
	"positionFrom": 0,
	"positionTo": 8
	}
	*/

	//stream << "Hello, " << nameField;
	//stream << ", here is an int " << 7;

	//string move =  " \"isEnPassant\": "        + std::to_string(enPassant) + "," + 
	//				"\"isKingSideCastle\": "   + std::to_string(kingSideCastle) + "," +
	//	            "\"isQueenSideCastle\" : " + std::to_string(queenSideCastle) + "," +
	//	            "\"isPromotion\" : "       + std::to_string(promotion) + "," +
	//	            "\"isStandardCapture\" : " + std::to_string(standardCapture) + "," +
	//	            "\"isCheck\" : "           + std::to_string(isCheck) + "," +
	//	            "\"positionFrom\" : "      + std::to_string(source.getLocation()) + "," +
	//	            "\"positionTo\" : "        + std::to_string(destination.getLocation()) + "," + " }";

	string move = "{\"isEnPassant\":" + strBool(enPassant) + ","
	"\"isKingSideCastle\":" + strBool(kingSideCastle) + ","
	"\"isQueenSideCastle\":" + strBool(queenSideCastle) + ","
	"\"isPromotion\":" + strBool(promotion) + ","
	"\"isStandardCapture\":" + strBool(standardCapture) + ","
	"\"isCheck\":" + strBool(isCheck) + ","
	"\"positionFrom\":" + std::to_string(enPassant) + ","
	"\"positionTo\":" + std::to_string(enPassant) +
	"}";

	//const char* moveCSTR = move.c_str();
	return move;
}






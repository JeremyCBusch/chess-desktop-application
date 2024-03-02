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



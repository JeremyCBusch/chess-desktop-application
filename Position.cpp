/***********************************************************************
 * Source File:
 *    Position : Represents a Position of a Piece on the game
 * Author:
 *    Sulav Dahal and Jeremy Busch
 * Summary:
 *    Find the location, row, col, etc of a particular piece on the game
 ************************************************************************/





#include "position.h"
#include <iostream>

using namespace std;


int Position::getLocation()
{
   return location;
}

int Position::getRow()
{
   return isInvalid() ? 0 : (int)(location / 8);
}

int Position::getCol()
{
   return  isInvalid() ? 0 : (int)(location % 8);
}

int Position::getX()
{
   return  (int)((double)getCol() * getSquareWidth());
}

int Position::getY()
{
   return (int)((double)getCol() * getSquareHeight());
}

void Position::setRow(int row)
{
   if (row >= 0 && row < 8 && isValid())
   {

      location = row * 8 + getCol();
   }
   else
   {
      location = -1;
   }
}

void Position::setCol(int col)
{

   location = getRow() * 8 + col;

}

void Position::set(int row, int col)
{
   location = 0;
   setRow(row);
   setCol(col);
}


bool Position:: operator != (const Position& rhs) const
{
   if (!isInvalid())
      return rhs.isValid();
   else
      return rhs.location != location;
}


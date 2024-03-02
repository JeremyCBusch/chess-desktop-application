#include "space.h"
#include "uiDraw.h"

char Space::getLetter()
{
   return '_';
}

void Space::display(ogstream& gout)
{
   // not evven going to deal with that yet.

}


unordered_map<int, Move> Space::getPossibleMoves(Position posFrom, Board* Board, int currentMove)
{
	return unordered_map<int, Move>();
}

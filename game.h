//
//  game.h
//  Lab05
//
//  Created by Sulav Dahal on 5/17/22.
//

#pragma once

#include "board.h"

class Game
{
private:
   Board* boardInstance;
public:
   //    Board* getBoardGout(ogstream gout) {return board;}
   Game();

   Board* getBoard() { return boardInstance; }

   void displayPiece();
};

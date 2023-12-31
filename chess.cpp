#include <stdio.h>
#include <unordered_map>
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"
#include "Point.h"
#include "board.h"
#include "game.h"
#include "pawn.h"
#include "move.h"
using namespace std;


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/

/**
WELCOME TO JEREMY'S TODO LIST

3. so if we can add functionality to the piece class to for derived classes to inherit
4. Add functionality for capturing of non pawn pieces.
7. Add winner screen. perhaps try to make a 3d cube...?
8. add a header for text descriptions and buttons for promotion
9. show text when king is in check
20. allow promotion to any piece

*/


//Note white is on top and goes first


void callBack(Interface* pUI, void* p)
{
   // Cast the Void Pointer to the game object
   Board* board = (Board*)p;


   unordered_map<int, Move>* moves = new unordered_map<int,Move>();
   int currentMoveIndex;


   if (pUI->getPreviousPosition() >= 0 && pUI->getPreviousPosition() < 64)
   {
      currentMoveIndex = board->getCurrentMoveIndex();
      Piece* previousPiece = board->getPiece(pUI->getPreviousPosition());
      Piece* currentPiece = board->getPiece(pUI->getSelectPosition());

      moves = previousPiece->getPossibleMoves(previousPiece->getPosition(), board, currentMoveIndex);

      int selectedPosition = pUI->getSelectPosition();


      if (moves->count(selectedPosition) > 0)  //I am not sure what this is checking?
      {
         Move move = moves->at(selectedPosition);
         board->executeMove(moves->at(selectedPosition));
         //board->move(pUI->getPreviousPosition(), selectedPositio);
         pUI->clearSelectPosition();
      }

   }
   //look into deleting moves 
   // Draw the Board
   //pUI->getPreviousPosition();
   board->display(pUI->getHoverPosition(), pUI->getSelectPosition());


}



/*********************************
 * Initialize the simulation and set it in motion
 *********************************/



#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32


int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
//   Position ptUpperRight;
//   ptUpperRight.setPixelsX(700.0);
//   ptUpperRight.setPixelsY(500.0);
//   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
//   Interface ui(0, NULL,
//      "Demo",   /* name on the window */
//      ptUpperRight);
//
   Interface ui("Chess");

   //   // Initialize the demo
   //   GameState demo(ptUpperRight);
   Board board;
   // set everything into action
//   ui.run(callBack, &demo);

   ui.run(callBack, &board);


   return 0;
}

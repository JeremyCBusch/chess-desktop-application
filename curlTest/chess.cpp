#define CURL_STATICLIB
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
//#include "gameSelector.h"
#include "curl/curl.h"
#include "serverConnector.h"
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
21. change get letter to an enumaration
22. set up not hopping over opposing colors



LETS FREAKING GO WE HAVE A KING IN CHECK

*/


//Note white is on top and goes first


void callBack(Interface* pUI, void* p)
{
   // Cast the Void Pointer to the game object
   Board* board = (Board*)p;


   unordered_map<int, Move> moves = unordered_map<int,Move>();
   int currentMoveIndex;


   if (pUI->getPreviousPosition() >= 0 && pUI->getPreviousPosition() < 64 && pUI->getSelectPosition() >= 0 && pUI->getSelectPosition() < 64)
   {
      currentMoveIndex = board->getCurrentMoveIndex();
      Piece* previousPiece = board->getPiece(pUI->getPreviousPosition());
      Piece* currentPiece = board->getPiece(pUI->getSelectPosition());

      moves = previousPiece->getPossibleMoves(previousPiece->getPosition(), board, currentMoveIndex, board->getPlayerWhitePieces());

      int selectedPosition = pUI->getSelectPosition();


      if (moves.count(selectedPosition) > 0)  
      {
         Move move = moves.at(selectedPosition);
         vector<char>* fakeBoard = board->getSimpleBoardCopy();

         board->executeMoveOnFakeBoard(move, fakeBoard);
         board->executeMove(moves.at(selectedPosition));
         //board->move(pUI->getPreviousPosition(), selectedPositio);
         pUI->clearSelectPosition();
         if (move.getisCheck())
             cout << "check\n";
      }

   }
   

   //look into deleting moves 
   board->display(pUI->getHoverPosition(), pUI->getSelectPosition());

   if (pUI->getSelectPosition() < 67 && pUI->getSelectPosition() > 63) {
       cout << "clicked on refresh?\n";
       pUI->clearSelectPosition();
       serverConnector::ping();
   }
}

//#define CURL_STATICLIB

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


#endif // !_WIN32

//int main(int argc, char** argv)

//{
int main() {

    //TODO: create a game selector
    // call the game selector from main
    // game selector will be ina  while loop until a game is create (join later)
    // print out a menu and be able to type craete, join, list
    // on create start a game
    

    bool isPlayerWhite;
    //isWhite = gameSelector::menuLoop();
    isPlayerWhite = true;


   Interface ui("Chess");

   //   // Initialize the demo
   //   GameState demo(ptUpperRight);
   Board board(isPlayerWhite);
   // set everything into action
//   ui.run(callBack, &demo);

   ui.run(callBack, &board);


   return 0;
}

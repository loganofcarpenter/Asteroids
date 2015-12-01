/*********************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * This file is provided as the instructor's "half" of the project.
 *
 * Please DO NOT provide, share, or distribute this file to students
 * of other sections or semesters.
 *********************************************************************/

#ifndef game_h
#define game_h


/****************************************
 * The game of Asteroids
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include "flyingObject.h"
#include "ship.h"
#include "rocks.h"
#include "bullet.h"

#include <list>
using namespace std;

#define INITIAL_ROCK_COUNT 5


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   // create the game
   Game(Point tl, Point br)
   {
      topLeft = tl;
      bottomRight = br;
      
      pShip = new Ship;
      
      for (int i = 0; i < INITIAL_ROCK_COUNT; i++)
      {
         Rock* pRock = new BigRock(getRandomPoint());
         rocks.push_back(pRock);
      }
   }
   
   // handle user input
   void handleInput(const Interface & ui);
   
   // advance the game
   void advance();
   
   // draw stuff
   void draw(const Interface & ui);
   
   static int getXMin() { return topLeft.getX(); }
   static int getXMax() { return bottomRight.getX(); }
   static int getYMin() { return bottomRight.getY(); }
   static int getYMax() { return topLeft.getY(); }
   
private:
   static Point topLeft;
   static Point bottomRight;
   
   Ship* pShip;
   
   list<Bullet*> bullets;
   list<Rock*> rocks;
   
   Point getRandomPoint() const;
   void checkForCollisions();
   void cleanUpZombies();
   
   bool isCollision(const FlyingObject &obj1, const FlyingObject &obj2) const;
   float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
   
};


#endif /* game_h */

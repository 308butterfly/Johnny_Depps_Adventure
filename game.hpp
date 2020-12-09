/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/9/2019
** Description:     Function implementation files for text adventure game engine
** Dependencies:     bathroom.hpp, bedroom.hpp, diningRoom.hpp, entrance.hpp,
**                   hallway.hpp, kitchen.hpp, livingRoom.hpp, space.hpp,
**                   pockets.hpp
\** File name:       game.hpp
*********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "bathroom.hpp"
#include "bedroom.hpp"
#include "diningRoom.hpp"
#include "entrance.hpp"
#include "hallway.hpp"
#include "kitchen.hpp"
#include "livingRoom.hpp"
#include "space.hpp"

#include "pockets.hpp"


class Game
{
    private:
        int timer;

        Space* bathroom;
        Space* bedroom;
        Space* diningRoom;
        Space* entrance;
        Space* hallway;
        Space* kitchen; 
        Space* livingRoom;

        Space* johnnyDeppPosition;
        Space* bombRoom;

        bool bombDetonated = false;
        bool isPlayAgain = false;

       // Pockets* pockets;

    public:
        Game();
        ~Game();

        void gameMenu();    
        void info();
        void adventure();
        void nextRooms();
        
        Space* placeBomb();

        Pockets* getPockets();

};

#endif

/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/30/2019
** Description:     A text adventure game
** Dependencies:    game.hpp                  
** File name:       textAdDrv.cpp
*********************************************************************************/

#include "game.hpp"

/*********************************************************************************
To run main put bathroom.hpp,  game.hpp, game.cpp, pockets.hpp,
pockets.cpp, space.hpp, space.cpp, textAdv.cpp, validate.hpp
validate.cpp into the same directory and use Makefile run with ./proj5
*********************************************************************************/


int main()
{
    srand(time(0));
    
    Game textAdv1;

    textAdv1.gameMenu();
    
    return 0;
}
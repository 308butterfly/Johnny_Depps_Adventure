/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The skeleton for all the rooms in Johnny Depp's house
** Dependencies:    pockets.hpp, validate.hpp                  
** File name:       space.hpp
*********************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>

#include "pockets.hpp"
#include "validate.hpp"

class Space
{
    protected:
        Space* up;
        Space* down;
        Space* left;
        Space* right;

        std::string roomName = "";

        bool hasBomb;
        bool turnedOnLights;

        Pockets* JohnnyDeppPockets;
    
    public:
        Space(std::string roomType);
        
        virtual ~Space();

        //Special thanks to Christopher Stevenson for guiding me on how to get the room to use
        //the inventory. I knew I needed a pointer to the container in the room, I didn't how
        //how to connect the container to items found in the room.  Turning the examine method
        //from void to Pocket* was the start I needed to solve the pooblem.  Thanks Chris.

        virtual Pockets* examine() = 0;

        void setUp(Space* s_up);
        void setDown(Space* s_down);
        void setLeft(Space* s_left);
        void setRight(Space* s_right);
        
        Space* getUp();
        Space* getDown();
        Space* getLeft();
        Space* getRight(); 

        Pockets* getPockets();
        
        void setPockets(Pockets* transferStuff);

        bool getHasBomb();
        bool getTurnedOnLights();

        void setHasBomb();
        void turnedOffLights();


        void bomb();

        std::string getName();
};

#endif

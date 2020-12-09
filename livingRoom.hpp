/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The living room to Johnny Depp's house
** Dependencies:    space.hpp                 
** File name:       livingRoom.hpp
*********************************************************************************/

#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP


#include "space.hpp"

class LivingRoom : public Space
{
    private:
        
    public:
        LivingRoom();
        ~LivingRoom();
        
        Pockets* examine();
};

#endif

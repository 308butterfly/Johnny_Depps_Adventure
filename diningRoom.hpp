/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The dining room in Johnny Depp's house
** Dependencies:    space.hpp                 
** File name:       diningRoom.hpp
*********************************************************************************/

#ifndef DININGROOM_HPP
#define DININGROOM_HPP


#include "space.hpp"

class DiningRoom : public Space
{
    private:
        
    public:
        DiningRoom();
        ~DiningRoom();
    
        Pockets* examine();
};

#endif

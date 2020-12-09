/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The hallway to Johnny Depps house
** Dependencies:    space.hpp                 
** File name:       hallway.hpp
*********************************************************************************/

#ifndef HALLWAY_HPP
#define HALLWAY_HPP


#include "space.hpp"

class Hallway : public Space
{
    private:
        
    public:
        Hallway();
        ~Hallway();
        
        Pockets* examine();
};

#endif

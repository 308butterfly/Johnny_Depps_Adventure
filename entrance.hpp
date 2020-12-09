/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The entrance to Johnny Depps house
** Dependencies:    space.hpp                 
** File name:       entrance.hpp
*********************************************************************************/

#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP

#include <iostream>

#include "space.hpp"

class Entrance : public Space
{
    private:
        
    public:
        Entrance();
        ~Entrance();
        
        Pockets* examine();
        void roomActions();
        
};

#endif

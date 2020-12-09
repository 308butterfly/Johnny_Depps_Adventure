/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     Bathroom in Johnny Depp's house
** Dependencies:    space.hpp                 
** File name:       bathroom.hpp
*********************************************************************************/

#ifndef BATHROOM_HPP
#define BATHROOM_HPP

#include <iostream>

#include "space.hpp"

class Bathroom : public Space
{
    private:
        
    public:
        Bathroom();
        ~Bathroom();

        void continueWashingHands();
        
        Pockets* examine();
};

#endif

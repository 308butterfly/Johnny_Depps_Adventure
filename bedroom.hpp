/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     Johnny Depp's Bedroom 
** Dependencies:    space.hpp                 
** File name:       bedroom.hpp
*********************************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP


#include "space.hpp"

class Bedroom : public Space
{
    private:
        
    public:
        Bedroom();
        ~Bedroom();
        
        Pockets* examine();
};

#endif

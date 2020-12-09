/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The kitchen to Johnny Depps house
** Dependencies:    space.hpp                 
** File name:       kitchen.hpp
*********************************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "space.hpp"

class Kitchen : public Space
{
    private:
        
    public:
        Kitchen();
        ~Kitchen();
        
        Pockets* examine();
};

#endif

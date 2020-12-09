/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   5/27/2019
** Description:     
** Inputs:                                              
** Dependencies:                      
** Returns:         
** File name:       space.hpp
*********************************************************************************/

#ifndef POCKETS_HPP
#define POCKETS_HPP

#include <iostream>
#include <cstring>

#include "validate.hpp"

struct Item
{
    Item* next;
    Item* prev;
    
    std::string itemName;
    
    Item(std::string iString, Item* iPrev = nullptr, Item* iNext = nullptr)
    {
        itemName = iString;
        prev = iPrev;
        next = iNext;
    }  
};

class Pockets
{
    private:
        int limit;
        int numOfItems;

    protected:
        Item* head;
        Item* current;

    public:
        Pockets();
        ~Pockets();

        const int getNumOfItems();

        bool hasItem(std::string itemName);
        //prints all nodez
        void showPockets();
        //delete a node
        void dropItem();

        void addItem(std::string itemName);
        void addToInv(std::string itemName);
        //deletes entirelist
        void deleteInv();
};

#endif

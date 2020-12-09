/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/9/2019
** Description:     The container for the text adventure game 
** Dependencies:    pockets.hpp                 
** File name:       pockets.cpp
*********************************************************************************/

#include "pockets.hpp"

using std::cout;
using std::endl;
using std::string;

Pockets::Pockets()
{
  head = nullptr;
  current = nullptr;
  limit = 5;
  numOfItems = 0;
}

Pockets::~Pockets()
{}

const int Pockets::getNumOfItems()
{
  return numOfItems;
}

/************************************************************************************
Name:        hasItem         
Called by:   Space::bomb(), 
Calls:       nothing
Passed:      string
Returns:     bool  
 
Description  uses string to find if an item in the container is already there.  If 
             the item is there method returns true.
************************************************************************************/

bool Pockets::hasItem(string thisItem)
{
  bool hasItemNow = false;

  if(head == nullptr)
  {
    hasItemNow = false;
  }

  else
  {
    current = head;

    do
    {
      if (current->itemName.compare(thisItem) == 0)
      {
        hasItemNow = true;
      }

      current = current->next;
    } while (current != head);
  }
  


  return hasItemNow;
}

/************************************************************************************
Name:       showPockets            
Called by:  Game::adventure
Calls:      nothing
Passed:     nothing
Returns:    void    
 
Description: displays the contents of a circular doubly linked list used as Johnny 
             Depps pockets
************************************************************************************/

void Pockets::showPockets()
{
  current = head;

  if (head == nullptr)
  {
    cout << "Johnny Depp's pockets are empty.\n\n";
  }

  else
  {
    cout << "Johnny Depp has ";

    do
    {
      cout << "a " << current->itemName;

      if (current->next->next == head)
      {
        if (current != current->next)
        {
          cout << " and ";
        }
      }

      else if (current->next != head)
      {
        cout << ", ";
      }

      current = current->next;

    } while (current != head);

    cout << " in his pockets.\n";
  }
}

/************************************************************************************
Name:        dropItem           
Called by:   Game::adventure
Calls:       intRangeCheck(validate.cpp)
Passed:      nothing
Returns:      void    
 
Description:  Removes item from Johnny Depp's pockets or deletes a node from the 
              doubly linked circular linked list. 
************************************************************************************/

void Pockets::dropItem()
{
  current = head;

  if (head == nullptr)
  {
    cout << "Johnny Depp's pockets are empty\n\n";
  }

  else
  {
    int counter = 0;

    std::string message = "What do you want to drop?\n"
                          "Select the item using the number next to it\n"
                          "Push '0' to exit\n";

    cout << "Things in Johnny Depp's pockets\n";
    
    //displays stuff in Johnny Depp's pockets
    do
    {
      cout << ++counter << "-" << current->itemName << endl;
      current = current->next;

    } while (current != head);

    int dropNumber = intRangeCheck(0, counter, message);

    if (dropNumber == 0)
    {
      return;
    }

    else
    {
      current = head;

      if (dropNumber == 1)
      {
        if (head->next == head)
        {
          delete head;
          head = nullptr;
        }

        else
        {
          head = head->next;
          head->prev = current->prev;
          current->prev->next = head;
          delete current;
        }

      }

      else
      {
        for (int i = 0; i < dropNumber - 2; i++)
        {
          current = current->next;
        }

        Item *temp = current->next;
        current->next = temp->next;
        delete temp;
      }
    }
    numOfItems--;
  }
}

/************************************************************************************
Name:        addItems            
Called by:   addToInv
Calls:       nothing
Passed:      string
Returns:      void    
 
Description:  Adds node to a circular doubly linked list or an item to Johnny Depp's
              pockets.
************************************************************************************/

void Pockets::addItem(string addItemName)
{
  if (numOfItems < limit)
  {
    //empty pocket
    if (head == nullptr)
    {
      head = new Item(addItemName);
      numOfItems++;
      head->next = head;
      head->prev = head;
    }

    //search if Johnny has the item
    else
    {
      bool flag = true;

      current = head;
      do
      {
        if (addItemName.compare(current->itemName) == 0)
        {
          cout << "Johnny Depp already has " << addItemName << endl << endl;;
          flag = false;
          return;
        }

        current = current->next;

      } while (current != head);

      //add item if pocket is not empty
      if (flag)
      {

        current = head->prev;
        Item *temp = new Item(addItemName);
        numOfItems++;
        temp->next = head;
        temp->prev = current;
        current->next = temp;
        head->prev = temp;
      }
    }
  }

  else
  {
    cout << "Johnny Depp's pockets are full.\n";
  }
  
}

/************************************************************************************
Name:         addToInv         
Called by:    All derived classes from Space::Examine()
Calls:        addItem, getInteger(validate.cpp)
Passed:       string
Returns:      void    
 
Description:   Uses a menu to ask if user want so add item to Johnny Depps pockets
************************************************************************************/

void Pockets::addToInv(std::string item)
{
    string choices[2] = {"Yes\n", "No\n"};

    string message1 = "Do you want the " + item + "?\n\n"
                  "1-" + choices[0] + 
                  "2-" + choices[1];
                    
    bool flag = true;

    while(flag)
    {
      int choice = getInteger(message1);
      
      enum choices {YES = 1, NO};

      switch (choice)
      {
        case YES:
        {
          addItem(item);
          flag = false;
          break;
        }

        case NO:
        {
          cout << "Item not added\n";
          flag = false;
          break;
        }
      }
    }

}

/************************************************************************************
Name:        deleteInv           
Called by:   Game::adventure
Calls:       nothing
Passed:      nothing
Returns:     void    
 
Description:  Deletes a circular doubly linked list or empties Johnny Depp's pockets
************************************************************************************/
void Pockets::deleteInv()
{
  if(head != nullptr)
  {
    current = head;

    while(current->next != head)
    {
      Item* garbage = current;
      current = current->next;
      delete garbage;
    }

    delete current;
  }
}
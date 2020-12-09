/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     Function implementation files for text adventure game engine
** Dependencies:    game.hpp                  
** File name:       game.cpp
*********************************************************************************/

#include <iostream>
#include <string>

#include "game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Game::Game() 
{
    //create the house
    bathroom = new Bathroom();
    bedroom = new Bedroom();
    diningRoom = new DiningRoom();
    entrance = new Entrance();
    hallway = new Hallway();
    kitchen = new Kitchen();
    livingRoom = new LivingRoom();

    bathroom->setLeft(kitchen);
    bathroom->setDown(hallway);

    bedroom->setDown(hallway);

    diningRoom->setRight(entrance);
    diningRoom->setUp(kitchen);

    entrance->setLeft(diningRoom);
    entrance->setRight(livingRoom);
    entrance->setUp(kitchen);

    hallway->setLeft(kitchen);
    hallway->setRight(bathroom);
    hallway->setUp(bedroom);
    hallway->setDown(livingRoom);

    kitchen->setLeft(diningRoom);
    kitchen->setRight(hallway);
    kitchen->setDown(entrance);

    livingRoom->setLeft(entrance);
    livingRoom->setUp(hallway);

}

Game::~Game()
{
    //delete the game area
    
    delete bathroom; 
    delete bedroom;
    delete diningRoom; 
    delete entrance;
    delete hallway;
    delete kitchen;
    delete livingRoom; 
    
}

/************************************************************************************
Name:        gameMenu          
Called by:   main
Calls:       info getInteger
Passed:      nothing
Returns:     void    
 
Description:  Menu for Johnny Depp's Adeventure.  The menu switches to ask the user
              to continue again after the initial run.
************************************************************************************/
void Game::gameMenu()
{
    string choices[2] = {"","Exit\n"};

    if(!isPlayAgain)
    {
        choices[0] = {"Play\n"};
    }

    else
    {
        choices[0] = {"Play again\n"};
    }

    string message1 = "\nJohnny Depp's Adventure\n"
                    "1-" + choices[0] +
                    "2-" + choices[1];

    bool flag = true;
    
    while(flag)
    {   
        int choice = getInteger(message1);  
         
        enum choiceTitles {PLAY = 1, EXIT};

        switch(choice)
        {
            case PLAY:
            {
                cout << choices[0] << endl;
                flag = false;
                isPlayAgain = true;
                adventure();
                
                break;
            }   

            case EXIT:
            {
                cout << choices[1] << endl;
                flag = false;
                break;
            }

            default:
            {
                cout << "Invalid choice\n";
                break;
            }
        }
    }
}

/************************************************************************************
Name:        info          
Called by:   gameMenu
Calls:       adventure
Passed:      nothing
Returns:     void    
 
Description:  Explains story of Johnny Depp's Adventure
************************************************************************************/

void Game::info()
{
    cout << "Johnny Depp's Ex Amber Heard is still crazy. \n";
    cout << "She put a bomb in the house\n";
    cout << "Find something to disarm the bomb\n";
    cout << "Find the bomb ...\n";
    cout << "Disarm the bomb ...\n";
    cout << "Make cool music with Slash ... \n";

    cout << "\nPress enter to continue\n";

    cin.get();
    
}

/************************************************************************************
Name:        nextRooms          
Called by:   adventure
Calls:       nothing
Passed:      nothing
Returns:     void    
 
Description:  Moves Johnny Depp's Adventure to a different room.
************************************************************************************/

void Game::nextRooms()
{
    if(entrance->getTurnedOnLights())
    {
        cout << "The bomb is in the " << bombRoom->getName() << endl << endl;
    }

    cout << "Left goes ";

    if(johnnyDeppPosition->getLeft() != nullptr)
    {
        cout << "to the " << johnnyDeppPosition->getLeft()->getName() << endl;
    }

    else 
    {
        cout << "nowhere\n";
    }

    cout << "Right goes ";

    if(johnnyDeppPosition->getRight() != nullptr)
    {
        cout << "to the " << johnnyDeppPosition->getRight()->getName() << endl;
    }

    else 
    {
        cout << "nowhere\n";
    }

    cout << "Up goes ";

    if(johnnyDeppPosition->getUp() != nullptr)
    {
        cout << "to the " << johnnyDeppPosition->getUp()->getName() << endl;
    }

    else 
    {
        cout << "nowhere\n";
    }

    cout << "Down goes ";

    if(johnnyDeppPosition->getDown() != nullptr)
    {
        cout << "to the " << johnnyDeppPosition->getDown()->getName() << endl;
    }

    else 
    {
        cout << "nowhere\n";
    }
}

/************************************************************************************
Name:        placeBomb          
Called by:   adventure
Calls:       IntNumberGen
Passed:      nothing
Returns:     void    
 
Description:  randomly determines where the bomb is placed in the house. 
************************************************************************************/

Space* Game::placeBomb()
{
    
    //this will not put the bomb in the entrance
    int whereBomb = IntNumberGen(0,5);

    enum rooms {BATH, BED, DIN, HALL, KIT, LIV};

    switch(whereBomb)
    {
        case BATH:
        {
            bathroom->setHasBomb();
            bombRoom = bathroom;
            break;
        }

        case BED:
        {   
            bedroom->setHasBomb();
            bombRoom = bedroom;
            break;
        }

        case DIN:
        {
            diningRoom->setHasBomb();
            bombRoom = diningRoom;
            break;
        }

        case HALL:
        {
            hallway->setHasBomb();
            bombRoom = hallway;
            break;
        }

        case KIT:
        {
            kitchen->setHasBomb();
            bombRoom = kitchen;
            break;
        }

        case LIV:
        {
            livingRoom->setHasBomb();
            bombRoom = livingRoom;
            break;
        }
    } 

    return bombRoom; 
}

/************************************************************************************
Name:        adventure
Called by:   main
Calls:       info, placebomb, nextRooms, gameMenu, Validate::getInteger
Passed:      nothing
Returns:     void    
 
Description:  Game engine for Johnny Depp's text adventure
************************************************************************************/

void Game::adventure()
{
    Pockets* johnnyDeppPockets = new Pockets;

    info();

    placeBomb();

    johnnyDeppPosition = entrance;
    //
    johnnyDeppPosition->setPockets(johnnyDeppPockets);

    for(timer = 25; timer > 0 && bombRoom->getHasBomb(); timer--)
    {

        string choices[8] = {"Go left\n", 
                            "Go right\n", 
                            "Go up\n", 
                            "Go down\n",
                            "Examine the room\n", 
                            "Check your pockets\n",
                            "Drop an item\n",
                            "Remember instructions\n"};

        string message1 = "\nJohnny Depp is in the " + johnnyDeppPosition->getName() + "\n"
                        "1-" + choices[0] + 
                        "2-" + choices[1] + 
                        "3-" + choices[2] + 
                        "4-" + choices[3] + 
                        "5-" + choices[4] +
                        "6-" + choices[5] +
                        "7-" + choices[6] +
                        "8-" + choices[7];

        bool flag = true;
    
        while(flag)
        {   
            cout << "The bomb has " << timer << " left on the timer\n\n";

            nextRooms();  

            int choice = getInteger(message1);  
            
            enum choiceTitles {LEFT = 1, RIGHT, UP, DOWN, EXAMINE, CHECK, DROP, INSTRU};

            switch(choice)
            {
                case LEFT:            
                {
                    cout << choices[0] << endl;

                    if(johnnyDeppPosition->getLeft() != nullptr)
                    {
                        johnnyDeppPosition->getLeft()->setPockets(johnnyDeppPosition->getPockets());
                        johnnyDeppPosition = johnnyDeppPosition->getLeft();
                        flag = false;
                    }

                    else
                    {
                        cout << "Can't go left\n";
                    }
                    
                    break;
                }  

                case RIGHT:            
                {
                    cout << choices[1] << endl;

                    if(johnnyDeppPosition->getRight() != nullptr)
                    {
                        johnnyDeppPosition->getRight()->setPockets(johnnyDeppPosition->getPockets());
                        johnnyDeppPosition = johnnyDeppPosition->getRight();
                        flag = false;
                    }

                    else
                    {
                        cout << "Can't go right\n";
                    }
                    
                    break;
                }   

                case UP:            
                {
                    cout << choices[2] << endl;

                    if(johnnyDeppPosition->getUp() != nullptr)
                    {
                        johnnyDeppPosition->getUp()->setPockets(johnnyDeppPosition->getPockets());
                        johnnyDeppPosition = johnnyDeppPosition->getUp();
                        flag = false;
                    }

                    else
                    {
                        cout << "Can't go up\n";
                    }
                    
                    break;
                }   

                case DOWN:            
                {
                    cout << choices[3] << endl;

                    if(johnnyDeppPosition->getDown() != nullptr)
                    {
                        johnnyDeppPosition->getDown()->setPockets(johnnyDeppPosition->getPockets());
                        johnnyDeppPosition = johnnyDeppPosition->getDown();
                        flag = false;
                    }

                    else
                    {
                        cout << "Can't go down\n";
                    }
                    
                    break;
                }    

                case EXAMINE:
                {
                    cout << choices[4] << endl;
                    johnnyDeppPosition->examine();
                    flag = false;
                    break;
                }

                case CHECK:
                {
                    cout << choices[5] << endl;
                    johnnyDeppPosition->getPockets()->showPockets();
                    flag = false;
                    break;
                }

                case DROP:
                {
                    cout << choices[6] << endl;
                    johnnyDeppPosition->getPockets()->dropItem();
                    break;
                }

                case INSTRU:
                {
                    cout << choices[7] << endl;
                    info();
                    break;
                }

                default:
                {
                    cout << "Invalid choice\n";
                    break;
                }
            }
        }  

    }

    if(timer > 0)
    {
        cout << "\n\n\nJohnny Depp stopped the bomb\n\n\n";
        cout << "He goes WOO HOO!!! like Homer Simpson\n";

        if(johnnyDeppPosition->getPockets()->hasItem("guitar"))
        {
            cout << "And takes his guitar to find Slash to rock out.\n";
        }

        else
        {
            cout << "But, now needs to find his guitar to rock out with Slash.\n";
        }
        
        cout << "\n\n\n**** FIN ****\n\n\n";
    }

    else
    {
        cout << "\n\n\nTHE BOMB HAS DETONATED!\n\n\n";
        cout << "Johnny Depp had a really bad day today.\n";
        cout << "\n\n\n**** GAME OVER ****\n\n\n";
    }

    //clean up for next run;
    johnnyDeppPosition->getPockets()->deleteInv();

    delete johnnyDeppPockets;

    entrance->turnedOffLights();
    //
    
    gameMenu();
}

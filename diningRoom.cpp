/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The dining room in Johnny Depp's house
** Dependencies:    space.hpp                 
** File name:       diningRoom.hpp
*********************************************************************************/

#include "diningRoom.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

DiningRoom::DiningRoom() : Space("dining room")
{}

DiningRoom::~DiningRoom()
{}

/************************************************************************************
Name:        DiningRoom::examine
Called by:   Game::adventure
Calls:       getInteger (validate.cpp), IntNumGen(validate.cpp), continueWashingHands,
             bomb, addToInv
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
 
Description: A place where Johnny Depp can look at a painting, search a table and 
             chairs, look out a picture window or pet his pet peacock.  
************************************************************************************/
Pockets* DiningRoom::examine()
{
    if(hasBomb)
    {
        cout << "You really hear the sound of a ticking bomb\n";
    }

    cout << "Johnny Depp looks around his dining room\n";
    cout << "He sees a painting\n";
    cout << "He sees a long table with chairs\n";
    cout << "He can see out a picture window\n";
    cout << "He sees his pet peacock walking around\n";
    cout << "Press enter to continue\n\n";

    cin.get();

    string choices[5] = {"Look at the painting\n",
                        "Check the table and chairs\n", 
                        "Look out the picture window\n", 
                        "Walk up to the peacock\n",
                        "Stop examining the dining room\n"};

    string message1 = "\nWhat does does Johnny Depp do?\n"
                    "1-" + choices[0] +
                    "2-" + choices[1] +
                    "3-" + choices[2] +
                    "4-" + choices[3] +
                    "5-" + choices[4];

    bool flag = true;

    while(flag)
    {
        int choice = getInteger(message1);  
        
        enum choiceTitles {PAINTING = 1, TABLE, WINDOW, PEACOCK, DOOR};

        switch(choice)
        {
            case PAINTING:
            {
                cout << choices[0] << endl;
                cout << "You see the painting of Slash\n";
                cout << "It is pretty sweet.\n";

                if(hasBomb)
                {
                    cout << "But you hear the ticking very clearly\n";
                    cout << "You look behind the painting to find\n";
                    cout << "THE BOMB!!!";
                    bomb();
                    if(!hasBomb)
                    {
                        flag = false;
                    }

                }
                
                break;
            }

            case TABLE:
            {
                cout << choices[1] << endl;
                cout << "Johnny Depp goes over to the tables and chairs.\n";
                cout << "He looks underneath and sees....";
                cout << "AMBER WITH A KNIFE...\n";
                cout << "Just kidding\n";
                cout << "Checking the top of the table Johnny sees a teapot.\n";

                JohnnyDeppPockets->addToInv("teapot");


                break;
            }

            case WINDOW:
            {
                cout << choices[2] << endl;
                cout << "Johnny Depp looks out the big picture window.\n";
                cout << "He sees the grass blowing in the wind\n";
                cout << "He sees the waves gently crashing on to the shore\n";
                
                if(hasBomb)
                {
                    cout << "He hears the ticking of the bomb.\n";
                }

                break;
            }

            case PEACOCK:
            {
                cout << choices[3] << endl;
                cout << "Johnny Depp pets his peacock.\n";
                cout << "The peacock seems happy";

                if(hasBomb)
                {
                    cout << " even though there is a bomb in the house.\n";
                    cout << "The peacock seems to be pointing to the top of the table\n";
                    cout << "Does it know something??\n";
                }

                else
                {
                    cout << ".\n";
                }
                
                break;
            }

            case DOOR:
            {
                cout << choices[4] << endl;
                cout << "Johnny Depp stops examining the dining room.\n";
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
    
    return JohnnyDeppPockets;
}

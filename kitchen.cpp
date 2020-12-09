/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The kitchen to Johnny Depps house
** Dependencies:    kitchen.hpp                 
** File name:       kitchen.cpp
*********************************************************************************/

#include "kitchen.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Kitchen::Kitchen() : Space("kitchen")
{}

Kitchen::~Kitchen()
{}

/************************************************************************************
Name:        Kitchen::examine           
Called by:   Game::adventure
Calls:       getInteger (validate.cpp), bomb, addToInv
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
 
Description
************************************************************************************/
Pockets* Kitchen::examine()
{
    if(hasBomb)
    {
        cout << "You really hear the sound of a ticking bomb.\n";
    }

    cout << "Johnny Depp looks around his kitchen\n";
    cout << "There is a refridgerator\n";
    cout << "There is a table and chairs\n";
    cout << "He notices that some cupboards are open\n";
    cout << "He can smell the trash\n";

    cout << "Press enter to continue\n";

    cin.get();

    string choices[5] = {"Check the fridge.\n",
                        "Look under the table.\n", 
                        "Check the cupboards.\n", 
                        "Check the trash.\n",
                        "Stop examining.\n"};

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
        
        enum choiceTitles {FRIDGE = 1, TABLE, CUP, TRASH, LEAVE};

        switch(choice)
        {
            case FRIDGE:
            {
                cout << choices[0] << endl;
                cout << "Johnny Depp goes to the fridge\n";
                cout << "He opens the fridge and sees ";
                
                if(hasBomb)
                {
                    cout << "THE BOMB!!!!\n";
                    bomb();
                    
                    if(!hasBomb)
                    {
                        flag = false;
                    }
                }

                else
                {
                    cout << "nothing but a bottle of mustard\n";
                    
                    JohnnyDeppPockets->addToInv("bottle of mustard");
                }
                
                break;
            }

            case TABLE:
            {
                cout << choices[1] << endl;
                cout << "Johnny Depp looks under the table and sees\n";
                cout << "AMBER WITH A KNIFE!!!\n";
                cout << "Just kidding\n";
                cout << "But, Johnny Depp sees a cheese puff.\n";
                
                JohnnyDeppPockets->addToInv("chesse puff");
                
                break;
            }

            case CUP:
            {
                cout << choices[2] << endl;
                cout << "Johnny Depp looks through the cupboards and finds a teapot\n";
                
                JohnnyDeppPockets->addToInv("teapot");
                
                break;
            }

            case TRASH:
            {
                cout << choices[3] << endl;
                cout << "Johnny Depp checks out why the trash is stinky.\n";
                cout << "Amber pooped in the trash can.\n";
                cout << "I guess she left two bombs in the house.\n";
                
                break;
            }

            case LEAVE:
            {
                cout << choices[4] << endl;
                flag = false;
                cout << "Johnny Depp stops examining the kitchen.\n";
                
                break;
            }

            default:
            {
                cout << "Invalid choice.\n";
                break;
            }
        }
    }

    return JohnnyDeppPockets;
}



/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The entrance to Johnny Depps house
** Dependencies:    entrance.hpp                 
** File name:       entrance.cpp
*********************************************************************************/

#include "entrance.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


Entrance::Entrance() : Space("Entrance")
{}

Entrance::~Entrance()
{}

/************************************************************************************
Name:        Entrance::examine            
Called by:   Game::adventure
Calls:       roomActions
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
 
Description: A place where Johnny Depp can pick up his guitar and explore the entrance
************************************************************************************/
Pockets* Entrance::examine()
{
    cout << "It is the entrance\n";
    cout << "He hears the faint sound of a ticking bomb ... \n";
    cout << "... but where is it?\n";
    cout << "When the staff heard about the bomb in the house, they left\n";
    cout << "He doesn't blame them.\n";

    cout << "He still sees the guitar, that Slash gave him, proudly displayed\n";
    
    JohnnyDeppPockets->addToInv("guitar");

    cout << "His cat comes over to him.  Cats don't care if the house has a bomb.\n";
    
    roomActions();


    return JohnnyDeppPockets;
}

/************************************************************************************
Name:       roomActions            
Called by:  Entrance::examine
Called by:   Game::adventure
Calls:       getInteger (validate.cpp), IntNumGen(validate.cpp), continueWashingHands,
             addToInv
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
  
 
Description: Johnny Depp can wipe off his, shoes, turn on the house lights, pet his
             cat, check inside the entrance closet.  
************************************************************************************/
void Entrance::roomActions()
{
    string choices[5] = {"Wipe off his shoes\n",
                        "Turn the lights on or off\n", 
                        "Pet his cat\n", 
                        "Check the inside of the closet\n",
                        "Stop examining the entrance.\n"};

    string message1 = "\nWhat does Johnny Depp do?\n"
                    "1-" + choices[0] +
                    "2-" + choices[1] +
                    "3-" + choices[2] +
                    "4-" + choices[3] +
                    "5-" + choices[4];

    bool flag = true;

    while(flag)
    {
        int choice = getInteger(message1);  
        
        enum choiceTitles {SHOES = 1, LIGHT, CAT, CLOSET, LEAVE};

        switch(choice)
        {
            case SHOES:
            {   
                cout << choices[0] << endl;
                cout << "Johnny tries to wipe off his shoes.\n";
                cout << "Wouldn't it be funny if the rug was a picture of Amber?\n";

                break;
            }

            case LIGHT:
            {
                cout << choices[1] << endl;
                
                if(!turnedOnLights)
                {
                    cout << "Johnny Depp sees the house is dark.\n"; 
                    cout << "He turns on the lights.\n";
                    cout << "Ahhhh, much better\n";
                    turnedOnLights = true;
                }
                
                else
                {
                    cout << "Johnny Depp thinks turning on the lights doesn't solve anything.\n";
                    cout << "The lights are turned off.\n";
                    turnedOnLights = false;
                }
                                
                break;
            }

            case CAT:
            {
                cout << choices[2] << endl;
                cout << "Johnny Depp pets his cat\n";
                cout << "It seems happy\n";

                break;
            }

            case CLOSET:
            {
                cout << choices[3] << endl;

                cout << "Johnny Depp looks inside the closet\n";
                cout << "He see a lot of the funny hats he worn in his movies\n";
                cout << "He is surprised that he didn't find Tom Kruse in the closet\n";
                
                break;
            }

            case LEAVE:
            {
                cout << choices[4] << endl;
                cout << "Johnny Depp stops examining the hallway.\n";
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


/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     Johnny Depp's Bedroom 
** Dependencies:    bedroom.hpp                 
** File name:       bedroom.cpp
*********************************************************************************/

#include "bedroom.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Bedroom::Bedroom() : Space("bedroom")
{}

Bedroom::~Bedroom()
{}

/************************************************************************************
Name:        Bedroom::examine          
Called by:   Game::adventure
Calls:       getInteger (validate.cpp), IntNumGen(validate.cpp), continueWashingHands,
             bomb, addToInv
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
 
Description  A place where Johnny Depp can check his bedroom closet, look through a
             dressor, search his bed, and look through the nightstand.
************************************************************************************/
Pockets* Bedroom::examine()
{
    if(hasBomb)
    {
        cout << "You really hear the sound of a ticking bomb\n";
    }

    cout << "Johnny Depp looks around his bedroom.\n";
    cout << "He sees his massive walk-in closet\n";
    cout << "It is a lot emptier since Amber left\n";
    cout << "He sees his dresser.\n";
    cout << "He sees his California king bed\n";
    cout << "He hopes there is no Amber *COUGH* *COUGH* monster under it\n";
    cout << "He sees his nightstand\n";
    cout << "Maybe something good is in it\n";

    cout << "Press Enter to continue\n\n";
    
    cin.get();

    string choices[5] = {"Check the walk-in closet\n",
                        "Look through the dresser\n", 
                        "Search under the bed\n", 
                        "Look through the nightstand\n", 
                        "Stop examining the bedroom\n"};

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

        enum choiceTitles {CLOSET = 1, DRESSOR, BED, NIGHTSTAND, DOOR};

        switch(choice)
        {
            case CLOSET:
            {
                cout << choices[0] << endl;
                cout << "Johnny Depp looks through his closet \n";
                cout << "He has a lot of clothes.\n";
                cout << "He sees his costume from Pirates of the Caribbean.\n";
                
                JohnnyDeppPockets->addToInv("pirate hat");
                JohnnyDeppPockets->addToInv("pirate sword");
                

                break;
            }

            case DRESSOR:
            {
                cout << choices[1] << endl;
                cout << "Johnny Depp looks through the dressor and finds ";

                int happening = IntNumberGen(0,3);

                enum dressorStuff {PHONE, SHIRTS, JEWELRY, PASSPORT};

                switch(happening)
                {
                    case PHONE:
                    {
                        cout << "his phone.\n";
                        JohnnyDeppPockets->addToInv("phone");

                        break;
                    }

                    case SHIRTS:
                    {
                        cout << "shirts\n";
                        JohnnyDeppPockets->addToInv("shirt");

                        break;
                    }

                    case JEWELRY:
                    {
                        cout << "jewelry.\n";
                        JohnnyDeppPockets->addToInv("piece of jewelry");

                        break;
                    }

                    case PASSPORT:
                    {
                        cout << "his passport\n";
                        JohnnyDeppPockets->addToInv("passport");
                        break;
                    }
                }

                break;
            }

            case BED:
            {
                cout << choices[2] << endl;
                cout << "Johnny Depp looks under the bed and finds....";
                
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
                    cout << "AMBER WITH A KNIFE!!!!\n";
                    cout << "just kidding...\n";
                }
                
                break;
            }

            case NIGHTSTAND:
            {
                cout << choices[3] << endl;
                cout << "Johnny Depp looks through the nightstand and finds ";

                int happening = IntNumberGen(0,3);

                enum nightStStanduff {GLASSES, DRUGS, MONEY, ZIPPO};

                switch(happening)
                {
                    case GLASSES:
                    {
                        cout << "his glasses.\n";
                        JohnnyDeppPockets->addToInv("pair of glasses");

                        break;
                    }

                    case DRUGS:
                    {
                        cout << "DRUGS!!!! THE GOOD KIND!!\n";
                        JohnnyDeppPockets->addToInv("drugs");

                        break;
                    }

                    case MONEY:
                    {
                        cout << "money.\n";
                        JohnnyDeppPockets->addToInv("wad of money");

                        break;
                    }

                    case ZIPPO:
                    {
                        cout << "his Zippo\n";
                        JohnnyDeppPockets->addToInv("Zippo");
                        break;
                    }
                }

                break;

            }

            case DOOR:
            {
                cout << choices[4] << endl;
                cout << "Johnny Depp stops examining the bedroom.\n";
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


/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The hallway to Johnny Depps house
** Dependencies:    hallyway.hpp                 
** File name:       hallway.cpp
*********************************************************************************/

#include "hallway.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Hallway::Hallway() : Space("hallway")
{}

Hallway::~Hallway()
{}

/************************************************************************************
Name:        Hallway::examine            
Called by:   Game::adventure
Calls:       getInteger (validate.cpp), bomb, addToInv
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
Description  A place where Johnny Depp looks at pictures on the wall, his movie 
             memorabilia, pet his cat (again??), and check out a closet.
************************************************************************************/
Pockets* Hallway::examine()
{
    if(hasBomb)
    {
        cout << "You really hear the sound of a ticking bomb\n";
    }


    cout << "Johnny Depp looks around the hallway\n";
    cout << "It is open and it echos with his footsteps";

    if(hasBomb)
    {
        cout << " and the sounds of a ticking bomb\n";
    }

    else 
    {
        cout << "\n";
    }

    cout << "He sees pictures on the wall\n";
    cout << "He sees posters from his movies\n";
    cout << "He sees his pet cat\n";
    cout << "He sees a closet\n";

    cout << "Press enter to continue\n";

    cin.get();

    string choices[5] = {"Look at the pictures\n",
                        "Look at the posters\n", 
                        "Pet his cat\n", 
                        "Check the inside of the closet\n",
                        "Stop examining the hallway.\n"};

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
        
        enum choiceTitles {PICT = 1, POSTER, CAT, CLOSET, LEAVE};

        switch(choice)
        {
            case PICT:
            {   
                cout << choices[0] << endl;
                cout << "Johnny looks at the pictures on the wall.\n";
                cout << "They are of friends and family.... and Slash\n";
                cout << "He thinks that he has had a pretty sweet life\n";

                break;
            }

            case POSTER:
            {
                cout << choices[1] << endl;
                cout << "Johnny Depp looks at all of his momentos from the \n"; 
                cout << "movies he has been in.\n";
                cout << "He notices that he has been wearing funny hats\n";
                cout << "in all of his movies ever since he was in \n";
                cout << "Alice in Wonderland\n";
                
                cout << "He sees his scissor-hands from Edward Scissor-hands\n";
                
                JohnnyDeppPockets->addToInv("pair of scissor-hands");

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

                if(hasBomb)
                {
                    cout << "The ticking is extremely loud\n";
                    cout << "IT IS THE BOMB!!\n";
                    bomb();
                    if(!hasBomb)
                    {
                        flag = false;
                    }
                }
                else
                {
                    cout << "IT'S TOM KRUSE!!??\n";
                    cout << "What is he doing in the closet??\n";
                    cout << "Johnny Depp tells Tom Kruse to get out of the closet\n";
                    cout << "But, he doesn't\n";
                }
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

    return JohnnyDeppPockets;
}

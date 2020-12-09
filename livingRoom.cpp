/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The living room to Johnny Depp's house
** Dependencies:    livingRoom.hpp                 
** File name:       livingRoom.cpp
*********************************************************************************/

#include "livingRoom.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

LivingRoom::LivingRoom() : Space("living room")
{}

LivingRoom::~LivingRoom()
{}

/************************************************************************************
Name:        LivingRoom::examine
Called by:   Game::adventure
Calls:       getInteger (validate.cpp), IntNumGen(validate.cpp), bomb, addToInv
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
Description  A place where Johnny Depp can watch tv, sit in his couch, look at his 
             coffee table, or look out the window.  
************************************************************************************/

Pockets* LivingRoom::examine()
{
    if(hasBomb)
    {
        cout << "You really hear the sound of a ticking bomb\n";
    }

    cout << "Johnny Depp looks around his living room\n";
    cout << "He sees his Lazyboy\n";
    cout << "He sees his couch\n";
    cout << "He sees his coffee table\n";
    cout << "He sees the sun shining through the windows\n";

    cout << "Press enter to continue\n";

    cin.get();

    string choices[5] = {"Sit in the chair\n",
                        "Sit on the couch\n", 
                        "Check out the coffee table\n", 
                        "Look out the windows\n",
                        "Stop examining the room\n"};

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
        
        enum choiceTitles {CHAIR = 1, SOFA, COFFEE, WINDOWS, LEAVE};

        switch(choice)
        {
            case CHAIR:
            {
                cout << choices[0] << endl;
                cout << "Johnny Depp sits in the chair. \n";
                cout << "He turns on the tv and watches ";

                int show = IntNumberGen(0,4);

                enum tv{COPS, RANGO, BATMAN, MYTH, CART};

                switch (show)
                {
                    case COPS:
                    {
                        cout << "COPS\n";
                        break;
                    }

                    case RANGO:
                    {
                        cout << "Rango\n";
                        break;
                    }

                    case BATMAN:
                    {
                        cout << "Batman\n";
                        cout << "The campy one with Adam West\n";
                        break;
                    }

                    case MYTH:
                    {
                        cout << "Mythbusters\n";
                        cout << "He really admires Jamie's mustash\n";
                        break;
                    }

                    case CART:
                    {
                        cout << "Looney Tunes\n";
                        cout << "Than roadrunner and coyote\n";
                        break;
                    }
                }
                break;
            }

            case SOFA:
            {
                cout << choices[1] << endl;
                cout << "Johnny Depp sits on the sofa and digs in the cushions\n";
                cout << "He finds ";

                if(hasBomb)
                {
                    cout << "THE BOMB!!!\n";
                    bomb();
                    
                    if(!hasBomb)
                    {
                        flag = false;
                    }
                }

                else
                {
                    cout << IntNumberGen(0,100) << "cents\n";
                }
                
                break;
            }

            case COFFEE:
            {   
                cout << choices[2] << endl;
                
                cout << "Johnny Depp checks the coffee table.\n";
                cout << "He sees bubble gum on the top.\n";
                
                JohnnyDeppPockets->addToInv("bubble gum");
                
                break;
            }

            case WINDOWS:
            {
                cout << choices[3] << endl;
                
                cout << "Johnny Depp looks out the window.\n";
                cout << "He sees that it is a nice sunny day.\n";

                if(hasBomb)
                {
                    cout << "He is thinking why he has to waste time\n";
                    cout << "looking for a bomb\n";
                }
                break;
            }

            case LEAVE:
            {
                cout << choices[4] << endl;
                cout << "Johnny Depp stops examining the living room.\n";
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



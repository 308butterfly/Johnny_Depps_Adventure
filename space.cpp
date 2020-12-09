/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     The skeleton for all the rooms in Johnny Depp's house
** Dependencies:    space.hpp                  
** File name:       space.cpp
*********************************************************************************/

#include "space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Space::Space(std::string roomType)
    :roomName(roomType)
{
    up = nullptr;
    down = nullptr;
    left = nullptr;
    right = nullptr;

    JohnnyDeppPockets = nullptr;
    
    this->turnedOnLights = false;
    this->hasBomb = false;
}

Space::~Space()
{}

//setters for position
void Space::setUp(Space* s_up)
{
    up = s_up;
}

void Space::setDown(Space* s_down)
{
    down = s_down;
}

void Space::setLeft(Space* s_left)
{
    left = s_left;
}

void Space::setRight(Space* s_right)
{
    right = s_right;
}

//gives room bomb
void Space::setHasBomb()
{
    hasBomb = true;
} 

void Space::turnedOffLights()
{
    turnedOnLights = false;
}

//getters
Space* Space::getUp()
{
    return up;
}

Space* Space::getDown()
{
    return down;
}

Space* Space::getLeft()
{
    return left;
}

Space* Space::getRight()
{
    return right;
}

//
string Space::getName()
{
    return roomName;
}

//
bool Space::getHasBomb()
{
    return hasBomb;
}

bool Space::getTurnedOnLights()
{
    return turnedOnLights;
}

Pockets* Space::getPockets()
{
    return JohnnyDeppPockets;
}

//transfer contents of Johnny Depp's pockets from room to room. 
void Space::setPockets(Pockets* stuffTransfer)
{
    JohnnyDeppPockets = stuffTransfer;
}

/************************************************************************************
Name:        bomb            
Called by:   examine
Calls:       getInteger (validate.cpp)
Passed:      nothing
Returns:     void    
 
Description: Johnny Depp has a list of choices of how to disarm the bomb.  The choice
             that succeeds is dependent on which item he has in his pockets.  If he 
             can not disarm the bomb he can move away from the bomb. 
************************************************************************************/

void Space::bomb()
{
    cout << "It's ticking .....\n";
    cout << "But, Johnny Depp keeps his cool\n";
    cout << "Is there a way to disarm the bomb?\n\n";

    string choices[6] = {"Cut a wire\n", 
                        "Rock out on your guitar\n", 
                        "Kick it out a window\n", 
                        "Pour tea over it\n",
                        "Chew gum\n",
                        "Move away from the bomb\n"};

    string message1 = "What do you do?\n\n"
                    "1-" + choices[0] + 
                    "2-" + choices[1] + 
                    "3-" + choices[2] + 
                    "4-" + choices[3] +
                    "5-" + choices[4] +
                    "6-" + choices[5];
                
    bool flag = true;

    while(flag)
    {   

        int choice = getInteger(message1);  
        
        enum choiceTitles {CUT = 1, ROCK, KICK, TEA, GUM, LEAVE};

        switch(choice)
        {
            case CUT:            
            {
                cout << choices[0] << endl;

                if(JohnnyDeppPockets->hasItem("pair of scissor-hands") || 
                   JohnnyDeppPockets->hasItem("pirate sword"))
                {
                    cout << "Johnny Depp looks at the bomb wires\n";
                    cout << "He knows he has to cut the blue wire\n";
                    cout << "BUT ALL THE WIRES ARE BLUE!!!\n";
                    cout << "So, he cuts all the blue wires\n";
                    cout << "The bomb stops\n";
                    cout << "The day is saved!!!\n\n";
                    hasBomb = false;
                    flag = false;
                }

                else
                {
                    cout << "Johnny Depp needs something to cut the wires.\n";
                }
                
                break;
            }    

            case ROCK:            
            {
                cout << choices[1] << endl;

                if(JohnnyDeppPockets->hasItem("guitar"))
                {
                    cout << "Johnny Depp starts playing his guitar\n";
                    cout << "Alice Cooper shows up with his mic and starts singing!!!\n";
                    cout << "Joe Perry shows up and starts playing his guitar!!!!\n";
                    cout << "Duff McKagen appears and starts pounding on the drums\n";
                    cout << "AND A CLOUD OF SMOKE APPEARS...\n";
                    cout << "Slash walks through it with his guitar...\n ";
                    cout << "He starts to rip his solo.\n";
                    cout << "This bomb is getting the best personel consert of its life\n";
                    cout << "The bomb starts to glow....\n";
                    cout << "It explodes into a peacock array of pyrotechnics\n";
                    cout << "It is so beautiful that Dwayne \"THE ROCK\" Johnson starts crying like a baby.\n";

                    hasBomb = false;
                    flag = false;
            
                }

                else
                {
                    cout << "Johnny Depp can't rock out without his guitar.\n";
                }
                                
                break;
            }   

            case KICK:            
            {
                cout << choices[2] << endl;

                if(JohnnyDeppPockets->hasItem("pirate hat"))
                {
                    cout << "Johnny Depp puts on his pirate hat.\n";
                    cout << "A chadelier appears in the room.\n";
                    cout << "He jumps onto the chandelier and starts to spin around\n";
                    cout << "He gains enough momentum and kicks the bomb out the window\n";
                    cout << "The bomb lands by Bill O'Reily, Donald Trump and Amber Heard\n";
                    cout << "It explodes and covers them with super sticky glue\n";  
                    cout << "They all just look absolutely ridiculous\n\n";
                    cout << "Johnny Depp appears above them on his balcony and says\n"; 
                    cout << "\"And you will always remember this, as the day,\n";
                    cout << "You almost caught Captain Jack Sparrow.\"\n";

                    hasBomb = false;
                    flag = false;
                }

                else
                {
                    cout << "Johnny Depp kicks the bomb really hard.\n";
                    cout << "His foot hurts.\n";
                }
                
                break;
            }

            case TEA:
            {
                cout << choices[3] << endl;

                if(JohnnyDeppPockets->hasItem("teapot"))
                {
                    cout << "Johnny Depp takes out the teapot.\n";
                    cout << "It is the one from ALICE THROUGH THE LOOKING GLASS.\n";
                    cout << "The teapot says \"POUR ME\" ... but there is no tea in it.\n";
                    cout << "Suddenly the teapot emits steam and mysteriously fills up.\n";
                    cout << "Johnny Depp pours the tea over the bomb...\n";
                    cout << "It starts to shrink down ... down ... and down to a dot.\n";
                    cout << "Then the bomb gives the tinniest little \"POP!\"";
                    cout << "No more bomb.\n";

                    hasBomb = false;
                    flag = false;
                }

                else
                {
                    cout << "Johnny Depp doesn't have a teapot.\n";
                    cout << "How does a teapot stop a bomb.\n";
                    cout << "Only someone as mad as a hatter would try that.\n";
                }
                
                break;
            }

            case GUM:
            {
                cout << choices[4] << endl;

                if(JohnnyDeppPockets->hasItem("bubble gum"))
                {
                    cout << "Johnny Depp chews the bubble gum.\n";
                    cout << "Suddenly he hears the Oompa Loompa song.....\n";
                    cout << "Four Oompa Loompas come into the room.\n";
                    cout << "They circle the bomb singing their song.\n";
                    cout << "They are not really creative with their song.\n";
                    cout << "Johnny Depp hears them rhyme bomb with Tom Arnold??...huh??\n";
                    cout << "They must have sent the C list Oompa Loompas.\n";
                    cout << "Johnny Depp thinks about how old the gum is he is chewing.\n";
                    cout << "The Oompa Loompas carry the bomb out of the house.\n";
                    cout << "No more bomb.\n";

                    hasBomb = false;
                    flag = false;
                }

                else
                {
                    cout << "Johnny Depp doesn't have bubble gum\n";
                    cout << "Why would someone chew gum when there is a bomb ticking?\n";
                }

                break;
            }    

            case LEAVE:
            {
                cout << choices[5] << endl;
                cout << "Johnny Depp moves away from the bomb\n";
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




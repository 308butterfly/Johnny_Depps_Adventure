/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   6/10/2019
** Description:     Bathroom in Johnny Depp's house
** Dependencies:    bathroom.hpp                 
** File name:       bathroom.hpp
*********************************************************************************/

#include "bathroom.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


Bathroom::Bathroom() : Space("bathroom")
{}

Bathroom::~Bathroom()
{}

/************************************************************************************
Name:        Bathroom::examine           
Called by:   Game::adventure
Calls:       getInteger (validate.cpp), IntNumGen(validate.cpp), continueWashingHands,
             bomb, addToInv
Passed:      nothing
Returns:     pointer to Johnny Depp's pockets  
 
Description:  A place where Johnny Depp can swim, use the toilet, wash his hands,
              check the medicine cabinet, and check the bathroom closet.  
************************************************************************************/
Pockets* Bathroom::examine()
{   
    if(hasBomb)
    {
        cout << "You really hear the sound of a ticking bomb\n";
    }

    cout << "Johnny Depp looks around his bathroom.\n";
    cout << "It has a waterfall.  A big waterfall that flows into a pool.\n";
    cout << "You could swim in that thing.\n";
    cout << "Maybe there is a mermaid in the pool, but there is only one\n";
    cout << "to find out.\n";

    cout << "Press Enter to continue\n\n";

    cin.get();

    string choices[6] = {"Go for a swim\n",
                        "Use the toilet\n", 
                        "Washes his hands\n", 
                        "Search the medicine cabinet\n",
                        "Search the bathroom closet\n", 
                        "stop examining\n"};

    string message1 = "\nWhat does does Johnny Depp do?\n"
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
        
        enum choiceTitles {SWIM = 1, TOILET, WASH_HANDS, MEDICINE_CABINET,CLOSET, DOOR};

        switch(choice)
        {
            case SWIM:            
            {
                cout << choices[0] << endl;

                cout << "Johnny Depp swims in his waterfall in his bathroom\n";
                cout << "He sees a ";
                
                int happening = IntNumberGen(0,3);

                enum saw {MERMAID, FISH, SLASH, NOTHING };
                
                switch(happening)
                {
                    case MERMAID:
                    {
                        cout << "mermaid\n";
                        break;
                    }

                    case FISH: 
                    {
                        cout << "fish\n";
                        break;
                    }

                    case SLASH:
                    {
                        cout << "SLASH!!!???\n";
                        break;
                    }

                    case NOTHING:
                    {
                        cout << "nothing but beautiful water\n";
                        break;
                    }
                }
                
                break;
            }  

            case TOILET:            
            {
                cout << choices[1] << endl;
                cout << "Johhny Depp sits on the toilet\n";
                cout << "He thinks about shooting Hunter S. Thompson's ashes out of a cannon\n";
                cout << "He thinks he might have to do it with Slash's too someday\n";
                
                break;
            }   

            case WASH_HANDS:            
            {
                cout << choices[2] << endl;

                cout << "Johnny Depp washes his hands in the sink\n";
                continueWashingHands();

                break;
            }   

            case MEDICINE_CABINET:            
            {
                cout << choices[3] << endl;
                cout << "Johnny Depp checks the medicine cabinet and finds ";

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
                    int happening = IntNumberGen(0,3);
                    
                    enum cabinet{ASHES, MEDICINE, FLOSS, SLASH};

                    switch(happening)
                    {
                        case ASHES:
                        {
                            cout << "left over Hunter S. Thompson ashes\n";
                            JohnnyDeppPockets->addToInv("jar of ashes");

                            break;
                        }

                        case MEDICINE:
                        {
                            cout << "DRUGS!!!!  But, the boring kind like Tylenol\n";
                            JohnnyDeppPockets->addToInv("Tylenol");

                            break;
                        }

                        case FLOSS:
                        {
                            cout << "floss... nobody uses floss...\n";
                            break;
                        }

                        case SLASH:
                        {
                            cout << "SLASH!!!!?? \n";
                            break;
                        }
                    }
                }
                break;
            }  

            case CLOSET:
            {
                cout << choices[4] << endl;
                cout << "Johnny Depp opens the bathroom closet.\n";
                cout << "He sees WONKA gum in with all the towels, toothbrushes and TP\n";
                cout << "Amber must have put it here.\n";
                cout << "Johnny Depp doesn't get angry,\n"; 
                cout << "but he ponders if he should move it.\n";
                
                JohnnyDeppPockets->addToInv("bubble gum");
                break;

            }  

            case DOOR:
            {
                cout << choices[5] << endl;
                cout << "Johnny Depp stops examining the bathroom.\n";
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
/************************************************************************************
Name:        continueWashingHands            
Called by:   Bathroom::examine
Calls:       getInteger
Passed:      nothing
Returns:     void    
 
Description: lets Johnny keep washing his hands....of Amber
************************************************************************************/
void Bathroom::continueWashingHands()
{
    string choices[2] = {"Yes\n",
                        "No\n", 
                        };

    string message1 = "\nDoes he continue to wash his hands?\n"
                    "1-" + choices[0] +
                    "2-" + choices[1];
                    

    bool flag = true;

    while(flag)
    {   
        int choice = getInteger(message1);

        enum {YES = 1, NO};

        switch(choice)
        {
            case YES:
            {
                cout << choices[0] << endl;
                cout << "Here was going to be code about seeing a woman tied up\n";
                cout << "in the reflection of the mirror\n";
                cout << "How cool would that have been?? Huh??  Huh??\n";
                cout << "I can't believe how long it takes me to code these projects\n";
                cout << "I also thought about doing some kind of Konami code thing\n";
                cout << "If you went up, up, down, down, left, right, left, right\n";
                cout << "check your pockets, drop an item, check your pockets, and \n";
                cout << "drop an item again, the bomb would disappear\n";
                cout << "That would have been so cool!!!!\n";
                cout << "Anyway....\n";
                cout << "Thanks for grading this and giving feedback\n";
                
                flag = false;

                break;
               
            }

            case NO:
            {
                cout << choices[1] << endl;
                cout << "Johnny Depp stops washing his hands.\n";
                
                flag = false;
                break;
            }

            default:
            {
                cout << "Invalid input\n";
                break;
            }
        }
    }
}
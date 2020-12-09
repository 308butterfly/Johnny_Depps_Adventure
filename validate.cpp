/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     A collection of functions to validate, integer input,
**                  integer input within a designated range
** Inputs:          integers from user                          
** Dependencies:    See Below         
** Returns:         
** File name:       validate.hpp
*********************************************************************************/

#include"validate.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*********************************************************************************
** Function name:   getinteger
** Date Modified:   4/20/2019
** Description:     Asks for and validates integer input.               
** Depenencies:     cstring, iostream, limits, ios libraries
** Inputs:          predefined string to assist in valid input, and a user integer
** Returns:         a user inputted integer.
*********************************************************************************/

#include <cstring>
#include <iostream> 
#include <limits>
#include <ios>

int getInteger(string message)
{
    while(true)
    {   
        cout<< message;
        int integer;
        cin >> integer;

        if(cin.fail())
        {
            //https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
            //to clear input buffer
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input!\n"; 
        }

        else
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return integer;
        }   
    }
}

/*********************************************************************************
** Function name:   IntNumberGen
** Date Modified:   4/20/2019
** Description:     A random integer generator
** Arguments:       2 signed integers to set the minimum and maximum value with
**                  minimum < maximum
** Dependencies:    ctime, cstdlib libraries.  srand(time(0)) must be used outside
**                  function
** Returns:         random signed integer in range of arguments
*********************************************************************************/

#include<ctime>
#include<cstdlib>
#include<cstdio>

int IntNumberGen(int minimum, int maximum)
{
    return (rand()%(maximum - minimum + 1)) + minimum;
}

/*********************************************************************************
** Function name:   intRangeCheck
** Date Modified:   5/28/2019
** Description:     This function checks if an entered integer is within a desired 
**                  range.  If it is not, the getInteger function is called again
**                  using a string to specify desired input.
**
** Inputs:          the minimum bound, the maximum bound, and a string for to be 
**                  passed to the getInteger function.
**                  
**
** Dependencies:    cstring, climits, getInteger.cpp
**                  
** Returns:         the entered integer if it is in range
*********************************************************************************/

#include<climits>

int intRangeCheck(int leftBound, int rightBound, std::string message )
{
    bool flag = true;

    int value; 
    
    do
    {
        value = getInteger(message);

        if((value >= leftBound) && (value <= rightBound))
        {
            flag = false;   
        }

        else
        {
            std::cout << "NOT IN RANGE!\n";
        }   
        
    }while(flag);

    return value;
}

/*********************************************************************************
** Function name:   getString
** Date Modified:   5/21/2019
** Description:     Checks if an entered string for characters that will conflict
**                  with filenames
**
** Inputs:          a string used for a filename
**                  
** Dependencies:    cstring 
**                  
** Returns:         string useable for a filename
*********************************************************************************/

std::string getFilename()
{
    std::string filename = "";

    bool flag = true;
    
    string forbiddenChar = "\\/?%*:|<>";
    
    while(flag)
    {
        flag = false;
        
        cout << "Enter a filename to save ..  DO NOT USE \\/?%*:|<>\n";
        cin >> filename;
        
        for(int i = 0; (i < (signed)filename.length()) && (flag == false) ; i++)
        {
            for(int j = 0; (j < (signed)forbiddenChar.length()) &&  (flag == false); j++)
            {
                if(filename[i] == forbiddenChar[j])
                {
                    cout << "IMPROPER FILENAME! TRY AGAIN!\n";
                    flag = true;
                }   
            }
        }
    }

    return filename;
}

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

#ifndef VALIDATE_HPP
#define VALIDATE_HPP

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

int getInteger(std::string);

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

int IntNumberGen(int minimum, int maximum);

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

int intRangeCheck(int leftbound, int rightbound, std::string);

/*********************************************************************************
** Function name:   getFilename
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

std::string getFilename();

#endif
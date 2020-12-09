#Author:  Andrew Thiele
#Email:  <thielea@oregonstate.edu>
#Makefile for lab6 

#source files: bathroom.cpp, bathroom.hpp, bedroom.hpp, bedroom.cpp, character.hpp, character.cpp,
#			   diningRoom.hpp, diningRoom.cpp, entrance.hpp, entrance.cpp, game.hpp, game.cpp, 
#			   hallway.hpp, hallway.cpp, pockets.hpp, pockets.cpp, item.hpp, item.cpp,  
#			   kitchen.hpp, kitchen.cpp, livingRoom.hpp, livingRoom.cpp, space.hpp, space.cpp,
#			   textAdDrv.cpp validate.cpp, and validate.hpp 

#Description:  Creates object files from source files to c++11 standard and
#              deletes .o and bin(executables) with "clean" command.
#
#              Checks for memory leaks with Valgrind
#              with 'val' command.
#

CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#Program Name
PROJ = proj5

# compile exectuable 
$(PROJ): bathroom.o bedroom.o diningRoom.o entrance.o game.o hallway.o pockets.o kitchen.o livingRoom.o space.o textAdDrv.o validate.o 
	$(CXX) bathroom.o bedroom.o diningRoom.o entrance.o game.o hallway.o pockets.o kitchen.o livingRoom.o space.o textAdDrv.o validate.o -o  $(PROJ)

# bathroom object file
bathroom.o: bathroom.cpp
	$(CXX) $(CXXFLAGS) -c bathroom.cpp

# bedroom object file
bedroom.o: bedroom.cpp
	$(CXX) $(CXXFLAGS) -c bedroom.cpp

# diningRoom object file
diningRoom.o: diningRoom.cpp
	$(CXX) $(CXXFLAGS) -c diningRoom.cpp

# entrance object file
entrance.o: entrance.cpp
	$(CXX) $(CXXFLAGS) -c entrance.cpp

# game object file
game.o: game.cpp
	$(CXX) $(CXXFLAGS) -c game.cpp

# hallway object file
hallway.o: hallway.cpp
	$(CXX) $(CXXFLAGS) -c hallway.cpp


# kitchen object file
kitchen.o: kitchen.cpp
	$(CXX) $(CXXFLAGS) -c kitchen.cpp

# livingRoom object file
livingRoom.o: livingRoom.cpp
	$(CXX) $(CXXFLAGS) -c livingRoom.cpp
	
# pockets object file
pockets.o: pockets.cpp
	$(CXX) $(CXXFLAGS) -c pockets.cpp

# space object file
space.o: space.cpp
	$(CXX) $(CXXFLAGS) -c space.cpp

# textAdDrv object file
textAdDrv.o: textAdDrv.cpp
	$(CXX) $(CXXFLAGS) -c textAdDrv.cpp
			
# validate  object file
validate.o: validate.cpp
	$(CXX) $(CXXFLAGS) -c validate.cpp
	
# remove all object files and executable file
clean:
	rm *.o $(PROJ)
	
# memory test with valgrind	
val:
	valgrind --leak-check=full ./$(PROJ)

# zip files and transfer to flip
zip:
	zip $(PROJ).zip *.cpp *.hpp *.pdf Makefile *.txt

# unzip file
unzip:
	unzip $(PROJ).zip

# delete zip file
cleanzip:
	rm *.zip


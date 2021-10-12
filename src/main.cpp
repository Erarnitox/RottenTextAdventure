//usual includes:
#include <iostream> 
#include <vector>
#include <string>
#include <map>
#include <filesystem>
#include <stdio.h>

//game specific includes:
#include "Player.h"
#include "Area.h"

int main(){
   //build the world:
   std::vector<Area> areas;

   //first room:
   areas.emplace_back(Area("Room", "A small room with a window, a bed and a door.\nIt smells burned.", "[ ]"));
	areas[0].addOption("Kill yourself", 66);
	areas[0].addOption("Go outside", 1);
	areas[0].addOption("Sleep...", 0);

	//second room:
	areas.emplace_back(Area("Hallway", "Everything is full of Smoke!\nYou can barely breath or see!", "  #  \n ### \n#####"));
	areas[1].addOption("Move Forward", 2);
	areas[1].addOption("Walk back into the room", 0);
	areas[1].addOption("Stay here...", 1);
	
   //display the welcome message:
   std::cout 
   << "--------------------------------------------\n"
   "Welcome to ROTTEN!\n"
   "A game by Erarnitox.\n"
   "use the command #help for a list of possible commands.\n"
   "Or use the command #help <command> to get furter help on a command.\n" 
   "--------------------------------------------\n"
   << std::endl;
   
   //game loop:
   std::string input;
   
   //query for save game:
   bool newGame{true};
   
   //TODO: turn off input buffering:

   do{
	   static char c{0};
	   static unsigned tmp{1337};
	   static unsigned selection{0};

       tmp = areas[selection].select(c);
	   
	   if(tmp != 1337){
		   selection = tmp;
		   tmp = 1337;
		   c=0;
		   continue;
	   }

	   std::cin >> c;
   }while(input != "quit");
}

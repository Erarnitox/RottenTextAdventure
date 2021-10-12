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
   areas.emplace_back(
	 Area("Room", "A small room with a window, a bed and a door.\nIt smells burned."
	 ,"__________\n          \n    [   ]    \n__[]__m---")
	);
	areas[0].addOption("Kill yourself", 3);
	areas[0].addOption("Go outside", 1);
	areas[0].addOption("Sleep...", 4);

	//hallway:
	areas.emplace_back(
	 Area("Hallway", "Everything is full of Smoke!\nYou can barely breath or see!", 
	 "##########\n##########\n##########")
	);
	areas[1].addOption("Move Forward", 2);
	areas[1].addOption("Walk back into the room", 0);
	areas[1].addOption("Stay here...", 5);

   //behind the house:
   areas.emplace_back(
	Area("Behind House", "It is cold and dark.\nBut it feels good to breathe the fresh air.\nYour neighbours are standing outside as well",
	" *   * * \n  *       \n__I__II___"));
	areas[2].addOption("Talk to Neighbour", 3);
	areas[2].addOption("Go back inside", 1);
	areas[2].addOption("Walk away", 7);
	areas[2].addOption("Get Naked", 8);

   //talk to neighbour
   areas.emplace_back(Area("David", "Oh man... why does that always happen to us?",
   "  ///  \n (- -)  \n   -   \n /    \\"));
	areas[3].addOption("Ignore", 2);
	areas[3].addOption("Ask: \"What happende exactly?\"", 9);
	areas[3].addOption("Cough: *GAY*", 2);
   
   //fell asleep
   areas.emplace_back(Area("Room", "You fell asleep...", "Zzzzz"));
	areas[4].addOption("Wakeup", 10);
   
   //first room:
   areas.emplace_back(Area("LOL is you DEAD?", "I think you just died lol", "X_X"));
	areas[5].addOption("Go into the light...", 11);

   //first room:
   areas.emplace_back(Area("Room", "A small room with a window, a bed and a door.\nIt smells burned.", "[ ]"));
	areas[6].addOption("Kill yourself", 3);
	areas[6].addOption("Go outside", 1);
	areas[6].addOption("Sleep...", 0);

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
	  
	   if(tmp == 666){
		   //TODO: Enable buffered input
		   //std::cout << ":";
		   std::getline(std::cin >> std::ws, input);
		   //player.command(input);
		   //Disable buffered input
		   tmp = 1337;
		   c = 0;
		   continue;
	   }
	   if(tmp != 1337){
		   selection = tmp;
		   tmp = 1337;
		   c=0;
		   continue;
	   }

	   std::cin >> c;
   }while(input != "q");
}

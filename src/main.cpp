//usual includes:
#include <iostream> 
#include <string>
#include <map>
#include <filesystem>
#include <stdio.h>

//game specific includes:
#include "Player.h"
#include "Area.h"

int main(){
   
   std::string input;
   
   //query for save game:
   //bool newGame{true};
   
   //create our player:
   Player player;

   //create our game world:
   Area* areas = createAreas();

   //TODO: turn off input buffering:
	
   //game loop:
   do{
	   static char c{0};
	   static unsigned tmp{1337};
	   static unsigned selection{0};

       tmp = areas[selection].select(c);
	  
	   //if player command entered:
	   if(tmp == 666){
		   //TODO: Enable buffered input
		   //std::cout << ":";
		   std::getline(std::cin >> std::ws, input);
		   player.command(input);
		   //Disable buffered input
		   tmp = 1337;
		   c = 0;
		   continue;
	   }

	   //if the target didn't change 
	   if(tmp != 1337){
		   selection = tmp;
		   tmp = 1337;
		   c=0;
		   continue;
	   }

	   std::cin >> c;
   }while(input != "q");
}

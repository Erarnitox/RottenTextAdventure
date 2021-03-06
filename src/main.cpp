//usual includes:
#include <iostream> 
#include <string>
#include <map>
#include <filesystem>
#include <stdio.h>

//third party headers:
#include "Terminal.h"

//game specific includes:
#include "Player.h"
#include "Area.h"

int main(){
   
   std::string input;
   
   //query for save game: bool newGame{true};
   
   //create our player:
   Player player;

   //create Items:
   Area::addItem("Key");
   Area::addItem("Thinkpad");

   //create our game world:
   Area* areas = createAreas();

   //tun off buffered input:
   BufferToggle bf;
   bf.off();
	
   //game loop:
   do{
	   static char c{0};
	   static unsigned tmp{1337};
	   static unsigned selection{0};
	  
       tmp = areas[selection].select(player, c);

	   //open inventory:
	   if(tmp == 717){
		   player.inventory();
		   tmp = 666;
	   }

	   //if player command entered:
	   if(tmp == 666){
		   bf.on();
		   std::cout << ":";
		   std::getline(std::cin >> std::ws, input);
		   player.command(input);
		   bf.off();
		   tmp = 1337;
		   c = 0;
		   continue;
	   }

	   //if the target did change 
	   else if(tmp != 1337){
		   selection = tmp;
		   tmp = 1337;
		   c=0;
		   continue;
	   }

	   std::cin >> c;
   }while(input != "q");
   
   bf.on();
return 0;
}

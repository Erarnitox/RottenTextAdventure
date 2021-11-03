#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Player.h"

Player::Player(){

}

void Player::command(const std::string& cmd){
    if(cmd[0] == 'q') return;
    
    std::stringstream commandStream(cmd);
    std::vector<std::string> tokens;
    std::string tmp;
    
    while(getline(commandStream, tmp, ' ')){
        //intermediate commands
        if(tmp == "okay"){
            //doing nothing
        }else if(tmp == "use"){
            //this->dropItem(commandStream);
        }else if(tmp == "drop"){
            this->dropItem(commandStream);
        }else{
            tokens.push_back(tmp);
        }
    }
}

void Player::dropItem(std::stringstream& commandStream){
    unsigned itemId{0};
    unsigned count{0};
            
    if (commandStream.rdbuf()->in_avail()){
		commandStream >> itemId;
	}else{
        for(unsigned i{0}; i < 15; ++i){
            if(this->items[i] > 0){
                itemId = i;
                break;
            }
        }
        if(!items[itemId]){
			this->hasItems = 0;
			return;
		}
    }
    
    if (commandStream.rdbuf()->in_avail()) commandStream >> count;
    else count = 1;
    
    if(itemId > 14) return;
    if(count < this->items[itemId]){
        this->items[itemId] -= count;
		this->hasItems -= count;
    }else{
        --this->hasItems;
        this->items[itemId] = 0;
    }
}

void Player::explore(const char* location){
	std::cout << "Start exploring " << (location? location : "Wasteland of Zion") << "...\n";
}

//void Player::help(const char* matter){
	/*
	for(auto c : commands){
	    c.usage();	
	}*/
//}

bool Player::inventory(){
    if(!this->hasItems){
        puts("NO ITEMS IN INVENTORY");
        return false;
    }
	std::cout << "-----INVENTORY:-----\n";
	for(unsigned i{0}; i < 15; ++i){
		//print item information
		if(items[i]) printf("[%d] %dx %s\n", i, items[i], itemNames[i]);
	}
	std::cout << "You can: \"use <id>\" or \"drop <id>\"\n-------------------\n";
	return false;
}

void Player::take(const unsigned& itemId, const char* itemName){
    ++this->hasItems;
	++items[itemId];
	if(itemName) itemNames[itemId] = itemName;
}

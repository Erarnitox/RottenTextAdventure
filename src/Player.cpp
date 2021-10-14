#include <iostream>
#include <string>

#include "Player.h"

Player::Player(){

}

void Player::command(const std::string& cmd){
	//std::cout << "COMMAND: " << cmd << std::endl;
}

void Player::explore(const char* location){
	std::cout << "Start exploring " << (location? location : "Wasteland of Zion")         << "...\n";
}

void Player::help(const char* matter){
	/*
	for(auto c : commands){
	    c.usage();	
	}*/
}

void Player::inventory(const char* action){
	/*
	std::cout << "List of Items in Inventory:\n";
	for(auto i : this->items){
	    i.info();	
	}
	std::cout << "You can: \"use <id>\" or \"drop <id>\"\n";
	*/
}

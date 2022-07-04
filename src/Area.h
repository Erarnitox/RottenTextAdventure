#pragma once

#include <stdio.h>
#include "Player.h"

constexpr unsigned  OPT_SIZE{15};
//constexpr unsigned  ITEM_SIZE{15};

unsigned itemCount;
const char* itemNames[ITEM_SIZE];

class Option{
	char* text;
	unsigned target;
	unsigned reqAttribId;
	unsigned reqAttribCount;
	unsigned reqSkillId;
	unsigned reqSkillPoints;
	unsigned reqItemId;
	unsigned reqItemCount;
	
public:
	Option(char* text=nullptr, 	unsigned target=0,
	unsigned reqAttribId=0, 	unsigned reqAttribCount=0,
	unsigned reqSkillId=0, 		unsigned reqSkillPoints=0, 
	unsigned reqItemId=80085, 	unsigned reqItemCount=0):
		text{text},					target{target},
		reqAttribId{reqAttribId}, 	reqAttribCount{reqAttribCount},
		reqSkillId{reqSkillId}, 	reqSkillPoints{reqSkillPoints},
		reqItemId{reqItemId}, 		reqItemCount{reqItemCount}{
		}
	
	bool isAvailable(const Player& player) const{
		//check Attributes
		switch(reqAttribId){
			//perception:
			case 1:
				if(player.attributes.perception < reqAttribCount)
					return false;
			break;

			//endurance:
			case 2:
				if(player.attributes.endurance < reqAttribCount)
					return false;
			break;

			//resiliance:
			case 3:
				if(player.attributes.resiliance < reqAttribCount)
					return false;
			break;

			//strength:
			case 4:
				if(player.attributes.strength < reqAttribCount)
					return false;
			break;

			//intelligence:
			case 5:
				if(player.attributes.intelligence < reqAttribCount)
					return false;
			break;

			//luck:
			case 6:
				if(player.attributes.luck < reqAttribCount)
					return false;
			break;
		}
		//check Skills
		switch(reqSkillId){
			//hacking
			case 1:
				if(player.skills.hacking < reqSkillPoints)
					return false;
			break;
	
			//programming
			case 2:
				if(player.skills.programming< reqSkillPoints)
					return false;
			break;
		
			//soldering
			case 3:
				if(player.skills.soldering< reqSkillPoints)
					return false;
			break;

			//lockPicking
			case 4:
				if(player.skills.lockPicking< reqSkillPoints)
					return false;
			break;

			//climbing
			case 5:
				if(player.skills.climbing< reqSkillPoints)
					return false;
			break;

			//hiding
			case 6:
				if(player.skills.hiding< reqSkillPoints)
					return false;
			break;

		}
		
		if(reqItemId == 80085) return true;
		return player.hasItem(reqItemId, reqItemCount);
	}

	const char* getText(){
		return text;
	}

	unsigned getTarget(){
		return target;
	}

	void setText(const char* text){
		this->text = const_cast<char*>(text);
	}
	
	void setTarget(unsigned target){
		this->target = target;
	}

	void setRequirements(
	unsigned attribId=0, 	unsigned attribCount=0,
	unsigned skillId=0,  	unsigned skillPoints=0,
	unsigned itemId=80085, 	unsigned itemCount=0){
		this->reqAttribId = attribId;
		this->reqAttribCount = attribCount;
		this->reqSkillId = skillId;
		this->reqSkillPoints = skillPoints;
		this->reqItemId = itemId;
		this->reqItemCount = itemCount;
	}
};

class Area{
	bool hasItems{false};
	const char* name;
	const char* description;
	const char* picture;
	unsigned usedItemSlots{0};
	unsigned lastOption{0};
	Option options[OPT_SIZE]{};
	int items[ITEM_SIZE]{};	

public:

	Area(const char* const name=nullptr, const char* description=nullptr, const char* picture=nullptr):
		name{name}, description{description}, picture{picture}{
			//constructor body	
		}
	Area& addOption(const char* text, unsigned target, 
	unsigned attribId=0, 	unsigned attribCount=0, 
	unsigned skillId=0, 	unsigned skillPoints=0,
	unsigned itemId=80085, 	unsigned itemCount=0){
		if(!(lastOption < OPT_SIZE)) return *this;
		options[lastOption].setText(text);
		options[lastOption].setTarget(target);
		options[lastOption].setRequirements(attribId, attribCount, skillId, skillPoints, itemId, itemCount);
		++lastOption;
		return *this;
	}

	Area& addItem(const unsigned itemId, const unsigned count){
		if(itemCount<= itemId) return *this;
		++usedItemSlots;
		hasItems = true;
		items[itemId] += count;
		return *this;
	}

	Area& takeItem(Player& player, unsigned& itemSel){
		if(!hasItems) return *this;
		const unsigned itemId{itemSel};

		if(itemCount>0 && itemId<itemCount){
			--items[itemId];
			player.take(itemId, itemNames[itemId]);
			if(!items[itemId]){
				--usedItemSlots;
				if(!usedItemSlots) hasItems = false;
				else{
					do{
						if(itemSel) --itemSel;
						else itemSel = itemCount-1;
					}while(!items[itemSel]);
				}
			}
		}
		return *this;
	};


	static void addItem(const char* itemName){
		static bool initialized{false};
		if(!initialized) itemCount = 0;
		initialized = true;
		if(itemCount < ITEM_SIZE)
			itemNames[itemCount++] = itemName;
	};

	unsigned select(Player& player, char c=0){
		printf("\033[2J\033[1;1H[%s]:\n%s\n%s\n\nWHAT DO YOU DO?\n", name, picture, description);
	
		static unsigned sel{0};
		static unsigned itemSel{0};
		unsigned tmp{sel};

		switch(c){
			case 'j':
				++sel %= lastOption;
			break;
			case 'k':
				if(sel) --sel;
				else sel = lastOption-1;
			break;

			case 'l':
				if(!hasItems) break;
				do{
					++itemSel %= itemCount;
				}while(!items[itemSel]);
			break;
			case 'h':
				if(!hasItems) break;
				do{
					if(itemSel) --itemSel;
					else itemSel = itemCount-1;
				}while(!items[itemSel]);
			break;

			case 't':
				takeItem(player, itemSel);
			break;
			
			case 's':
				tmp=sel;
				sel=0;
				itemSel=0;
				c=0;
				return options[tmp].getTarget();
			break;

			case ':':
				c=0;
				return 666;
			break;

			case 'i':
				c=0;
				return 717;
			break;

			case 0:
			default:
			break;
		}
		
		if(hasItems){
			puts(" ---------------------ITEMS:-------------------------------- ");
			for(unsigned i{0}; i < itemCount; ++i){
				if(!(i%5)) puts("");
				if(itemSel==i) printf("\033[1;33m\033[1;42m");
				if(items[i]) printf("%c[%dx %s] ",itemSel==i?'*':' ', items[i], itemNames[i]);
				if(itemSel==i) printf("\033[0m");
			}
			puts("");
		}

		puts(" ---------------------OPTIONS:------------------------------ ");
		for(unsigned i{0}; i < lastOption; ++i){
			if(!options[i].isAvailable(player)) continue;
			if((i<5&&sel<5) || sel-i < 5){
				if(sel==i) printf("\033[1;33m\033[1;42m");
				printf(" %c [%s]\n", (sel != i)?' ':'>', options[i].getText());
				if(sel==i) printf("\033[0m");
			}
		}
		puts(" ----------------------------------------------------------- ");

		return 1337; 
	}
};

Area* createAreas(){
	static Area tmp[]{
		//first Room:
		Area("Hello World!", "You wake up in a small Shed", 
		" _____________________________________________\n"
		"|.'',                                     ,''.|\n"
		"|.'.'',                                 ,''.'.|\n"
		"|.'.'.'',                             ,''.'.'.|\n"
		"|.'.'.'.'',_________________________,''.'.'.'.|\n"
		"|.'.'.'.'.|.,.,.,.,.,.,.,.,.,.,.,.,.|.'.'.'.'.|\n"
		"|.'.'.'.'.|.,.,.,.,.,.,.,.,.,.,.,.,.|.'.'.'.'.|\n"
		"|.'.'.'.'.|.,.,.,.,.,.,.,.,.,.,.,.,.|.'.'.'.'.|\n"
		"|.'.'.'.'.|.,.,.,.,.,.,.,.,.,.,.,.,.|.'.'.'.'.|\n"
		"|.'.'.'.'.|.,.,.,.,--------.,.,.,.,.|.'.'.'.'.|\n"
		"|,',',',',|.,.,.,.,||||||||.,.,.,.,.|,',',',',|\n"
		"|.'.'.'.'.|.,.,.,.,||||||||.,.,.,.,.|.'.'.'.'.|\n"
		"|.'.'.'.'.|.,.,.,.,|-||||||.,.,.,.,.|,.'.'.'.'|\n"
		"|.'.'.'.'.|.,.,.,.,||||||||.,.,.,.,.|..'.'.'.'|\n"
		"|.'.'.'.'.|.,.,.,.,||||||||.,.,.,.,.|.'.'.'.'.|\n"
		"|.'.'.'.','_________________________|','.'.'.'|\n"
		"|.'.'.','        /%%%%%%%%%%%\\        ','.'.'.|\n"
		"|.'.','         /%%%%%%%%%%%%%\\         ','.'.|\n"
		"|.','          /%%%%%%%%%%%%%%%\\          ','.|\n"
		"|;____________/%%%%%%%%%%%%%%%%%\\____________;|\n")\
		.addOption("Go Outside", 1, ATTRIB_NONE, 0, SKILL_NONE, 0, ITEM_SHED_KEY, 1)\
		.addOption("Stay here...", 0)\
		.addItem(ITEM_SHED_KEY, 1)\
		.addItem(ITEM_THINKPAD, 1),

		//second Room:
		Area("Another Room", "wow another room!", "(*___*)")\
		.addOption("Go back", 0)\
		.addOption("Stay here...", 1)
	};
	return tmp;
};


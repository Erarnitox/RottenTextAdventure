#pragma once
#include <stdio.h>

constexpr unsigned  OPT_SIZE{5};

class Option{
	char* text;
	unsigned target;
public:
	Option(char* text=nullptr, unsigned target=0):
		text{text}, target{target}{
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
};

class Area{
	const char* name;
	const char* description;
	const char* picture;
	unsigned lastOption{0};
	Option options[OPT_SIZE]{};
	//int items[20]{};	

public:
	Area(const char* const name=nullptr, const char* description=nullptr, const char* picture=nullptr):
		name{name}, description{description}, picture{picture}{
			//constrctor body	
		}
	Area& addOption(const char* text, unsigned target){
		if(!(lastOption < OPT_SIZE)) return *this;
		options[lastOption].setText(text);
		options[lastOption++].setTarget(target);
		return *this;
	}

	unsigned select(char c=0){
		printf("\033[2J\033[1;1H[%s]:\n%s\n%s\n\nWHAT DO YOU DO?\n", name, picture, description);
	
		static unsigned sel{0};
		unsigned tmp{sel};

		switch(c){
			case 'j':
				++sel %= lastOption;
			break;
			case 'k':
				if(sel) --sel;
				else sel = lastOption-1;
			break;
			
			case 's':
				tmp=sel;
				sel=0;
				c=0;
				return options[tmp].getTarget();
			break;

			case ':':
				c=0;
				return 666;
			break;

			case 0:
			default:
			break;
		}

		puts(" ----------------------------------------------------------- ");
		for(unsigned i{0}; i < lastOption; ++i){
			printf(" %c [%s]\n", (sel != i)?' ':'>', options[i].getText());
		}
		puts(" ----------------------------------------------------------- ");

		return 1337; 
	}
};

Area* createAreas(){
	static Area tmp[]{
		//first Room:
		Area("First Room", "Everybody starts somewhere!", "(*.*)").addOption("Go to second Room", 1).addOption("Stay here...", 0),

		//first Room:
		Area("Another Room", "wow another room!", "(*___*)").addOption("Go to second Room", 1).addOption("Stay here...", 0)
	};
	return tmp;
};


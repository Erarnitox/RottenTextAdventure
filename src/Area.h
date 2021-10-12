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

	void setText(char* text){
		this->text = text;
	}
	
	void setTarget(unsigned target){
		this->target = target;
	}
};

class Area{
	const char* name;
	const std::string description;
	const char* picture;
	unsigned lastOption{0};
	Option options[OPT_SIZE]{};
	
public:
	Area(const char* const name, const std::string& description, const char* picture):
		name{name}, description{description}, picture{picture}{
			//constrctor body	
		}
	void addOption(char* text, unsigned target){
		if(!(lastOption < OPT_SIZE)) return;
		options[lastOption].setText(text);
		options[lastOption++].setTarget(target);
	}

	unsigned select(char c=0){
		std::cout << "\033[2J\033[1;1H";
		printf("%s:\n%s", name, picture);
		std::cout << "\n" <<  description << "\n";
		std::cout << "WHAT DO YOU DO?:\n";
	
		static unsigned sel{0};

		switch(c){
			case 'j':
				++sel %= lastOption;
			break;
			case 'k':
				if(sel) --sel;
				else sel = lastOption-1;
			break;
			
			case 's':
				return options[sel].getTarget();
			break;

			case 0:
			default:
			break;
		}

		for(unsigned i{}; i < lastOption; ++i){
			printf(" %c [%s]\n", (sel != i)?' ':'>', options[i].getText());
		}
		return 1337; 
	}
};

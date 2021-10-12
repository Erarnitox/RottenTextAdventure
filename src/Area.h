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
	const std::string description;
	const char* picture;
	unsigned lastOption{0};
	Option options[OPT_SIZE]{};
	int items[20]{};	

public:
	Area(const char* const name, const std::string& description, const char* picture):
		name{name}, description{description}, picture{picture}{
			//constrctor body	
		}
	void addOption(const char* text, unsigned target){
		if(!(lastOption < OPT_SIZE)) return;
		options[lastOption].setText(text);
		options[lastOption++].setTarget(target);
	}

	unsigned select(char c=0){
		std::cout << "\033[2J\033[1;1H";
		printf("[%s]:\n%s", name, picture);
		std::cout << "\n" <<  description << "\n\n";
		std::cout << "WHAT DO YOU DO?:\n";
	
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

#pragma once
#define ITEM_SIZE 512

#define ATTRIB_NONE 0
#define ATTRIB_PERCEPTION 1
#define ATTRIB_ENDURANCE 2
#define ATTRIB_RESILIANCE 3
#define ATTRIB_STRENGTH 4
#define ATTRIB_INTELLIGENCE 5
#define ATTRIB_LUCK 6

#define SKILL_NONE 0
#define SKILL_HACKING 1
#define SKILL_PROGRAMMING 2
#define SKILL_SOLDERING 3
#define SKILL_LOCK_PICKING 4
#define SKILL_CLIMBING 5
#define SKILL_HIDING 6

#define ITEM_NONE 80085
#define ITEM_SHED_KEY 0
#define ITEM_THINKPAD 1

#include <string>

struct Command{
   char keyword[20];
   void* function;

   void info();
};

struct Attributes{
   unsigned perception;
   unsigned endurance;
   unsigned resiliance;
   unsigned strength;
   unsigned intelligence;
   unsigned luck;
};

struct Skills{
   unsigned hacking;
   unsigned programming;
   unsigned soldering;
   unsigned lockPicking;
   unsigned climbing;
   unsigned hiding;
};

struct Position{
    long x, y;
};

class Player{
public:
   struct Attributes attributes{};
   struct Skills skills{};
   struct Position position;

private:
   std::string name;
   bool isMale{true};
   
   unsigned hasItems{0};
   unsigned items[ITEM_SIZE]{};
   const char* itemNames[ITEM_SIZE]{};
   unsigned maxHealth{100};
   unsigned health{100};
   unsigned stamina{100};
   int karma{0};
   int cryptoCoin{0};
   unsigned level{1};
   int expToNext{100};
   
   void dropItem(std::stringstream& commandStream);
  
public:
   Player();
   void explore(const char* location = nullptr);
   void help(const char* matter = nullptr);
   void profile();
   bool inventory(); 
   bool hasItem(unsigned itemId, unsigned itemCount) const;
   void take(const unsigned& id, const char* itemName);
   void command(const std::string& cmd);
};

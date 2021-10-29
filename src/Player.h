#pragma once

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
   unsigned strenght;
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
   struct Attributes attributes{};
   struct Skills skills{};
   struct Position position;

   std::string name;
   bool isMale{true};
   
   unsigned hasItems{0};
   unsigned items[15]{};
   const char* itemNames[15]{};
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
   void take(const unsigned& id, const char* itemName);
   void command(const std::string& cmd);
};

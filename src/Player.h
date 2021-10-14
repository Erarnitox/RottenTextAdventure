#pragma once

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

struct Items{
   unsigned id;
};

struct Position{
    long x, y;
};

class Player{
   struct Attributes attributes{};
   struct Skills skills{};
   struct Items items[6];
   struct Position position;

   std::string name;
   bool isMale{true};

   unsigned maxHealth{100};
   unsigned health{100};
   unsigned stamina{100};
   int karma{0};
   int cryptoCoin{0};
   unsigned level{1};
   int expToNext{100};
  
public:
   Player();
   void explore(const char* location = nullptr);
   void help(const char* matter = nullptr);
   void profile();
   void inventory(const char* action); 
   void take(const unsigned& id);
   void command(const std::string& cmd);
};

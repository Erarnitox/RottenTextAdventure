#pragma once

struct Attributes{
   unsigned perception;
   unsigned endurance;
   unsigned resiliance;
   unsigned strenght;
   unsigned intelligence;
   unsigned luck;
};

class Player{
   struct Attributes{};
   struct Skills{};
   struct Items[20];
   struct Position;

   char name[20];
   bool isMale{true};

   unsigned health{100};
   unsigned stamina{100};
   int karma{0};
   int cryptoCoin{0};
   unsigned level{1};
   int expToNext{100};
   
   public:
   Player();
   void explore(const char* location);
   void help(const char* matter);
   void profile();
   void inventory(const char* action);
};


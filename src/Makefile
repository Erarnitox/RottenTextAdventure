rotten.elf: ../bin/dbg/main.o ../bin/dbg/Player.o
	g++ -g -pedantic -Werror -Wall -Wextra -Wconversion -Woverloaded-virtual ../bin/dbg/main.o ../bin/dbg/Player.o -o ../bin/dbg/rotten.elf

../bin/dbg/main.o: main.cpp Area.h
	g++ -pedantic -Werror -Wall -Wextra -Wconversion -Woverloaded-virtual -g -c main.cpp -o ../bin/dbg/main.o

../bin/dbg/Player.o: Player.h Player.cpp
	g++ -pedantic -Werror -Wall -Wextra -Wconversion -Woverloaded-virtual -g -c Player.cpp -o ../bin/dbg/Player.o

release: ../bin/stbl/main.o ../bin/stbl/Player.o ../bin/stbl/story.pdf
	g++ -O3 -s -Wall ../bin/stbl/main.o ../bin/stbl/Player.o -o ../bin/stbl/ROTTEN

../bin/stbl/main.o: main.cpp Area.h
	g++ -O3 -Wall -c main.cpp -o ../bin/stbl/main.o

../bin/stbl/Player.o: Player.h Player.cpp
	g++ -O3 -Wall -c Player.cpp -o ../bin/stbl/Player.o

../bin/stbl/story.pdf: ../story.ms
	groff -mspdf -Tpdf ../story.ms  > ../bin/stbl/story.pdf

clean:
	rm -rf ../bin/dbg/*; rm -rf ../bin/stbl/*
	
run:
	../bin/stbl/ROTTEN
	
debug:
	gdb ../bin/dbg/rotten.elf

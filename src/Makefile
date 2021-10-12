rotten.elf: ../bin/main.o ../bin/Player.o
	g++ -Wall ../bin/main.o ../bin/Player.o -o ../bin/rotten.elf

../bin/main.o: main.cpp Area.h
	g++ -Wall -c main.cpp -o ../bin/main.o

../bin/Player.o: Player.h Player.cpp
	g++ -Wall -c Player.cpp -o ../bin/Player.o

clean:
	rm -rf ../bin/*
	
run:
	../bin/rotten.bin

rotten.elf: ../bin/main.o ../bin/Player.o
	g++ ../bin/main.o ../bin/Player.o -o ../bin/rotten.elf

../bin/main.o: main.cpp Area.h
	g++ -c main.cpp -o ../bin/main.o

../bin/Player.o: Player.h Player.cpp
	g++ -c Player.cpp -o ../bin/Player.o

clean:
	rm -rf ../bin/*

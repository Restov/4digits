all: bin/programm

bin/programm: build/main.o
	g++ -Wall -Werror build/main.o -o bin/programm

build/main.o: src/main.cpp
	g++ -Wall -Werror -c src/main.cpp


clean:
	rm -rf build/*.o
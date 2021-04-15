all: store.o main.o laba

store.o: store.cpp
	g++ -c -o store.o store.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

laba: store.o main.o
	g++ main.o store.o -o laba
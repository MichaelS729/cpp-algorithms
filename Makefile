main: main.o LinkedList.o Node.o
	g++ -o main main.o LinkedList.o Node.o

main.o: main.cpp LinkedList.h Node.h LinkedListTests.h
	g++ -Wall -c main.cpp

Node.o: Node.cpp Node.h
	g++ -Wall -c Node.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Node.h
	g++ -Wall -c LinkedList.cpp

clean:
	rm -f main.o LinkedList.o Node.o main

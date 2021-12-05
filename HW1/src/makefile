all: ./c/stack.o ./c++/stack.o 
	g++ ./c/main.c ./c/stack.o -o ./c/main.out
	g++ ./c/main2.c ./c/stack.o -o ./c/main2.out
	g++ ./c++/main.cpp ./c++/stack.o -o ./c++/main.out
	g++ ./c++/main2.cpp ./c++/stack.o -o ./c++/main2.out

./c/stack.o:
	g++ -c ./c/stack.c -o ./c/stack.o
./c++/stack.o:
	g++ -c ./c++/stack.cpp -o ./c++/stack.o

clean:
	rm -f ./c/main.out
	rm -f ./c/main2.out 
	rm -f ./c/stack.o 
	rm -f ./c++/main.out
	rm -f ./c++/main2.out
	rm -f ./c++/stack.o 
	
all: main.out

main.out: lexer.o main.o
	g++ lexer.o main.o -o main.out

lexer.o: lexer.cpp lexer.h
	g++ -c lexer.cpp -o lexer.o

main.o: main.cpp lexer.h
	g++ -c main.cpp -o main.o

clean:
	rm -f *.out
	rm -f *.o

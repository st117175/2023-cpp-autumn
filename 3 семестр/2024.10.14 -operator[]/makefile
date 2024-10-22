main: main.o string.o
	g++ main.o string.o -o main			
main.o: main.cpp 						
	g++ -c main.cpp
string.o: string.cpp 						
	g++ -c string.cpp
clean: 								
	rm -f main *.o

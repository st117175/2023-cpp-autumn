main: main.o Data.o Dataset.o
	g++ main.o Data.o Dataset.o -o main			
Data.o: Data.cpp 						
	g++ -c Data.cpp
Dataset.o: Dataset.cpp 						
	g++ -c Dataset.cpp
main.o: main.cpp
	g++ -c main.cpp
clean: 								
	rm -f main *.o

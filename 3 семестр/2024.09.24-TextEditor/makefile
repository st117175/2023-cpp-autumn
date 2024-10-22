main: main.o Editor.o
	g++ main.o Editor1.o -o main
main.o: main.cpp 						
	g++ -c main.cpp			
Editor.o: Editor1.cpp 						
	g++ -c Editor1.cpp
clean: 								
	rm -f main *.o

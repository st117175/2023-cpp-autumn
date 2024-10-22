main: main.o BankAccount.o Bank.o
	g++ main.o BankAccount.o Bank.o -o main			
BankAccount.o: BankAccount.cpp 						
	g++ -c BankAccount.cpp
Bank.o: Bank.cpp 						
	g++ -c Bank.cpp
main.o: main.cpp
	g++ -c main.cpp
clean: 								
	rm -f main *.o

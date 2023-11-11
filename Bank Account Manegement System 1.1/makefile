programRun: compile connect run

compile:
	g++ -c -I "./include/" ./src/BankAccount.cpp -o ./lib/BankAccount.o
	
connect:
	g++ ./lib/BankAccount.o -o ./bin/BAMS
	
run:
	./bin/BAMS 
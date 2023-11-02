runprogram: compile connect run

compile:
	g++ -c -I "./include/" ./src/Person-Employee-Maneger.cpp -o ./lib/Person-Employee-Maneger.o
	
connect:
	g++ ./lib/Person-Employee-Maneger.o -o ./bin/Program
	
run:
	./bin/Program
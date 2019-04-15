member.o: member.cpp member.h
	g++ -c member.cpp
extraFunctions.o: extraFunctions.h extraFunctions.cpp member.h
	g++ -c extraFunctions.cpp
program.o: extraFunctions.h member.h program.cpp
	g++ -c program.cpp
finalExecutable: program.o member.o extraFunctions.o
	g++ $^ -o $@

clean:
	rm program.o member.o extraFunctions.o

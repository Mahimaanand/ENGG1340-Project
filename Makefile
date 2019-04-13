member.o: member.cpp member.h
	g++ -c member.cpp
extraFunctions.o: extraFunctions.h extraFunctions.cpp member.h
	g++ -c extraFunctions.cpp


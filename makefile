proj6: airport.o wlin48proj6.o
	g++ -o proj6 airport.o wlin48proj6.o

airport.o: airport.cpp airport.h
	g++ -c airport.cpp

wlin48proj6.o: wlin48proj6.cpp airport.h
	g++ -c wlin48proj6.cpp



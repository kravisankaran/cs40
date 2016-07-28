all:	airline.out

airline.out: main.o flight.o plane.o utilities.o
	g++ -Wall main.o flight.o plane.o utilities.o -o airline.out

main.o: main.cpp flight.h utilities.h plane.h
	g++ -Wall -g -c main.cpp

utilities.o: utilities.cpp utilities.h
	g++ -Wall -g -c utilities.cpp

flight.o: flight.cpp flight.h plane.h 
	g++ -Wall -g -c flight.cpp

plane.o: plane.cpp plane.h
	g++ -Wall -g -c plane.cpp

clean:
	rm *.o
	rm airline.out

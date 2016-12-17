#ifndef FLIGHT_H
#define	FLIGHT_H


#include "plane.h"

#define MAX_CITY_LENGTH 20


 

class Flight
{
  private:
  
  int flightNum;
  char origin[MAX_CITY_LENGTH];
  char destination[MAX_CITY_LENGTH];
  Plane *plane;

  public:
   void addPassenger();
  ~Flight();
   int getFlightNumber();
   void printFlightInfo();
   void readFlight(ifstream &inf);
   void writeFlight(ofstream &outf);

};


#endif	// FLIGHT_H


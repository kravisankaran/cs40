// Author: Sean Davis


#include <iostream>
#include <fstream>
#include <string.h>
#include "flight.h"

using namespace std;

void Flight::addPassenger()
{
  if(!plane->addPassenger())
    cout << "We are sorry but Flight #"<< flightNum << " is full.\n" ;
  
}  // addPassenger()

Flight::~Flight()
{
  delete(plane);
  
}  // freeFlight()


int Flight::getFlightNumber()
{
  return flightNum;
}  // getFlightNumber()


void Flight::printFlightInfo()
{
  cout <<  flightNum <<  origin << destination << endl;
}  // printFlightInfo()


void Flight::readFlight(ifstream &inf)
{
  inf>>flightNum;
  
  inf.ignore(10, '\n');
  inf.getline(origin, MAX_CITY_LENGTH);
  

  strtok(origin, "\r\n");  // get rid of '\n' and/or '\r'
  inf.getline(destination, MAX_CITY_LENGTH);
  strtok(destination, "\r\n");  // get rid of '\n'
  //flight->plane = (Plane*) malloc(sizeof(Plane));
  plane= new Plane(inf);
  
}  // readFlight()


void Flight::writeFlight(ofstream &outf)
{
  outf << flightNum << '\n' << origin << '\n' << destination << endl;
  
  plane->writePlane(outf);
}  // readFlight()

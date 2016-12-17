

#include <iostream>
#include <fstream>
#include "flight.h"
#include "utilities.h"

using namespace std;
#define DONE 0
#define MAX_CHOICE 1


void addPassenger(Flight* flights, int numFlights)
{
  int i, flightNumber;
  
  cout << "Flt# Origin               Destination"<<endl;

  for(i = 0; i < numFlights; i++)
    flights[i].printFlightInfo();

  do
  {
    printf("\nFlight number (0 = exit): ");
    flightNumber = getNumber();

    if(flightNumber > 0)
    {
      
      for(i = 0; i < numFlights; i++)
        if(flights[i].getFlightNumber() == flightNumber)
        {
          flights[i].addPassenger();
          break;
        }  // if found match of flight

      if(i == numFlights)
      {
        cout << "We do not have a flight number "<< flightNumber << ".\n";
        cout << "Please try again.\n";
      }  // if flightNumber not found
    }  // if flightNumber > 0
    else // if flightNumer <= 0
      if(flightNumber == ERROR)
        cout << "That is an invalid flight number.\nPlease try again.\n"; 
  }  while((flightNumber != 0 && i == numFlights) || flightNumber == ERROR);
}  // addPassenger()


void freeFlights(Flight *flights, int numFlights)
{
 /* int i;
  
  for(i = 0; i < numFlights; i++)
    freeFlight(&flights[i]);*/
  
  delete [] flights;
}  // freeFlights()


int getChoice()
{ 
  int choice;
  cout << "\nECS Flight Reservation Menu\n";
  cout << "0. Exit.\n";
  cout << "1. Add Passenger.\n";
  
  do
  {
    cout << "\nPlease enter your choice: ";
    choice = getNumber();
    
    if(choice == ERROR)
    {
      cout << "Your choice is invalid.\n";
      cout << "Please try again.\n";
    }  // if invalid format
    else // choice is a valid number
      if(choice < DONE || choice > MAX_CHOICE)
      {
        cout << choice << " is not an available choice.\n";
        cout << "Please try again.\n";
      }  // if choice out of range.
  } while(choice < DONE || choice > MAX_CHOICE  || choice == ERROR);
  
  if(choice == DONE)
    printf("Goodbye.\n");
  
  return choice;
} // getChoice()


Flight* readFlights(int *numFlights)
{
  
  int i;
  ifstream inf;
  inf.open("reservations.txt", ifstream::in);
  //fscanf(fp, "%d", numFlights);
  inf >> *numFlights;
  //flights = (Flight*) malloc();
  
 Flight *flights= new Flight [*numFlights * sizeof(Flight)];
  
  for(i = 0; i < *numFlights; i++)
    flights[i].readFlight(inf);
  
  inf.close();
  return flights;
} // readFlights()

void writeFlights(Flight *flights, int numFlights)
{
  int i;
  ofstream of;
  of.open("reservations2.txt", ofstream :: out| ofstream:: app);
  of << numFlights << endl;
  
  for(i = 0; i < numFlights; i++)
    flights[i].writeFlight(of);
  
  of.close();
}  // freeFlights()

int main(int argc, char** argv)
{
  int numFlights;
  Flight *flights = readFlights(&numFlights);
  
  while(getChoice() != DONE)
    addPassenger(flights, numFlights);
  
  writeFlights(flights, numFlights);
  freeFlights(flights, numFlights);

  return 0;
} // main())


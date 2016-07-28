#include "flight.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilities.h"
FILE * createOpen()
{
  return fopen("reservations.txt", "r");

}// returns fileopen pointer

void firstLineParser(int *numFlights)
{
  FILE * file = fopen("reservations.txt", "r");
  char string[100];
  fgets(string,4, file);
  stringFix(string);
  *numFlights=atoi(string);
  fclose(file);
 
}//reading number of flights from the first line of the file

void fileParser(Flight *flights, int *numFlights)
{
  FILE *file = createOpen();
  
  
  
  fileParser(file,flights,numFlights);
}// passing to the reader function

void flightMenu(Flight *flights, int *numFlights)
{
  int num = 0;
  bool c= false;
  while(1)
  {
    printf("Flight number (0 = exit) :");
    scanf("%d",&num);
    c=checkFlight(flights,num, numFlights);
    if(!c)
    {
      printf("We dont have a flight number %d\n", num);
    }
    else
    {
      //printf("Plane specifics\n");
      flightDisplay(flights,numFlights);

      //Call Flight
      break;
    }


  }
}

int main(int argc, char **argv)
{
	int numFlights=0;
  firstLineParser(&numFlights);
 
	Flight *flights = (Flight*) malloc(sizeof(Flight) *numFlights);
  printf("ECS Flight Reservation Menu\n");
  printf("0. Exit\n");
  printf("1. Add Passenger.\n");
	while(1)
  {
	
   printf("Please enter your choice:");
   int choice=0;
   int flag=0;
   //int num=0;
   scanf("%d", &choice);
   switch(choice)
   {
   	case 0:
   	{
   		printf("Goodbye\n");
   		exit(0);

   	}
   	case 1:
   	{
      fileParser(flights,&numFlights);
      flightMenu(flights,&numFlights);
     

   	  //printf("Got here \n");
      break;
   	}
    
    default:
    {
      flag=1;
   }
   }
  if(flag == 1 )
   {printf("%d is not an available choice\n", choice);}
  }
//printf("here\n");
	
free(flights);
return 0;
}
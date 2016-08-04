#include "plane.h"

void planeCreate(Plane *plane, int rows, int width, int reserved)
{
	
	plane->rows = rows;
	plane->reserved = reserved;
	plane->width = width;

    
    
}
void planeDisplay(Plane *plane)
{
	printf("Rows: %d \n", plane->rows);
	printf("Width: %d \n", plane->width);
	printf("Reserved: %d \n", plane->reserved);


}
void planeUpdate(Plane *plane, char * seatLetter, char * passengerName)
{
  rowsize= sizeof(int)* plane->rows;
  colsize = sizeof(int)* plane->width;
  plane->(passengers)= (Plane ***) malloc(sizeof(char **) * plane->reserved); 
  
}

bool checkReserved(Plane *plane)
{

 	return false;
}

void rowDisplay(Plane *plane)
{
	printf("Row#\t AB\n");
	//bool answer= false;
	int c;
	for(int i=0; i<plane->rows; i++)
	{
	  c= i+1;
      printf("%d\n", c); 

      checkReserved(plane);
	}
}
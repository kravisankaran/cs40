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
void checkReserved

void rowDisplay(Plane *plane)
{
	printf("Row#\t AB\n");
	bool answer= false;
	int c;
	for(int i=0; i<plane->rows; i++)
	{
	  c= i+1;
      printf("%d", c); 
      checkReserved(plane);
	}
}
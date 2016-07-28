#ifndef FLIGHT_H
#define FLIGHT_H

#include "plane.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utilities.h"
#define FLIGHT_CHAR 20
typedef struct
{
 int flightNum;
 char origin[80];
 char destination[80];
 Plane *plane;
 
} Flight;
void fileParser(FILE *file, Flight *flights, int *num);
void lineParser(char * string, int i, int *numFlights, Flight *flights,int n);
int flightCount(int n);
bool checkforSpace(char * string);
void stringFix(char *string);
void printNumber(Flight *flights);
bool checkFlight(Flight *flights, int search, int *numFlights);
void flightDisplay(Flight *flights, int *numFlights);



#endif
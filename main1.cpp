#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "flight.h"
#define MAX_CHAR 80

int numFlights =1;
int flightNumber =0;
char  orgindesti[MAX_CHAR];
char finaldesti[MAX_CHAR];

void stringFix(char *string)
{

	int len = strlen(string)-1;
	while(len >= 0)
	{
     if(string[len] == '\n')
     {
     		string[len]='\0';
     		len --;
     }// if newline

     else if (string[len] == '\r')
     {
     		string[len] = '\0';
     		len --; 
     }// if carriage return

     else
     {	
     	 
     	  break;

     }// 

	}// while

}// fixing trailing newline and carriage return
bool checkforSpace(char * string)
{
  int len = strlen(string)-1;
  int i= 0;
  int ret = 0;
  bool flag = false;
  
  //strcpy(temp, "");
  while(i <= len)
  {
    if(isspace(string[i]))
    {
      ret = 1;
      break;
    }
    i++;
  }
  if(ret == 1)
  {
    flag = true;
  }
  else {flag = false;}
return flag;

}


void lineParser(char * string, int i, int numFlights, Flight **flights)
{
  char * pointer;
  pointer = strtok(string, "\n");
  if(i==1)
  {
    
    numFlights = atoi(pointer);
     printf("%d", numFlights);
  }
  else
  {
    if(isdigit(string[0]))
    {
       bool answer = checkforSpace(string);
       if(answer)
       {
        printf("Plane specifics \n");
       }
       else
       {
         pointer = strtok(string, "\n");
         //printf("%s\n", pointer);
         flightNumber = atoi(pointer);
         //printf("%d\n",flightNumber);
         //setFlightNumber(flightNumber);
       }
    }
  } 
  
}// parsing line

void fileParser(FILE *file, Flight **flights, int num)
{
	char *string = (char*) malloc (sizeof(char));
  strcpy(string, " ");
  int i =1;
	while(fgets(string, 100, file))
	{
    stringFix(string);
    //printf("%s at line %d \n", string, i);
    
    lineParser(string, i,num, flights); // to separate the words
    //printf("%d is the flightNumber for this iteration", flightNumber);

    i++;

	} // fgets while
  
	free(string);

}// parsing files

FILE * createOpen()
{
	return fopen("reservations.txt", "r");

}// returns fileopen pointer

int main(int argc, char **argv)
{
	
	
  //int * num = &numFlights;
	Flight **flights = (Flight*) malloc(sizeof(Flight) * numFlights + 1);
  FILE *file= createOpen();
  fileParser(file, flights, numFlights);
  free(flights);
  
	return 0;
}// main
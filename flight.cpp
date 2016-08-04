#include "flight.h"

/*void setFlightNumber(int flightNumber)
{
	flightNum=flightNumber;
	printf("%d", fli
  ghtNum);
}*/
void flightrowDisplay(Flight *flights, int num, int *numFlights)
{
  int number= *numFlights;
  for(int i=0; i<number; i++)
  {
    if(num == flights[i].flightNum)
      {
       rowDisplay(flights[i].plane);
       break;
     }

  }
 
}

bool checkFlight(Flight *flights, int search, int *numFlights)
{
  int num = *numFlights;
  int flag =0;
  bool ret= true;

  for(int i=0; i<num; i++)
  {
    if(search == flights[i].flightNum)
      {
       flag =1;
       break;
     }

  }
  if(flag == 0)
  {
    ret=false;
  }
  else {ret = true; }
return ret;
}


int flightCount(int n)
{
   
   n++;
   return n;
}


void lineParser(char * string, int i, int *numFlights, Flight *flights,int n)
{
  char * pointer;
  //pointer = NULL;
  static int c=0;
  static int d=0;
  static int e=0;
  static int f =0;
  static int flag=0;
  char seatLetter[80];
  char passengerName[80];
  int rows, width, reserved;
  pointer = strtok(string, "\n");
  if(i==1)
  {
  
   int num = atoi(pointer);

     
     *numFlights = num;
     
      
  }
  else	
  {
    if(isdigit(string[0]))
    {
    	//int a = *numFlights;
    	
    	//printf("the array allocation will be for %d elements\n", a);
       //flights = (Flight*) mall>oc(sizeof(Flight) *(*numFlights));
       bool answer = checkforSpace(string);
         
      
       if(answer)
       {
         flights[f].plane = (Plane*) malloc (sizeof(Plane));
         if(isspace(string[1]))
         {
           pointer = strtok(string, "\n");
           pointer = strtok(string, " ");
            rows = atoi(pointer);
          
           
           int flag =0;
           while(pointer!=NULL)
           {
             pointer = strtok(NULL, " ");
             flag++;
             if(flag == 1)
             {
              width = atoi(pointer);
              //printf("Width: %d \n", width);
             }
             else if (flag == 2) 
             {
               reserved = atoi(pointer);
               //printf("Reserved: %d \n", reserved);
             }

           }

            
             planeCreate(flights[f].plane, rows, width, reserved);
            f++;
            
            // havent freed plane
           }
           else 
           {
             pointer = strtok(string, "\n");
             pointer = strtok(string, " ");
             strcpy(seatLetter,pointer);
             pointer = strtok(NULL, "\n");
             strcpy(passengerName,pointer);
             planeUpdate(flights[f].plane,seatLetter, passengerName);
             
           }
           
        
       }

       else
       {
         pointer = strtok(string, "\n");
         //printf("%s\n", pointer);
         int flightNumber = atoi(pointer);
         
         flights[c++].flightNum = flightNumber;
         
        
         
         //setFlightNumber(flightNumber);
       }

    }
    else
    {
      
      pointer = strtok(string,"\n");
      if(flag == 0)
      {
         
         strcpy(flights[d].origin,pointer);
         
         d++;
         flag =1;
      }
      else if(flag==1)
      {
        
        strcpy(flights[e].destination,pointer);
         
         e++;

        flag =0;
      }
    }
  } 
  

}// parsing line
void flightDisplay(Flight *flights, int *numFlights)
{
  int num = *numFlights;
  for(int i= 0; i<num; i++)
  {
    planeDisplay(flights[i].plane);
  }
}

void printNumber(Flight *flights)
{
  printf("Flt#\t Origin\t\t Destination\n");
	for(int i =0; i < 4; i++)
    {
    	printf("%d\t ",flights[i].flightNum);
      printf("%s\t\t  ",flights[i].origin);
    	printf("%s\n", flights[i].destination);
      
    }

}
void fileParser(FILE *file, Flight *flights, int *num)
{
	char *string = (char*) malloc (sizeof(char));
	int n=-1;
  strcpy(string, " ");

  
    int i =1;
	while(fgets(string, 100, file))
	{
    stringFix(string);
    //printf("%s at line %d \n", string, i);
    
    lineParser(string, i,num, flights,n); // to separate the words
    //printf("%d is the flightNumber for this iteration", flightNumber);
     
    i++;
   

	} // fgets while
	printNumber(flights);
  
	free(string);

}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "plane.h"
#include "utilities.h"

#define TRUE 1


int Plane::addPassenger()
{
  int row, seatNum;
  char name[MAX_NAME_SIZE];
  
  if(reserved == rows * width)
    return 0;  // false
  
  cout << "Please enter the name of the passenger: ";
  cin.getline(name, MAX_NAME_SIZE);
  strtok(name, "\r\n");
  showGrid();
  
  while(TRUE)
  {
    row = getRow();
    cout << "Please enter the seat letter you wish to reserve: ";
    seatNum = cin.get() - FIRST_SEAT;

    while(cin.get() != '\n');

    if(passengers[row - FIRST_ROW][seatNum] == NULL)
      break;

    cout << "That seat is already occupied" << '\n' << "Please try again."<< endl;
  } // while occupied seat
  
  passengers[row - FIRST_ROW][seatNum] 
    = new char[(strlen(name) + 1)];
  strcpy(passengers[row - FIRST_ROW][seatNum], name);
  reserved++;
  return 1;
}  // addPassenger()

 Plane::~Plane()
{
  int row, seatNum;
  
  for(row = 0; row < rows; row++)
  {
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != NULL)
        delete passengers[row][seatNum];
    
    delete passengers[row];
  }  // for row
  
  delete [] passengers;
}  // freePlane


int Plane::getRow()
{
  int row;
  
  do
  {
    cout << "Please enter the row of the seat you wish to reserve: " << endl;
    row = getNumber();

    if(row == ERROR)
      cout << "That is an invalid row number." << "\n" << "Please try again." << endl;
    else  // valid row number
      if(row < 1 || row > rows)
        cout << "There is no row #" << row << "on this flight." << "\n" <<"Please try again." << endl;
  }  while(row < 1 || row > rows);
  
  return row;
} // getRow()

  
Plane::Plane(ifstream &inf)
{
  int row, numPassenger, seatNum;
  char seat, name[MAX_NAME_SIZE];
  inf >> rows >> width >> reserved;
  
  //fscanf(fp, "%d %d %d", &rows, &width, &reserved);
  //passengers = (char***) malloc(rows * sizeof(char**));
  passengers = new char**[(rows * sizeof(char**))];
  for(row = 0; row < rows; row++)
  {
    passengers[row] = new char* [(width * sizeof (char*))];
    
    for(seatNum = 0; seatNum < width; seatNum++)
      passengers[row][seatNum] = NULL;
  } // for each row
  
  for(numPassenger = 0; numPassenger < reserved; numPassenger++)
  {
    //fscanf(fp, "%d%c ", &row, &seat);
    inf >> row >> seat;

    //fgets(name, MAX_NAME_SIZE, fp);
    inf.getline(name, MAX_NAME_SIZE);
    
    seatNum = seat;
    passengers[row - FIRST_ROW][seatNum - FIRST_SEAT] 
      = new char [(strlen(name) + 1)];
    strcpy(passengers[row - FIRST_ROW][seatNum - FIRST_SEAT], name);
  }  // for each passenger
}  // readPlane()


void Plane::showGrid()
{
  int row, seatNum = 0;
  
  printf("ROW# ");
  
  for(seatNum = 0; seatNum < width; seatNum++)
    cout << seatNum + FIRST_SEAT;
  
  cout<< '\n' ;
  
  for(row = 0; row <rows; row++)
  {
    printf("%2d   ", row + 1);
    
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum])
        cout << 'X';
      else  // empty seat
        cout << '-';
    
    cout << endl;
  }  // for each row
  
  cout <<  "\nX = reserved.\n";
}  // showGrid()


void Plane::writePlane(ofstream &outf)
{
  int row, seatNum=0;
  outf << rows << ' ' << width << ' ' << reserved << endl;

  for(row = 0; row < rows; row++)
    for(seatNum = 0; seatNum < width; seatNum++)
      if(passengers[row][seatNum] != NULL)
        outf<< row + FIRST_ROW << char(seatNum + FIRST_SEAT) << ' ' << passengers[row][seatNum] << endl;
}  // readPlane()

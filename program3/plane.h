#ifndef PLANE_H
#define	PLANE_H
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_NAME_SIZE 80
#define FIRST_ROW 1
#define FIRST_SEAT 'A'


class Plane
{
  private:
  	int rows;
  	int width;
  	int reserved;
  	char ***passengers;
  	
    int getRow();
    void showGrid();

  public:
  int addPassenger();
  Plane(ifstream &inf);
  ~Plane();
  void writePlane(ofstream &outf);
} ;


#endif	// PLANE_H




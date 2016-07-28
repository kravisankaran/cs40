#ifndef PLANE_H
#define PLANE_H
#include <stdio.h>
#include <stdlib.h>



typedef struct
{
 int rows;
 int width;
 int reserved;
 char ***passengers; // 2-dimensional
} Plane;


void planeCreate(Plane *plane, int rows,int width, int reserved);
void planeDisplay(Plane *plane);

#endif
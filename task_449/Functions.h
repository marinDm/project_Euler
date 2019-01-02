#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double countY_z(double currZ);
double countDerivY_z(double currZ);
double countNormalFunc(double z0, double y0, double zCurr);
void countRingPoint(double z0, double y0, double h, double* ringArr);
double countFigVolume( int nSteps);

#endif // FUNCTIONS_H

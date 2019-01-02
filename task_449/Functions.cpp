#include "Functions.h"
#include "CommonVars.h"

using namespace std;

double countY_z(double currZ)
{
    double y;
    y = a * pow(1 - currZ*currZ / (b*b), 0.5 );
    return y;
}

double countDerivY_z(double z0)
{
    double dy;
    dy = ( -1.0 * a * z0 / (b*b) ) / pow(1 - z0*z0 / (b*b), 0.5 );
    return dy;
}

double countNormalFunc(double z0, double y0, double zCurr)
{
    double yCurr;
    yCurr = y0 + ( z0 - zCurr) / countDerivY_z(z0);

    return yCurr;
}

void countRingPoint(double z0, double y0, double h, double* ringArr)
{
    double yRing, zRing, yTemp, zTemp;
    double normAng;
    double delta;

    delta = 1;

    zTemp = z0 + delta;
    yTemp = countNormalFunc( z0, y0, zTemp);

    normAng = delta / pow( delta*delta + (yTemp - y0)*(yTemp - y0), 0.5);     // acosl

    if( z0 < 0)
    {
        zRing = -1.0 * h * normAng + z0;
    }
    else
    {
        zRing = h * normAng + z0;
    }

    yRing = countNormalFunc( z0, y0, zRing);
    ringArr[0] = zRing;
    ringArr[1] = yRing;
}

double countFigVolume( int nSteps)
{
    double step =  2* b / ( (float)nSteps);
    double yCurr, zCurr;
    double* ringArr[nSteps];
    for(int i = 0; i < nSteps; i++)
    {
        ringArr[i] = new double[2];
    }

    double h = 1.0;
    double volume = 0;

    for( int i = 0; i < nSteps; i++)
    {
        zCurr = -b + i * step;
        yCurr = countY_z( zCurr );
        countRingPoint( zCurr, yCurr, h, ringArr[i]);
    }

    for(int i = 0; i < nSteps - 1; i++)
    {
        volume += M_PI * ringArr[i][1]*ringArr[i][1] * fabs(ringArr[i + 1][0] - ringArr[i][0]);
    }

    return volume;
}

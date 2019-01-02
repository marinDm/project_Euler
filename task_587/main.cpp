#include <math.h>
#include <stdio.h>

using namespace std;

double calcYVal(double rad, double x0);
double findIntersection(int numCirc, double R);
double calcConcTriangSquare(int nSteps, double R, double xMin, double xMax);

double calcYVal(double rad, double x0)
{
    double y0;
    y0 = -1.0 * sqrt(rad*rad - x0*x0);
    return y0;
}

double findIntersection(int numCirc, double R)
{
    double D, x1, x2;
    double a, b, c;

    a = 1.0 + numCirc*numCirc;
    b = 2 * (R - R*numCirc);
    c = R*R - 2*R*R*numCirc;

    D = b*b - 4*a*c;
    x1 = (-b + sqrt(D) )/ (2*a);
    x2 = (-b - sqrt(D) )/ (2*a);

    if(x1 < 0)
    {
        return x1;
    }
    else
    {
        return x2;
    }
}

double calcConcTriangSquare(int nSteps, double R, double xMin, double xMax)
{
    double square = 0;
    double step;
    step = (xMax - xMin)/ nSteps;

    for(int i = 0; i < nSteps; i++)
    {
        square+= step * (R + ( -sqrt(R*R - (xMin + i*step)*(xMin + i*step)) ));
    }

    return square;
}

int main()
{
    double R = 1.0;
    int nSteps = 100000;

    double sqLSec, sqTriang, sqConcTr;
    double xInters, yInters;

    double perc = 100;
    int N = 0;

    while(perc >= 0.1)
    {
        N++;
        xInters = findIntersection( N, R);
        yInters = calcYVal( R, xInters);

        sqLSec = (4.0*R*R - M_PI*R*R) / 4.0;
        sqTriang = 0.5* fabs(-R - xInters)* fabs(-R - yInters);
        sqConcTr = calcConcTriangSquare( nSteps, R, xInters, 0);

        perc = (sqTriang + sqConcTr)/ sqLSec * 100;
    }

    printf("N= %d\n", N);

    return 0;
}


#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

double getIncAng(double kBeam, double bBeam, double kTang, double bTang);
double getReflLine(double incAng, double kTang, double x1, double y1, double* kRefl, double* bRefl);
double getElipseFuncValPos(double x);
double getElipseFuncValNeg(double x);
void getBeamLine(double x1, double x2, double y1, double y2, double* k, double* b);
void getTangLine(double x1, double y1, double* k, double* b);


double getIncAng(double kBeam, double bBeam, double kTang, double bTang)
{
    double incAng;
    incAng = atan( (kBeam - kTang)/ (1 + kBeam*kTang) );
    return incAng;
}

double getReflLine(double incAng, double kTang, double x1, double y1, double* kRefl, double* bRefl)
{
    double refAng;
    refAng = M_PI - incAng + atan(kTang);
    *kRefl = tan(refAng);
    *bRefl = y1 - (*kRefl) * x1;
    return refAng;
}

double getElipseFuncValPos(double x)
{
    double yVal;
    yVal = sqrt(100 - 4*x*x);
    return yVal;
}

double getElipseFuncValNeg(double x)
{
    double yVal;
    yVal = -sqrt(100 - 4*x*x);
    return yVal;
}

void getBeamLine(double x1, double x2, double y1, double y2, double* k, double* b)
{
    *k = (y2 - y1) / (x2 - x1);
    *b = y1 - (*k) * x1;
}

void getTangLine(double x1, double y1, double* k, double* b)
{
    *k = -4 * x1 / y1;
    *b = y1 - (*k) * x1;
}

int getIntersection(double kRefl, double bRefl, double X0, double Y0, double* outX, double* outY)
{
    double D, x1, x2, y1, y2;
    D = 4.0 * kRefl*kRefl * bRefl*bRefl - 4.0 * (4.0 + kRefl*kRefl) * (bRefl*bRefl - 100);
    if(D >= 0)
    {
        x1 = (-2.0*kRefl*bRefl + sqrt(D) ) / (2.0 * (4.0 + kRefl*kRefl));
        x2 = (-2.0*kRefl*bRefl - sqrt(D) ) / (2.0 * (4.0 + kRefl*kRefl));

        if(fabs(x1 - X0) < 0.000001 )
        {
            *outX = x2;
            y1 = getElipseFuncValPos(x2);
            y2 = getElipseFuncValNeg(x2);

            if( y1 - kRefl*x2 - bRefl < 0.000001)
            {
                *outY = y1;
            }
            else
            {
                *outY = y2;
            }
        }
        else
        {
            *outX = x1;
            y1 = getElipseFuncValPos(x1);
            y2 = getElipseFuncValNeg(x1);

            if( y1 - kRefl*x1 - bRefl < 0.000001)
            {
                *outY = y1;
            }
            else
            {
                *outY = y2;
            }
        }

        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    double x0 = 0.0, y0 = 10.1;
    double x1 = 1.4, y1 = -9.6;
    double xInters, yInters;

    double kBeam, bBeam;
    double kTang, bTang;
    double incAng, reflAng;
    double kRefl, bRefl;
    int resInters;

    getBeamLine(x0, x1, y0, y1, &kBeam, &bBeam);

    int i = 0;

    while(true)
    {
        getTangLine(x1, y1, &kTang, &bTang);
        incAng = getIncAng(kBeam, bBeam, kTang, bTang);
        reflAng = getReflLine(incAng, kTang, x1, y1, &kRefl, &bRefl);
        resInters = getIntersection( kRefl, bRefl, x1, y1, &xInters, &yInters);

        x1 = xInters;
        y1 = yInters;
        kBeam = kRefl;
        bBeam = bRefl;

        if( fabs(xInters) <= 0.01 && yInters > 0)
        {
            printf("i= %d\n", i+1);
            printf("xInt= %f yInt= %f\n", xInters, yInters);
            break;
        }
        i++;
    }

    return 0;
}

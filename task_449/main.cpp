#include "Functions.h"
#include "CommonVars.h"

using namespace std;

int main()
{
    double fullVolume, layerVolume;

    fullVolume = countFigVolume( 500000);
    layerVolume = fullVolume - 4.0 * M_PI * a*a * b/3.0;

    printf("fullVol= %f\t layerVol= %.9f\n", fullVolume, layerVolume);
    return 0;
}


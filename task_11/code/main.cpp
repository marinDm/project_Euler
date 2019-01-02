#include "functions.h"

int main(int argc, char *argv[])
{
    int size = 20;
    int maxProd;
    char digCharArr[size*size*2];
    int digIntArr[size*size];

    readNumbers(size*2, digCharArr);
    convertCharToInt(digCharArr, size*size*2, digIntArr);
    maxProd = checkProduct(4, digIntArr, size);

    printf("maxProd = %d\n", maxProd);

    return 0;
}

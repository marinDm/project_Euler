#include "functions.h"

int main()
{
    int size = 1000;
    int prodSize = 13;
    long long int maxProd;
    int digArr[size];

    readNumbers(size, digArr);
    maxProd = checkProduct(prodSize, digArr, size);

    printf("maxProd= %lld\n", maxProd);

    return 0;
}

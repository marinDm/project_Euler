#include "functions.h"

void readNumbers(int size, int* digArr)
{
    std::ifstream ifs("..\\data\\digits.txt");
    char temp;

    for(int i = 0; i < size; i++)
    {
        ifs >> temp;
        digArr[i] = temp - '0';
    }
}

long long int checkProduct(int prodSize, int* digArr, int size)
{
    long long int tempProd = 1;
    long long int maxProd = 0;
    int maxIndex;

    for(int j = 0; j < size - prodSize; j++)
    {
        for(int k = 0; k < prodSize; k++)
        {
            tempProd *= digArr[j + k];

            if(maxProd < tempProd)
            {
                maxProd = tempProd;
                maxIndex = j;
            }
        }
        tempProd = 1;
    }
    printf("maxIndex= %d\n", maxIndex );
    return maxProd;
}

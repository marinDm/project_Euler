#include "functions.h"

void readNumbers(int size, char* digArr)
{
    std::ifstream ifs("..\\data\\numbers.txt");

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            ifs >> digArr[i * 40 + j];
        }
    }
}

void convertCharToInt(char* digCharArr, int size, int* digIntArr)
{
    string tempStr;

    for(int i = 0; i < size / 2; i++)
    {
        tempStr.push_back( digCharArr[2*i]);
        tempStr.push_back( digCharArr[2*i+1]);
        digIntArr[i] = stoi(tempStr);
        tempStr.clear();
    }
}

int checkProduct(int prodSize, int* digIntArr, int size)
{
    int tempProd = 1;
    int maxProd = 0;
    int maxIndex[2];

// horizontally
    for(int j = 0; j < size; j++)
    {
        for(int i = 0; i < size - prodSize; i++)
        {
            for(int k = 0; k < prodSize; k++)
            {
                tempProd *= digIntArr[j*size + i +k];
                if(maxProd < tempProd)
                {
                    maxProd = tempProd;
                    maxIndex[0] = j;
                    maxIndex[1] = i;
                }
            }
            tempProd = 1;
        }
    }

// vertically
    for(int j = 0; j < size; j++)
    {
        for(int i = 0; i < size - prodSize; i++)
        {
            for(int k = 0; k < prodSize; k++)
            {
                tempProd *= digIntArr[(i+k) * size + j];
                if(maxProd < tempProd)
                {
                    maxProd = tempProd;
                    maxIndex[0] = j;
                    maxIndex[1] = i;
                }
            }
            tempProd = 1;
        }
    }

// diagonal forward
    for(int j = 0; j < size - prodSize; j++)
    {
        for(int i = 0; i < size - prodSize; i++)
        {
            for(int k = 0; k < prodSize; k++)
            {
                tempProd *= digIntArr[(i+k) * size + j+k];
                if(maxProd < tempProd)
                {
                    maxProd = tempProd;
                    maxIndex[0] = j;
                    maxIndex[1] = i;
                }
            }
            tempProd = 1;
        }
    }

// diagonal reverse
    for(int j = prodSize - 1; j < size; j++)
    {
        for(int i = 0; i < size - prodSize; i++)
        {
            for(int k = 0; k < prodSize; k++)
            {
                tempProd *= digIntArr[(i+k) * size + j-k];
                if(maxProd < tempProd)
                {
                    maxProd = tempProd;
                    maxIndex[0] = j;
                    maxIndex[1] = i;
                }
            }
            tempProd = 1;
        }
    }

    return maxProd;
}

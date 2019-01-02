#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void readNumbers(int size, char* digArr);
void convertCharToInt(char* digCharArr, int size, int* digIntArr);
int checkProduct(int prodSize, int* digIntArr, int size);

#endif // FUNCTIONS_H

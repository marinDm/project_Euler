#include <stdio.h>

int main(int argc, char *argv[])
{
    long long int sumSq = 0;
    long long int sqSum = 0;
    long long int diff;
    int N = 100;
    int i;

    for(i = 0; i <= N; i++)
    {
        sumSq += i*i;
        sqSum += i;
    }

    sqSum = sqSum*sqSum;
    diff = sqSum - sumSq;
    printf("difference= %d\n", diff);

    return 0;
}

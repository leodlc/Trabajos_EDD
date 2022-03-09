#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int findSum(int A[], int N)
{
    if (N <= 0)
        return 0;
    return (findSum(A, N - 1) + A[N - 1]);
}

// Driver code
int main()
{
    int n;
    int** arreglo;

    cout << "Ingrese la dimension: " << endl;
    cin >> n;
    //arreglo = (int*)malloc(n * sizeof(int));
    
    arreglo = (int**)malloc(n * sizeof(int*));
    for (int j = 0; j < n; j++) {
        *(arreglo + j) = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                *(*(arreglo + i) + j) = 0;
            }
        }
    }


    
    
    return 0;
}

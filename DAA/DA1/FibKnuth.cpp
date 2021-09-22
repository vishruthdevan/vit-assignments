#include <iostream>

using namespace std;

int** knuthsquare(int** F){
    int a = F[0][0] * F[0][0];
    int b = F[0][1] * F[0][1];
    int c = F[1][1] * F[1][1];

    int** mat = new int*[2];
    mat[0] = new int[2];
    mat[1] = new int[2];

    mat[0][0] = a + b;
    mat[0][1] = a - c;
    mat[1][0] = a - c;
    mat[1][1] = b + c;

    return mat;
}

int** multiply(int** F, int** A){
    int** mat = new int*[2];
    mat[0] = new int[2];
    mat[1] = new int[2];

    int x = F[0][0] * A[0][0] +
            F[0][1] * A[1][0];
    int y = F[0][0] * A[0][1] +
            F[0][1] * A[1][1];
    int z = F[1][0] * A[0][0] +
            F[1][1] * A[1][0];
    int w = F[1][0] * A[0][1] +
            F[1][1] * A[1][1];

    mat[0][0] = x;
    mat[0][1] = y;
    mat[1][0] = z;
    mat[1][1] = w;

    return mat;
}


int** fib(int** A, int n){
    if(n==1){
        return A;
    }

    if(n%2==0){
        int** F = fib(A, n/2);
        return knuthsquare(F);
    }

    else{
        int** F = fib(A, (n-1)/2);
        return (knuthsquare(F), A);
    }
}

int main(){
    int** A = new int*[2];
    A[0] = new int[2];
    A[1] = new int[2];
    
    A[0][0] = A[0][1] = A[1][0] = 1;
    A[1][1] = 0;

    int** F = fib(A, 4);
    cout << "fib(4) = "  << F[0][1];
}
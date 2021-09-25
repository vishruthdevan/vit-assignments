#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> knuthsquare(vector<vector<int>> F){
    int a = F[0][0] * F[0][0];
    int b = F[0][1] * F[0][1];
    int c = F[1][1] * F[1][1];

    vector<vector<int>> mat{vector<int>(2), vector<int>(2)};
    mat[0][0] = a + b;
    mat[0][1] = a - c;
    mat[1][0] = a - c;
    mat[1][1] = b + c;

    return mat;
}

vector<vector<int>> multiply(vector<vector<int>> F, vector<vector<int>> A){
    vector<vector<int>> mat{vector<int>(2), vector<int>(2)};

    int x = F[0][0] * A[0][0] + F[0][1] * A[1][0];
    int y = F[0][0] * A[0][1] + F[0][1] * A[1][1];
    int z = F[1][0] * A[0][0] + F[1][1] * A[1][0];
    int w = F[1][0] * A[0][1] + F[1][1] * A[1][1];

    mat[0][0] = x;
    mat[0][1] = y;
    mat[1][0] = z;
    mat[1][1] = w;

    return mat;
}


vector<vector<int>> fib(vector<vector<int>> A, int n){
    if(n==1){
        return A;
    }

    if(n%2==0){
        vector<vector<int>> F = fib(A, n/2);
        return knuthsquare(F);
    }

    else{
        return multiply(knuthsquare(fib(A, (n-1)/2)), A);
    }
}

int main(){
    vector<vector<int>> A{{1, 1}, {1, 0}};
    cout << "\nfib(0) = 0\n";
    for(int i=1; i<=10; i++){
        vector<vector<int>> F = fib(A, i);
        printf("fib(%d) = %d\n", i, F.at(0).at(1));
    }
    cout << "\n";
    return 0;
}
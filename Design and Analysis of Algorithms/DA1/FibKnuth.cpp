#include<iostream>

void matmul(int a[2][2], int m[2][2]){
    int w = a[0][0] * m[0][0] + a[0][1] * m[1][0];
    int x = a[0][0] * m[0][1] + a[0][1] * m[1][1];
    int y = a[1][0] * m[0][0] + a[1][1] * m[1][0];
    int z = a[1][0] * m[0][1] + a[1][1] * m[1][1];

    a[0][0] = w;
    a[0][1] = x;
    a[1][0] = y;
    a[1][1] = z;
}

void recur(int a[2][2], int n){
    if (n==0 || n==1)
        return;
    int m[][2] = {{1, 1}, {1, 0}};

    recur(a, n/2);
    matmul(a, m);

    if(n%2!=0){
        matmul(a, m);
    }
}

int fib(int n){
    int a[][2] = {{1, 1}, {1, 0}};
    if(n==0)
        return n;
    recur(a, n-1);
    return a[0][0]; 
}

int main(){
    std::cout<<fib(4);
}
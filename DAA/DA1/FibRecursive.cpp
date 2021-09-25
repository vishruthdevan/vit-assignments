#include<iostream>

using namespace std;

int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return fib(n-1) + fib (n-2); 
}

int main(){
    cout << "\n";
    for(int i=0; i<10; i++){
        printf("fib(%d) = %d\n", i, fib(i));
    }
    cout << "\n";
    return 0;
}
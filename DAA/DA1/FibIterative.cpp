#include<iostream>

using namespace std;

int fib(int n){
    int fn = 1, prev = 1, temp;
   
    for(int i=0; i<n-2; i++){
        temp = fn;
        fn = fn + prev;
        prev = temp;
    }

    return fn;
}

int main(){
    cout << "fib(0) = 0\n";
    for(int i=1; i<=10; i++){
        printf("fib(%d) = %d\n", i, fib(i));
    }
    return 0;
}
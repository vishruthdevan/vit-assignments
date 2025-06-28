#include<iostream>

using namespace std;

int fib(int n){
    int fn = 0, prev = 1;;
   
    for(int i=0; i<n-2; i++){
        fn = fn + prev;
        prev = fn ;
    }

    return fn;
}

int main(){
    cout << fib(4);
    return 0;
}
#include<iostream>
#include<cmath>

using namespace std;

double phi = (sqrt(5) + 1)/2;

double fib(int n){
    if (n == 2)
        return phi*phi;
    else if (n%2 == 0)
        return pow(fib(n/2), 2);
    else
        return pow(fib(n/2), 2)*phi;
}

int main(){
    cout << "fib(4) = " << round(fib(4)/sqrt(5));
}
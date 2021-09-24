#include<iostream>
#include<cmath>

using namespace std;

double phi = (sqrt(5) + 1)/2;

double fib(int n){
    if (n == 1)
        return phi;
    else if (n%2 == 0)
        return pow(fib(n/2), 2);
    else
        return pow(fib(n/2), 2)*phi;
}

int main(){
    for(int i=1; i<=10; i++)
    printf("%d\n", (int)round(fib(i)/sqrt(5)));
    return 0;
}
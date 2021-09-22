#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void MinMaxIterative(vector<int> &arr){
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i : arr){
        if(i<min) min=i;
        if(i>max) max=i;
    }
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
}

int main(){
    vector<int> arr{12, 23, 34, 45, 56, 67, 78, 89, 90};
    MinMaxIterative(arr);
    return 0;
}
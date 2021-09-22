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
    vector<int> arr{67, 78, 12, 23, 89, 90, 90, 89, 56, 178};
    MinMaxIterative(arr);
    return 0;
}

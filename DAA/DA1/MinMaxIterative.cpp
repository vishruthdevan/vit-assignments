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
    cout << "\nMinimum: " << min << endl;
    cout << "Maximum: " << max << endl;
}

int main(){
    vector<int> arr1{67, 78, 12, 23, 89, 90, 90, 89, 56, 178};
    vector<int> arr2{34, 46, 12, 865, 23474, 1231, 8531, 562321, 7474, 1};
    cout << "\n";
    for(auto i: arr1)
        cout << i << " ";
    MinMaxIterative(arr1);

    cout << "\n\n";
    for(auto i: arr2)
        cout << i << " ";
    MinMaxIterative(arr2);
    cout << "\n";
    return 0;
}

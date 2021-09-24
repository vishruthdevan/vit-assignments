#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void MinMaxDaC(vector<int> &arr, int &min, int &max, int low, int high){
    if(low==high){
        min = arr[low];
        max = arr[low];
        return;
    }

    if(low==high-1){
        if(arr[low]<=arr[high]){
            min = arr[low];
            max = arr[high];
        }
        if(arr[low]>arr[high]){
            min = arr[high];
            max = arr[low];
        }
        return;
    }

    else{
        int mid = (high + low) / 2;
        int min1 = INT_MAX;
        int max1 = INT_MIN;
        int min2 = INT_MAX;
        int max2 = INT_MIN;
        MinMaxDaC(arr, min1, max1, low, mid);
        MinMaxDaC(arr, min2, max2, mid+1, high);
        min = (min1 < min2)? min1:min2;
        max = (max1 > max2)? max1:max2;
    }
}

int main(){
    vector<int> arr1{67, 78, 12, 23, 89, 90, 90, 89, 56, 178};
    int min = INT_MAX;
    int max = INT_MIN;
    for(auto i: arr1)
        cout << i << " ";
    MinMaxDaC(arr1, min, max, 0, 9);
    cout << "\nMinimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    cout << "\n\n";
    vector<int> arr2{34, 46, 12, 865, 23474, 1231, 8531, 562321, 7474, 1};
    min = INT_MAX;
    max = INT_MIN;
    for(auto i: arr2)
        cout << i << " ";
    MinMaxDaC(arr2, min, max, 0, 9);
    cout << "\nMinimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    return 0;
}
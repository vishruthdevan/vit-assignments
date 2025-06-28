#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void minmax(vector<int> &arr, int &min, int &max, int low, int high){
    if(low==high){
        min = arr[low];
        max = arr[low];
        return;
    }

    if(low==high-1){
        if(arr[low]<arr[high]){
            if(arr[low]<min)
                min = arr[low];
            if(arr[high]>max)
                max = arr[high];
        }
        if(arr[low]>arr[high]){
            if(arr[high]<min)
                min = arr[high];
            if(arr[low]>max)
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
        minmax(arr, min1, max1, low, mid);
        minmax(arr, min2, max2, mid+1, high);
        min = (min1 < min2)? min1:min2;
        max = (max1 > max2)? max1:max2;
    }
}

int main(){
    vector<int> arr{12, 23, 34, 45, 56, 67, 78, 89, 90};
    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::lowest();
    minmax(arr, min, max, 0, 3);
    cout << min << " " << max;
    return 0;
}
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int condition(vector<int> x, vector<int> y){
    int xmax = *(max_element(x.begin(), x.end()));
    int ymin = *(max_element(y.begin(), y.end()));
    if(xmax<ymin){
        return 1;
    }
    else{
        return 2;
    }
    return 0;
}


void partition(vector<vector<int>> set){

}


int main(){
    cout << condition(vector<int>{1, 2, 4}, vector<int>{5, 6, 7});
}


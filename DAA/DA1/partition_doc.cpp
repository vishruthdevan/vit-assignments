#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>> deleteIndex;

bool lesserthan(vector<int> x, vector<int> y){
    bool cond1 = true, cond2 = false;
    for(int i=0; i<x.size(); i++){
        if(x[i] > y[i]){
            cond1 = false;
            break;
        }
        if(x[i] < y[i])
            cond2 = true;
    }
    return (cond1 && cond2);
}

bool greaterthan(vector<int> x, vector<int> y){
    bool cond1 = true, cond2 = false;
    for(int i=0; i<x.size(); i++){
        if(x[i] < y[i]){
            cond1 = false;
            break;
        }
        if(x[i] > y[i])
            cond2 = true;
    }
    return (cond1 && cond2);
}

void merge(vector<vector<vector<int>>> &f, int left, int mid, int right){
    int len1 = mid - left + 1;
    int len2 = right - mid;

    vector<vector<vector<int>>> leftSet(len1);
    vector<vector<vector<int>>> rightSet(len2);

    for (int i = 0; i < len1; i++)
        leftSet[i] = f[left + i];
    for (int j = 0; j < len2; j++)
        rightSet[j] = f[mid + 1 + j];

    int i=0, j=0, k=left;

    while(i<len1 && j<len2){
        if(lesserthan(rightSet[j].front(), leftSet[i].front())){
            f[k] = leftSet[i];
            i++;
        }
        else if(greaterthan(rightSet[j].front(), leftSet[i].front())){
            f[k] = rightSet[j];
            j++;
        }

        else{
            f[k] = leftSet[i];
            f[k].push_back(rightSet[j].front());
            deleteIndex.push_back(rightSet[j].front());
            i++;
            j++;
        }
        k++;
    }

    while (i < len1) {
        f[k] = leftSet[i];
        i++;
        k++;
    }

    while (j < len2) {
        f[k] = rightSet[j];
        j++;
        k++;
    }
}


void partition2(vector<vector<vector<int>>> &f, int left, int right){
    if (left>=right)
        return;
    int mid = (left+right)/2;
    partition2(f, left, mid);
    partition2(f, mid+1, right);
    merge(f, left, mid, right);
}

int main(){
    vector<vector<int>> set{vector<int>{22, 4, 4}, vector<int>{23, 2, 4}, vector<int>{67, 6, 4},  vector<int>{67, 5, 4}};
    vector<vector<vector<int>>> f;
    for(auto i: set){
        f.push_back(vector<vector<int>>{i});
    }
    partition2(f, 0, 3);
    int count = 1;

    for(auto i: deleteIndex){
        auto it = find(f.begin(), f.end(), vector<vector<int>>{i});
        f.erase(it);
    }

    for(auto i:f){
        cout << "------F" << count << "------" << endl;
        for(auto j:i){
            for(auto k:j){
                cout << k << "    ";
            }
            cout << "\n";
        }
        cout << "--------------\n\n\n";
        count++;
    }
}
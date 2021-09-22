/*
Consider a set of points A = {p1, p2, . . . , pn} where pi ∈ IRd
and d > 1, ∀i = 1, . . . , n.
Two points pi and pj are compared as follows:
We say pi ≻ pj if the following conditions hold
1. pi[k] ≥ pj[k], ∀k ∈ {1, 2, . . . , d}
2. ∃k ∈ {1, 2, . . . , d} such that pi[k] > pj[k]
and if any of the above condition fails then alternatively, if the following conditions hold, we say pi ≺ pj
1. pi[k] ≤ pj[k] ∀k ∈ {1, 2, . . . , d}
2. ∃k ∈ {1, 2, . . . , d} such that pi[k] < pj[k]
Further if pi ≻ pj and pi ≺ pj both are not true, then pi and pj are not comparable.
1. Design an algorithm to partition the points into distinct sets F1, F2, F3 . . . Fr, where, each
set Fi (∀i = {1, 2, . . . r}) consists of points which are not comparable to each other. Also,∀p ∈ Fi ≻ ∀q ∈ Fj, ∀i < j
2. Discuss the time complexity of the algorithm in terms of n and d.
*/


#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int lessthan(vector<int> x, vector<int> y){
    bool cond1 = true, cond2 = false;
    for(int i=0; i<x.size(); i++){
        if(x[i] > y[i]){
            cond1 = false;
            break;
        }
        if(x[i] < y[i])
            cond2 = true;
    }
    if(cond1 && cond2)
        return true;
    else
        return false;
}

int greaterthan(vector<int> x, vector<int> y){
    bool cond1 = true, cond2 = false;
    for(int i=0; i<x.size(); i++){
        if(x[i] < y[i]){
            cond1 = false;
            break;
        }
        if(x[i] > y[i])
            cond2 = true;
    }
    if(cond1 && cond2)
        return true;
    else
        return false;
}

void partition(vector<vector<int>> set){
    vector<vector<vector<int>>> f;
    int i=0;
    for(int p=0; p<set.size(); p++){
        if(f.size()==0){
            f.push_back(vector<vector<int>>{set[p]});
        }

        else{
            for(int i = 0; i < f.size(); i++){
                if(lessthan(set[p], f[i].front())){
                    f.insert(f.begin() + i, vector<vector<int>>{set[p]});
                    break;
                }
                else if(greaterthan(set[p], f[i].front())){
                    continue;
                }
                else{
                    f[i].push_back(set[p]);
                    break;
                }
                
            }
        }
    }

    for(auto i:f){
        cout << "-----------" << endl;
        for(auto j:i){
            cout << "---" << endl;
            for(auto k:j){
                cout << k << endl;
            }
            cout << "---" << endl;
        }
    }
}

int main(){
    vector<vector<int>> set{vector<int>{67, 6, 4}, vector<int>{67, 5, 4}, vector<int>{23, 2, 4}, vector<int>{22, 4, 4}};
    partition(set);
}


// vector<int> set2{67, 2, 4, 23, 3, 6};
// vector<vector<vector<int>>> f;

// void merge(vector<vector<int>> &set, int left, int mid, int right){
//     int len1 = mid - left + 1;
//     int len2 = right - mid;

//     vector<vector<int>> leftSet(len1);
//     vector<vector<int>> rightSet(len2);

//     for (int i = 0; i < len1; i++)
//         leftSet[i] = set[left + i];
//     for (int j = 0; j < len2; j++)
//         rightSet[j] = set[mid + 1 + j];

//     int i=0, j=0, k=left;

//     while(i<len1 && j<len2){
//         if(lessthan(leftSet[i], rightSet[j])){
//             set[k] = leftSet[i];
//             i++;
//         }
//         else if(greaterthan(leftSet[i], rightSet[j])){
//             set[k] = rightSet[j];
//             j++;
//         }

//         else{
//             set[k] = leftSet[i];
//             i++;
//         }
//         // if (leftSet[i] <= rightSet[j]) {
//         //     set[k] = leftSet[i];
//         //     i++;
//         // } else {
//         //     set[k] = rightSet[j];
//         //     j++;
//         // }
//         k++;
//     }

//     while (i < len1) {
//         set[k] = leftSet[i];
//         i++;
//         k++;
//     }

//     while (j < len2) {
//         set[k] = rightSet[j];
//         j++;
//         k++;
//     }
// }


// void partition2(vector<vector<int>> &set, int left, int right){
//     if (left>=right)
//         return;
//     int mid = (left+right)/2;
//     partition2(set, left, mid);
//     partition2(set, mid+1, right);
//     merge(set, left, mid, right);
// }


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

void partition(vector<vector<int>> set){
    vector<vector<vector<int>>> f;
    int i=0;
    f.push_back(vector<vector<int>>{set[0]});
    for(int p=1; p<set.size(); p++){
        for(int i=0; i < f.size(); i++){
            bool cond1 = greaterthan(set[p], f[i].front());
            bool cond2 = lesserthan(set[p], f[i].front());
            if(cond1){
                f.insert(f.begin() + i, vector<vector<int>>{set[p]});
                break;
            }
            else if(cond2){
                if(f.size()-1 == i){
                    f.push_back(vector<vector<int>>{set[p]});
                    break;
                }
                continue;
            }
            else if(!cond1 && !cond2){
                f[i].push_back(set[p]);
                break;
            }
            //f.push_back(vector<vector<int>>{set[p]});
        }
    }
    int count = 1;
    for(auto i:f){
        cout << "\n\n------F" << count << "------" << endl;
        for(auto j:i){
            for(auto k:j){
                cout << k << "    ";
            }
            cout << "\n";
        }
        cout << "--------------\n";
        count++;
    }
}



// void merge(vector<vector<vector<int>>> &f, int left, int mid, int right){
//     int len1 = mid - left + 1;
//     int len2 = right - mid;

//     vector<vector<vector<int>>> leftSet(len1);
//     vector<vector<vector<int>>> rightSet(len2);

//     for (int i = 0; i < len1; i++)
//         leftSet[i] = f[left + i];
//     for (int j = 0; j < len2; j++)
//         rightSet[j] = f[mid + 1 + j];

//     int i=0, j=0, k=left;

//     while(i<len1 && j<len2){
//         if(lesserthan(rightSet[j].front(), leftSet[i].front())){
//             f[k] = leftSet[i];
//             i++;
//         }
//         else if(greaterthan(rightSet[j].front(), leftSet[i].front())){
//             f[k] = rightSet[j];
//             j++;
//         }

//         else{
//             f[k] = leftSet[i];
//             f[k].push_back(rightSet[j].front());
//             f.erase(f.begin() + (mid + 1 + j));
//             i++;
//             j++;
//         }
//         k++;
//     }

//     while (i < len1) {
//         f[k] = leftSet[i];
//         i++;
//         k++;
//     }

//     while (j < len2) {
//         f[k] = rightSet[j];
//         j++;
//         k++;
//     }
// }


// void partition2(vector<vector<vector<int>>> &f, int left, int right){
//     if (left>=right)
//         return;
//     int mid = (left+right)/2;
//     partition2(f, left, mid);
//     partition2(f, mid+1, right);
//     merge(f, left, mid, right);
// }

int main(){
    vector<vector<int>> set{vector<int>{67, 6, 4}, vector<int>{67, 5, 4}, vector<int>{23, 2, 4}, vector<int>{22, 4, 4}};
    vector<vector<vector<int>>> f;
    for(auto i: set){
        f.push_back(vector<vector<int>>{i});
    }
    partition(set);
    cout << "\n\n---------------------------------\n\n\n";
    // partition2(f, 0, 3);
    int count = 1;
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
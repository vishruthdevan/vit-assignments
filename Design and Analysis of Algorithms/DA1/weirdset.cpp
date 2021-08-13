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



int main(){
    // if(!lessthan(vector<int>{1, 2, 4}, vector<int>{1, 2, 4}) &&
    // !greaterthan(vector<int>{1, 2, 4}, vector<int>{1, 2, 4})){
    //     cout << "yes";
    // };

    partition(vector<vector<int>>{vector<int>{67, 2, 4}, vector<int>{67, 2, 4}, vector<int>{23, 2, 4}});
}


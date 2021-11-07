#include <iostream>
#include <vector>
#include<string>

using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

void print(vector<vector<int>> C, vector<vector<char>> direction, string s, int i, int j){
    if(i==0 || j==0)
        return;
    if(direction[i][j] == 'c'){
        print(C, direction, s, i-1, j-1);
        cout << s[i-1];
    }
    else if(direction[i][j] == 'u'){
        print(C, direction, s, i-1, j);
    }
    else
        print(C, direction, s, i, j-1);
}

void lcs(string s1, string s2){

    int len1 = s1.length();
    int len2 = s2.length();

    vector<vector<int>> C(len1+1, vector<int>(len2+1));
    vector<vector<char>> direction(len1+1, vector<char>(len2+1));
    // direction is useful when printing out the longest subsequence
    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0 || j==0){
                C[i][j] = 0;
            }
            else if (s1[i-1] == s2[j-1]){
                C[i][j] = C[i-1][j-1] + 1;
                direction[i][j] = 'c';
            }
            else if (C[i-1][j]>=C[i][j-1]){
                C[i][j] = C[i-1][j];
                direction[i][j] = 'u';
            }
            else{
                C[i][j] = C[i][j-1];
                direction[i][j] = 'l';
            }
        }
    }
    cout << "\nLength of longest common subsequence: " << C[len1][len2] << endl;
    
    cout << "\nLongest common subsequence: ";
    print(C, direction, s1, len1, len2);
    cout << "\n\n";
}

int main(){
    string s1, s2;
    cout << "Enter string 1:\n";
    getline(cin, s1);
    cout << "Enter string 2:\n";
    getline(cin, s2);
    lcs(s1, s2);
}
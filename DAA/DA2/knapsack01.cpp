#include <iostream>
#include <vector>

using namespace std;

class item{
public:
    int value;
    int weight;
};

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    int n, W;
    cout << "\nEnter the number of items: ";
    cin >> n;
    vector<item> items(n);
    cout << "\nEnter the values and weights of each item: \n";
    for (int i = 0; i < n; i++){
        cin >> items[i].value;
        cin >> items[i].weight;
    }

    cout << "\nEnter the maximum weight that the knapsack can hold: ";
    cin >> W;

    vector<vector<int>> V(n+1, vector<int>(W + 1));

    for (int k = 0; k <= n; k++)
        for (int w = 0; w <= W; w++)
            if(k==0 || w==0){
                V[k][w] = 0;
            }
            else if (items[k].weight <= w){
                V[k][w] = max(
                    V[k - 1][w],
                    items[k].value + V[k - 1][w - items[k].weight]);
            }
            else
                V[k][w] = V[k-1][w];

    cout << "\nTable of Options:\n";
    for (auto i : V){
        for (auto j : i)
            cout << j << "\t";
        cout << "\n";
    }

    cout << "\nMaximum value of knapsack: " << V[n][W] << "\n\n";

    cout << "Item\tValue\tWeight\n";

    while(n>0 && W>0){
        if(V[n][W] == V[n-1][W]){
            n--;
        }
        else{
            cout << n+1 << "\t" << items[n].value << "\t" << items[n].value << endl;
            n--;
            W -= items[n].weight;
        }
    }
}

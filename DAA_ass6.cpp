#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[100][100]; 

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W]; 
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    int* wt = new int[n];
    int* val = new int[n];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    delete[] wt;
    delete[] val;

    return 0;
}

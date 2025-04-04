#include <iostream>
using namespace std;

bool isSafe(int row, int col, int x[]) {
    for (int i = 1; i < row; i++) {
        if (x[i] == col || abs(x[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int row, int n, int* x) {
    if (row > n) { 
        for (int i = 1; i <= n; i++)
            cout << x[i] << " ";
        cout << endl;
        return;
    }
    
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col, x)) { 
            x[row] = col; 
            solveNQueens(row + 1, n, x); 
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    
    int* x = new int[n + 1](); 
    solveNQueens(1, n, x); 
    delete[] x; 
    return 0;
}

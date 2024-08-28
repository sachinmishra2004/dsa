#include <bits/stdc++.h>
using namespace std;
int countways(int i, int j, vector<vector<int>> &grid, int m, int n)
{
    if (i == m || j == n)
        return 0;

    if (grid[i][j] == 1) //obstacles
    
        return 0;

    if (i == m - 1 && j == n - 1)
        return 1;

    return countways(i + 1, j, grid, m, n) + countways(i, j + 1, grid, m, n);
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    int i = 0;
    int j = 0;
    int m = grid.size();
    int n = grid[0].size();

    cout << countways(i, j, grid, m, n);
}
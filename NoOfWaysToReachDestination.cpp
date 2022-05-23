#include <bits/stdc++.h>

using namespace std;

int TotalPath(vector<vector<int>> &grid, int row, int col)
{
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == -1)
    {
        return 0;
    }
    else if (row == grid.size() - 1 && col == grid[0].size()-1)
    {
        return 1;
    }
    return TotalPath(grid,row+1,col)+TotalPath(grid,row,col+1);
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {0, -1, 0, 0},
                                {-1, 0, 0, 0},
                                {0, 0, 0, 0}};
    cout << TotalPath(grid, 0, 0);
    return 0;
}
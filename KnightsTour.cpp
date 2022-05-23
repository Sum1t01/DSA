#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> steps = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
void printSolution(vector<vector<int>> &board)
{
    for (auto a : board)
    {
        for (int b : a)
        {
            cout << b << "   ";
        }
        cout << endl;
    }
    cout<<endl;
}

bool KT(vector<vector<int>> &board, int row, int col, int val)
{
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != -1)
    {
        return false;
    }
    
    if (val == 63)
    {
        return true;
    }
    board[row][col] = val;
    printSolution(board);
    bool finalVal = false;
    for (auto a : steps)
    {
         if(KT(board, row + a[0], col + a[1], val + 1))
         {
             return true;
         }
         else
         {
             board[row][col]=-1;
         }
    }

    return false;
}



void solveKT()
{
    vector<vector<int>> board(8, vector<int>(8, -1));
    if (KT(board, 0, 0, 0))
    {
        printSolution(board);
    }
}

int main()
{
    solveKT();
}
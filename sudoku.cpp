#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define empty 0
#define N 9
bool isGridSafe(int grid[N][N], int row, int col, int num);
bool isEmptyLocation(int grid[N][N], int &row, int &col);
/* assign values to all the zero (not assigned) values for Sudoku solution
 */
bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!isEmptyLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isGridSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = empty;
        }
    }
    return false;
}
/* Check for entries that don't have a value. */
bool isEmptyLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == empty)
                return true;
    return false;
}
/* Returns whether the assigned entry n in the particular row matches
   the given number num. */
bool UsedInRow(int grid[N][N], int prow, int number)
{
    for (int col = 0; col < N; col++)
        if (grid[prow][col] == number)
            return true;
    return false;
}
/* Returns true if the number num matches any number in the column */
bool UsedInCol(int grid[N][N], int pcol, int number)
{
    for (int row = 0; row < N; row++)
        if (grid[row][pcol] == number)
            return true;
  else 
     return false;
}
//Check if the entry used already in the grid box
bool UsedInBox(int grid[N][N], int boxBeginRow, int boxBeginCol, int number)
{
    bool tf = false;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxBeginRow][col+boxBeginCol] == number)
                tf = true;
    return tf;
}
/* Checks if num can be assigned to a given prow,pcol location. */
bool isGridSafe(int grid[N][N], int prow, int pcol, int number)
{
    return !UsedInRow(grid, prow, number) && !UsedInCol(grid, pcol, number) &&
           !UsedInBox(grid, prow - prow % 3 , pcol - pcol % 3, number);
}

// void printGrid(int grid[N][N])
// {
//     cout<<"-------------------------"<<endl;
//     for(int i=0;i<N;i++)
//     {
//         cout<<"| ";
//         for(int j=0;j<N;j++)
//         {
//             if(grid[i][j]!=0)
//             {
//                 cout<<"\033[1m\033[34m"<<grid[i][j]<<" ";
//             }
//             else
//             {
//                 cout<<"_ ";
//             }
//             cout<<"\033[0m";
//             if((j+1)%3==0 && (j+1)!=9)
//             {
//                 cout<<"| ";
//             }
            
//         }
//         cout<<"|"<<endl;
//         if((i+1)%3==0 && (i+1)!=9)
//             {
//                 cout<<"-------------------------"<<endl;
//             }
        
        
//     }
//     cout<<"-------------------------"<<endl;
// }

void solveconsole(int copyGrid[N][N], int grid[N][N])
{
    static int x=0, y=0,z=1;
    int value;
    cout<<"-------------------------"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"| ";
        for(int j=0;j<N;j++)
        {
            if(copyGrid[i][j]!=0)
            {
                cout<<"\033[1m\033[34m"<<copyGrid[i][j]<<" ";
            }
            else if(i==x && j==y)
            {
                cout<<"\033[32m"<<"X"<<" ";
            }
            else
            {
                cout<<"_ ";
            }
            cout<<"\033[0m";
            if((j+1)%3==0 && (j+1)!=9)
            {
                cout<<"| ";
            }
            
        }
        cout<<"|"<<endl;
        if((i+1)%3==0 )
            {
                cout<<"-------------------------"<<endl;
            }
        
        
    }
    cin>>value;
    copyGrid[x][y]=value;
    x++;
    if(z==10)
    {
        z=1;y++;x=0;
    }
    if(isEmptyLocation)
    {
        z++;
        system("CLS");
        solveconsole(copyGrid,grid);
        
    }
    else
    {
        return;
    }
    
}


/* Main */
int main()
{
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 8, 5},
                      {0, 0, 1, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 5, 0, 7, 0, 0, 0},
                      {0, 0, 4, 0, 0, 0, 1, 0, 0},
                      {0, 9, 0, 0, 0, 0, 0, 0, 0},
                      {5, 0, 0, 0, 0, 0, 0, 7, 3},
                      {0, 0, 2, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 9}}; 
    int copyGrid[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            copyGrid[i][j]=grid[i][j];
        }
    }
    // SolveSudoku(grid);
    // printGrid(grid);
    solveconsole(copyGrid,grid);
// if (SolveSudoku(grid) == true)
//         printGrid(grid);
//     else
//         cout<<"No solution found"<<endl;
//     return 0;
}
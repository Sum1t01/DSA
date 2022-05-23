#include<bits/stdc++.h>

using namespace std;


bool isReachable(vector<vector<int>> &maze,vector<vector<int>>&mazePath, int i, int j)
{
    if(i<0 || j<0 || i>=maze.size() || j>=maze[0].size() ||  maze[i][j]<=0)
    {
        return false;
    }
    if(maze[i][j]==9)
    {
        mazePath[i][j]=9;
        return true;
    }
    mazePath[i][j]=maze[i][j];
    maze[i][j]=-maze[i][j];
    bool path=isReachable(maze,mazePath,i+1,j) || isReachable(maze,mazePath,i-1,j) || isReachable(maze,mazePath,i,j+1) 
    || isReachable(maze,mazePath,i,j-1);
    if(path==false)
    {
        mazePath[i][j]=0;
        maze[i][j]=-maze[i][j];
    }
    return path;
}

void printGrid(vector<vector<int>>&maze)
{
    vector<vector<int>>mazePath(maze.size(),vector<int>(maze[0].size(),0));
    if(isReachable(maze,mazePath,0,0))
    {
        for(int i=0;i<maze.size();i++)
        {
            for(int j=0;j<maze[0].size();j++)
            {
                cout<<mazePath[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"Cheese Not Reachable";
    }
}

int main()
{
    vector<vector<int>>maze={{1, 0, 1, 1, 1, 0, 0, 1},
                             {1, 0, 0, 0, 1, 1, 1, 1},
                             {1, 0, 0, 0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 9, 0, 1, 1},
                             {1, 1, 1, 0, 1, 0, 0, 1},
                             {1, 0, 1, 0, 1, 1, 0, 1},
                             {1, 0, 0, 0, 0, 1, 0, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1}
                            };
    printGrid(maze);
}
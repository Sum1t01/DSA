#include<bits/stdc++.h>

using namespace std;

bool validPath(vector<vector<int>>& maze, vector<vector<int>>&mazePath, int i, int j)
{
    if(i<0 || j<0 || i>=maze.size() || j>=maze[i].size() || maze[i][j]<=0)
    {
        return false;
    }
    if(i==maze.size()-1 && j==maze[i].size()-1 && maze[i][j]==1)
    {
        mazePath[i][j]=maze[i][j];
        return true;
    }
    mazePath[i][j]=maze[i][j];
    maze[i][j]=-maze[i][j];
    bool path= validPath(maze,mazePath,i+1,j) || validPath(maze,mazePath,i-1,j) || validPath(maze,mazePath,i,j+1) || validPath(maze,mazePath,i,j-1);
    if(path==false)
    {
        mazePath[i][j]=0;
        maze[i][j]=-maze[i][j];
    }
    return path;
}

void findPath(vector<vector<int>> & maze)
{
    vector<vector<int>>mazePath(maze.size(),vector<int>(maze[0].size(),0));
    if(validPath(maze,mazePath,0,0))
    {
        for(int i=0;i<mazePath.size();i++)
        {
            for(int j=0;j<mazePath[i].size();j++)
            {
                cout<<mazePath[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No path exists";
    }
}

int main()
{
    vector<vector<int>> maze = { { 1, 0, 0, 0 },
                                 { 1, 1, 0, 1 },
                                 { 0, 1, 0, 0 },
                                 { 1, 1, 1, 1 } };
 
    findPath(maze);
    return 0;
}
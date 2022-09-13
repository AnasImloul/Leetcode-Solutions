// Runtime: 163 ms (Top 77.33%) | Memory: 40.5 MB (Top 19.90%)
class Solution {
public:
    //checks if the coordinates of the cell are that of an unvisited valid empty cell
    bool isValid(int x,int y,int n,int m, vector<vector<char>>& maze,vector<vector<int>>& visited){
        if(x>=0 && x<n && y>=0 && y< m && maze[x][y]!='+' && visited[x][y]!=1){
            return true;
        }
        return false;
    }

    //checks if the cell is a valid exit point
    bool isExit(int x,int y,int startX,int startY, vector<vector<char>>& maze,vector<vector<int>>& visited){
        if(x==startX && y==startY) return false;
        if( (x==0 || x==maze.size()-1 || y==0 || y==maze[0].size()-1)
           && maze[x][y]!='+')
        {
            return true;
        }
        return false;
    }

    //main BFS function
    int bfsHelper(vector<vector<char>>& maze,vector<vector<int>>& visited,int startX,int startY){
        queue<vector<int>>Queue;
        Queue.push({startX,startY,0});
        while(!Queue.empty()){
            int x = Queue.front()[0];
            int y = Queue.front()[1];
            int steps = Queue.front()[2];
            Queue.pop();
            //if you reach a valid exit, return the number of steps
            if(isExit(x,y,startX,startY,maze,visited)) return steps;
            int dx[4] = {0,-1,0,1};
            int dy[4] = {-1,0,1,0};
            //check in the 4 directions that you can travel
            for(int i=0;i<4;i++){
                int newX = x+dx[i] , newY = y+dy[i];
                //if the coordinates of the cell are that of
                //an unvisited valid empty cell, add it to the queue
                //and mark it as visited.
                if(isValid(newX,newY,maze.size(),maze[0].size(),maze,visited)){
                    Queue.push({newX,newY,steps+1});
                    visited[newX][newY] = 1;
                }
            }
        }
        //if you could not find a valid exit point, return -1
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        //create a 2d matrix and mark all the cells as -1,
        //denoting that they have not been visited yet.
        vector<vector<int>>visited(n,vector<int>(m,-1));
        return bfsHelper(maze,visited,entrance[0],entrance[1]);
    }
};
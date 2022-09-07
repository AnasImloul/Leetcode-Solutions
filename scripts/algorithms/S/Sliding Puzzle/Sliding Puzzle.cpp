// Runtime: 59 ms (Top 21.57%) | Memory: 12.6 MB (Top 21.84%)
class Node{
public:
int row;
int col;
vector<vector<int>>state;
    };

class Solution {
public:

int slidingPuzzle(vector<vector<int>>& board) {

    vector<vector<int>>target={{1,2,3},{4,5,0}};
    queue<Node>q;
    int n=2;
    int m=3;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==0){
                q.push({i,j,board});
                break;
            }
        }

    set<vector<vector<int>>>set;
    set.insert(q.front().state);
    int ladder=0;
    while(!q.empty()){
       int size=q.size();
        for(int i=0;i<size;i++){
            Node curr=q.front();
            q.pop();
            if(curr.state==target)
                return ladder;

            int row=curr.row;
            int col=curr.col;
            for(auto &x:dir){
                int r=x[0]+row;
                int c=x[1]+col;

                if(r<n && r>=0 && c<m && c>=0 ){
                    swap(curr.state[r][c],curr.state[row][col]) ;
                    if(set.find(curr.state)==set.end()){
                        set.insert(curr.state);
                        q.push({r,c,curr.state});
                    }
                     swap(curr.state[r][c],curr.state[row][col]) ;

                }

            }

        }
        ladder++;

    }
    return -1;

}
};
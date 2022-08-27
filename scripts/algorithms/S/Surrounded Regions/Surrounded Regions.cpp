// Runtime: 19 ms (Top 61.60%) | Memory: 10.6 MB (Top 22.64%)
class Solution {
public:
    int n,m; int visited[201][201] = {0};
    // Breadth First Search
    // Flood Fill Algorithm
    void bfs(vector<vector<char>>& board, int x, int y){
        queue<int> q; q.push(m*x+y);
        visited[x][y] = 1;
        int curr,i,j;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            i = curr/m; j = curr%m;
            board[i][j] = 'O';
            if(i > 0 && !visited[i-1][j] && board[i-1][j] == 'C'){
                visited[i-1][j] = 1;
                q.push(m*(i-1)+j);
            }
            if(i < n-1 && !visited[i+1][j] && board[i+1][j] == 'C'){
                visited[i+1][j] = 1;
                q.push(m*(i+1)+j);
            }
            if(j > 0 && !visited[i][j-1] && board[i][j-1] == 'C'){
                visited[i][j-1] = 1;
                q.push(m*i+j-1);
            }
            if(j < m-1 && !visited[i][j+1] && board[i][j+1] == 'C'){
                visited[i][j+1] = 1;
                q.push(m*i+j+1);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(); m = board[0].size();
        // Marking the regions to capture
        // mark all the O to C
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'C';
            }
        }
        // if we have found C on the outer edges, then all the connected C to it should be
        // converted to O as they can't be captured
        for(int i=0; i<m; i++){
            if(board[0][i] == 'C' && !visited[0][i]) bfs(board, 0, i);
            if(board[n-1][i] == 'C' && !visited[n-1][i]) bfs(board, n-1, i);
        }
        for(int i=1; i<n-1; i++){
            if(board[i][0] == 'C' && !visited[i][0]) bfs(board, i, 0);
            if(board[i][m-1] == 'C' && !visited[i][m-1]) bfs(board, i, m-1);
        }
        // capturing the regions
        // now remaining C can be capture
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'C') board[i][j] = 'X';
            }
        }
    }
};
static const auto speedup =[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
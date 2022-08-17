class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, int> mp;
        int n = board.size();
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != -1) {
                    int val;
                    if((n-i)%2 != 0) val = (n-i-1)*n + j + 1;
                    else val = (n-i-1)*n + n - j;
                    mp[val] = board[i][j];
                }
            }
        }
        queue<pair<int, int>> q;
        vector<int> visited(n*n+1, false);
        q.push({1, 0});
        while(!q.empty()) {
            int node = q.front().first;
            int moves = q.front().second;
            q.pop();
            if(node == n*n) return moves;
            if(visited[node]) continue;
            visited[node] = true;
            for(int k = 1; k <= 6; k++) {
                if(node+k > n*n) continue;
                int x = node + k;
                if(mp.find(x) != mp.end()) x = mp[x];
                q.push({x, moves+1});
            }
        }
        return -1;
    }
};

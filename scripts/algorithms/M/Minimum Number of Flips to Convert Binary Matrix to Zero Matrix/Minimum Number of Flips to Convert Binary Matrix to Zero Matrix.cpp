// Runtime: 3 ms (Top 73.54%) | Memory: 7.20 MB (Top 86.55%)

class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};

    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), mask = 0;
        unordered_set<int>vis;
        queue<int>q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                mask |= (mat[i][j] << (i*m+j));

        q.push(mask);
        vis.insert(mask);
        int step = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cur = q.front();
                q.pop();
                if(cur == 0) return step;

                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++) {
                        int temp = cur;
                        temp ^= (1 << (i*m+j));
                        for(int k = 0; k < 4; k++){
                            int ni = i + dir[k];
                            int nj = j + dir[k+1];
                            if(min(ni, nj) >= 0 && ni < n && nj < m) {
                                temp ^= (1 << (ni*m + nj));
                            }
                        }
                        if(vis.find(temp) == vis.end()) {
                            vis.insert(temp);
                            q.push(temp);
                        }
                    }
                }
                
            }
            step++;
        }
        return -1;
    }
};

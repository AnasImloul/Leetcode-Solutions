// Runtime: 356 ms (Top 70.09%) | Memory: 8.7 MB (Top 99.54%)
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        // BFS
        queue<int> q;
        vector<bool> vis(1001, false);

        q.push(goal);
        if (0 <= goal && goal <= 1000) vis[goal] = true;

        int dist = -1;
        bool done = false;
        while (!q.empty() && !done) {
            dist++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur = q.front(); q.pop();
                if (cur == start) {
                    done = true;
                    break;
                }
                for (int j = 0; j < n; j++) {
                    if (0 <= cur-nums[j] && cur-nums[j] <= 1000 && !vis[cur-nums[j]]) {
                        q.push(cur-nums[j]);
                        vis[cur-nums[j]] = true;
                    }
                    if (0 <= cur+nums[j] && cur+nums[j] <= 1000 && !vis[cur+nums[j]]) {
                        q.push(cur+nums[j]);
                        vis[cur+nums[j]] = true;
                    }
                    if (0 <= (cur^nums[j]) && (cur^nums[j]) <= 1000 && !vis[cur^nums[j]]) {
                        q.push(cur^nums[j]);
                        vis[cur^nums[j]] = true;
                    }
                }
            }
        }

        return done ? dist : -1;
    }
};
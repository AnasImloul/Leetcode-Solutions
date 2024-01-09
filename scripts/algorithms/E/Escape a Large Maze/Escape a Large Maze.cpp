// Runtime: 27 ms (Top 97.1%) | Memory: 14.20 MB (Top 96.74%)

class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
   
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
      unordered_set<long long> visited_s;
      unordered_set<long long> visited_t;
      for (auto& block : blocked) {
        if (abs(source[0] - block[0]) + abs(source[1] - block[1]) <= 200)
          visited_s.insert(((long long)block[0] << 32) + block[1]);
        if (abs(target[0] - block[0]) + abs(target[1] - block[1]) <= 200)
          visited_t.insert(((long long)block[0] << 32) + block[1]);
      }
      return bfs(source, target, visited_s, visited_s.size()) &&
             bfs(target, source, visited_t, visited_t.size());
    }
    bool bfs(vector<int>& source, vector<int>& target, 
             unordered_set<long long>& visited, int blocks) {
      queue<pair<int, int>> q;
      q.push({source[0], source[1]});
      while (!q.empty() && q.size() <= blocks) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == target[0] && y == target[1])
          return true;
        for (auto& dir : dirs) {
          int next_x = x + dir[0];
          int next_y = y + dir[1];
          if (next_x < 0 || next_x > 999999 || next_y < 0 || next_y > 999999
              || visited.find(((long long)next_x << 32) + next_y) != visited.end())
            continue;
          q.push({next_x, next_y});
          visited.insert(((long long)next_x << 32) + next_y);
        }
      }
      return !q.empty();
    }
};

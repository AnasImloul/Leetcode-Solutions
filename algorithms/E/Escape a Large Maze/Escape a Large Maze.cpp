class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool valid(int x, int y) {
        return x >= 0 && x < 1e6 && y >= 0 && y < 1e6;
    }
    
    bool dfs(vector<int> &source, vector<int> &target, vector<int> &curr, set<pair<int, int>> &blocked, set<pair<int, int>> &used) {
        if(curr[0] == target[0] && curr[1] == target[1])
            return true;
        else if(abs(curr[0]-source[0]) + abs(curr[1]-source[1]) >= 200)
            return true;
        
        used.insert({curr[0], curr[1]});
        for(int i = 0; i < 4; i++) {
            int x = curr[0] + dir[i][0];
            int y = curr[1] + dir[i][1];
            if(valid(x, y) && !blocked.count({x, y}) && !used.count({x, y})) {
                vector<int> tmp = {x, y};
                if(dfs(source, target, tmp, blocked, used))
                    return true;
            }
        }
        
        return false;
    }
    
    
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int, int>> blocked_set;
        for(auto it: blocked) 
            blocked_set.insert({it[0], it[1]});
        
        set<pair<int, int>> used1, used2;
        return dfs(source, target, source, blocked_set, used1) && dfs(target, source, target, blocked_set, used2);
    }
};


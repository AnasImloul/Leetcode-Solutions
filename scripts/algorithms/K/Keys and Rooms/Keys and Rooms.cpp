// Runtime: 23 ms (Top 5.63%) | Memory: 11.70 MB (Top 10.19%)

class Solution {
    void dfs(vector<vector<int>>& rooms, unordered_set<int> & keys, unordered_set<int> & visited, int curr) {
        visited.insert(curr);
        for (int k : rooms[curr]) keys.insert(k);
        for (int k : keys) if (visited.find(k) == visited.end()) dfs(rooms, keys, visited, k);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        unordered_set<int> visited;
        dfs(rooms, keys, visited, 0);
        return visited.size() == rooms.size();
    }
};

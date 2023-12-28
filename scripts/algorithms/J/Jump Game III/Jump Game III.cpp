// Runtime: 26 ms (Top 94.29%) | Memory: 47.00 MB (Top 27.2%)

class Solution {
public:
    
    bool ff(vector<int>& arr, vector<bool>& visited, int i) {
        if (i < 0 || i >= arr.size() || visited[i]) return false;
        if (arr[i] == 0) return true;
        visited[i] = true;
        return ff(arr, visited, i + arr[i]) || ff(arr, visited, i - arr[i]);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return ff(arr, visited, start);
    }
};

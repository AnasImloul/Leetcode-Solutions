class Solution {
public:
    bool dfs(int curr, vector<int>& arr, vector<bool>& visited, int size) {
		// edge cases - we can't go outside the array size and if the curr index is alredy visited it will repeat same recursion all over again so we can return false in that case too.
        if(curr < 0 || curr >= size || visited[curr])
            return false;
		// If we reach zero we can return true
        if(arr[curr] == 0)
            return true;
        visited[curr] = true;
		// do dfs in left and right and return two if any of the two paths end up reaching to zero
        return dfs(curr - arr[curr], arr, visited, size) || 
            dfs(curr + arr[curr], arr, visited, size);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        vector<bool> visited(size, false);
        return dfs(start, arr, visited, size);
    }
};

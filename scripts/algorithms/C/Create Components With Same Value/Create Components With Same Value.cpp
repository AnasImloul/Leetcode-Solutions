// Runtime: 329 ms (Top 80.64%) | Memory: 145.10 MB (Top 21.5%)

class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum=0, n=nums.size();
        
        // sum of value
        for (int i=0; i<n; ++i)
            sum+=nums[i];
        
        vector<vector<int>> next(n);
        
        // create edges map
        for (auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        
        for (int i=n; i>1; --i) {
            if (sum%i) continue;  // there is no probability that split the tree into i part.
            vector<int> temp(n);
            if (traverse(nums, next, 0, temp, sum/i)==0) return i-1;
        }
        return 0;
    }
    
    int traverse(vector<int>& nums, vector<vector<int>>& next, int cur, vector<int>& temp, int target) {
        temp[cur]=nums[cur];
        for (auto n : next[cur]) {
            if (temp[n]) continue; // this condition represents that the node n has been visited.
            temp[cur]+=traverse(nums, next, n, temp, target);
            // If temp[cur]>target means that we fail the separation.
            // In this condition, we just return a very large integer.
            if (temp[cur]>target) return 1e7;
        }
        // this condition represents that the substree rooted at cur can be deleted from the tree. So, the sum of value can not add up to the parent of curent node.
        if (temp[cur]==target) return 0;
        return temp[cur];
    }
};

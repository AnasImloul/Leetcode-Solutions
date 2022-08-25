// Runtime: 14 ms (Top 73.19%) | Memory: 11.4 MB (Top 67.29%)
class Solution {
private:
    void dfs(int i, int n, vector<int> &ans){
        if(i > n) return;
        ans.push_back(i);
        for(int j = 0; j< 10; ++j) dfs(i * 10 + j, n, ans);
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i =1; i<10; ++i) dfs(i, n, ans);
        return ans;
    }
};
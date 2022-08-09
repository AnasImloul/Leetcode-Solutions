class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0, x = 1;
        vector<int> degree(n,0);
        for(auto road : roads){
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(),degree.end());
        for(auto i : degree) ans += i * (x++);
        return ans;
    }
};

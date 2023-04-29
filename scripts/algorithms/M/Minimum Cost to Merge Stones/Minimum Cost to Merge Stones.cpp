class Solution {
public:
    #define LIM 32
    vector<int> prefixSum = {0};
    int dp[LIM][LIM][LIM];
    int solve(vector<int> &stones, int start, int end, int k){
        // Base Case: Invalid Index or For single element answer is always 0
        if(start >= end) return 0;
        int cost = INT_MAX;
        if(dp[start][end][k]!=-1) return dp[start][end][k];
        for(int i = start; i < end; i = i+k-1)
            cost = min(cost, solve(stones, start, i, k) + solve(stones, i+1, end, k));
        if((end-start)%(k-1) == 0)
            cost += prefixSum[end+1]-prefixSum[start];
        return dp[start][end][k]=cost;
    }
    int mergeStones(vector<int>& stones, int k){
        int n = stones.size();
        if((n-1)%(k-1) != 0) return -1;
        for(int i : stones) prefixSum.push_back(prefixSum.back()+i);
        for(int i=0; i<LIM; i++) for(int j=0; j<LIM; j++) for(int k=0; k<LIM; k++) dp[i][j][k]=-1;
        return solve(stones, 0, n-1, k);
    }
};
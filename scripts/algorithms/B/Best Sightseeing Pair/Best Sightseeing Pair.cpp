class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=-1e9;
        int maxSum=values[0];
        int n=values.size();
        for(int i=1;i<n;i++){
            ans=max(ans,maxSum+values[i]-i);
            maxSum=max(maxSum,values[i]+i);
        }
        return ans;
        
    }
};

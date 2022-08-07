class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        int n=timeSeries.size();
        for(int i=0;i<n;i++){
            ans+=min(duration,(i==n-1?duration:timeSeries[i+1]-timeSeries[i]));
        }
        return ans;
    }
};
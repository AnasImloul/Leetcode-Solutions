class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int diff=INT_MAX,ans=0;
        for(auto i : tasks){
            diff=min(diff,i[1]-i[0]);
            ans+=i[0];
        }
        int val=0;
        for(auto i : tasks)
            val=max(val,i[1]);
        return max(ans+diff,val);
    }
};

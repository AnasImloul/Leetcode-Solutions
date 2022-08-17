class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size=rolls.size(),sum=accumulate(rolls.begin(),rolls.end(),0),missingSum=0;
         missingSum=mean*(n+size)-sum;
        if(missingSum<n || missingSum>6*n)
            return {};
         int rem=missingSum%n;
         vector<int>ans(n,missingSum/n);
        for(int i=0;i<rem;i++)
            ans[i]+=1;
        return ans;   
    }
};

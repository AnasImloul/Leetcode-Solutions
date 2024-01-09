// Runtime: 187 ms (Top 74.84%) | Memory: 162.90 MB (Top 10.32%)

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n= nums.size();
        long long sum= 0; for(int i=0; i<n; i++){ sum+=nums[i]; } long long ans=sum;
        
        for(int cycle=1; cycle<=n; cycle++){
            vector<int> temp= nums; sum=0;
            for(int i=0; i<n-1; i++){
                if(nums[i+1]>nums[i]){  temp[i+1]=nums[i];  }
            }
            if(nums[0]>nums.back()){  temp[0]=nums.back();  }
            
            for(int i=0; i<n; i++){ sum+=temp[i]; }
            ans= min(ans, sum+ (1LL*x*cycle));
            nums= temp;
        }
        
        return ans;
    }
};

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        //j - i != nums[j] - nums[i] means  nums[i]-i != nums[j]-j
        map<long long,long long >mp;
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = nums[i]-i;
            
            mp[nums[i]]++;
        }
        long long  n = nums.size();
        long long totalPair = n*(n-1)/2;
        
        for(auto& it:mp)
        {
            if(it.second>1)
            {
                totalPair -= (it.second)*(it.second-1)/2;
            } 
        }
        
        
        
        return totalPair;
    }
};
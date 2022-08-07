class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> ans;        
        for(int i = 0; i < n; i++)
        {                
            vector<int> tmp;
            tmp.push_back(nums[i]);
            
            // Checking the prev one
            int j = i - 1;
            while(j >= 0)
            {
                if(tmp.back() % nums[j] == 0)
                    tmp.push_back(nums[j]);
                    
                j--;
            }
            
            // Reversing the order to make it in increasing order
            reverse(tmp.begin(), tmp.end());
            
            // Checking the forward one
            j = i + 1;
            while(j < n)
            {
                if(nums[j] % tmp.back() == 0)
                    tmp.push_back(nums[j]);
                
                j++;
            }
            
            // updating the ans
            if(ans.size() < tmp.size())
                ans = tmp;
        }
        
        return ans;        
    }
};

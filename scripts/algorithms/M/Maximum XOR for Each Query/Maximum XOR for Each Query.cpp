class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), xoR=0, prevXOR=0;  
        vector<int> ans;
        for(auto it:nums)
            xoR^=it;
        for(int j=0;j<n;j++){
            xoR^=prevXOR;
            int k=0;
            for(int i=0;i<maximumBit;i++){
                if((xoR & (1<<i)))
                    continue;
                else
                    k^=(1<<i);
            }
            ans.push_back(k);
            prevXOR=nums.back();
            nums.pop_back();
        }
        return ans;
    }
};
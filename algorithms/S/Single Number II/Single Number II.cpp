class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans= 0;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto j: mp){
            if(j.second == 1){
                ans = j.first;
                break;
            }
        }
        return ans;
        
    }
};

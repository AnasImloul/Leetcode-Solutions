class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int i=0;
        map<int,int> mp;
        int n=nums.size();
        for(int j=0;j<n;j++){
            auto val=mp.lower_bound(nums[j]);
            if(val!=mp.end() and (val->first-nums[j])<=valueDiff){
                return true;
            }
            if(val!=mp.begin()){
                val--;
                if(abs(val->first-nums[j])<=valueDiff){
                    return true;
                }
            }
            mp[nums[j]]++;
            if((j-i)==indexDiff){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
        }
        return false;
    }
};
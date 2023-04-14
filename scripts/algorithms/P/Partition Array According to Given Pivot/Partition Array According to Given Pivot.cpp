class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i = 0;
        vector<int> res;
        int cnt = count(nums.begin(), nums.end(), pivot);
        while(--cnt >= 0) {
            res.push_back(pivot);
        }
        for(int k = 0; k < nums.size(); k++) {
            if(nums[k] < pivot) {
                res.insert(res.begin() + i, nums[k]);
                i++;
            } else if(nums[k] > pivot) {
                res.push_back(nums[k]);
            } else
                continue;
        }
        return res;
    }
};
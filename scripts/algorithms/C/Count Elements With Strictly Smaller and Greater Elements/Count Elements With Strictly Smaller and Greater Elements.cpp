class Solution {
public:
    int countElements(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end()); 
        int m = *min_element(nums.begin(), nums.end()); 
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > m && nums[i] < M) res++;
        }
        return res;
    }
};

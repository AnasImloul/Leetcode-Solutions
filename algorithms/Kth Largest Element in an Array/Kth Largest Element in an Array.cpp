class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        int d = m - k;
        int ans;
        for(int i =0; i < nums.size(); i++){
            if(i == d){
                ans = nums[d];
            }
        }
        return ans;
    }
};

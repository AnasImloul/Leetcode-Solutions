// Runtime: 196 ms (Top 75.30%) | Memory: 70.9 MB (Top 52.97%)
class Solution {
public:
    vector<int> nums;
    int solve(int k){
        int low = 0, high = 0, cnt = 0, res = 0;

        while(high < nums.size()){
            if(nums[high] & 1){
                cnt++;

                while(cnt > k){
                    if(nums[low] & 1) cnt--;
                    low++;
                }
            }
            high++;
            res += high - low;
        }

        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        this -> nums = nums;
        return solve(k) - solve(k - 1);
    }
};
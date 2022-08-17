class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0; // store ans
        int j=-1; // starting window
        int sub = 0; // if current element is less than left bound then count how may element before current element which is less than left and must be continues(it means any element which is greater than left bound reset the count to 0 )
        for(int i=0;i<nums.size();i++){
            if(nums[i]>right){
                j = i;
                sub = 0;
            }
            else if(nums[i]<left){
                sub++;
            }
            else sub = 0;
            ans = ans + i - j - sub;
        }
        return ans;
    }
};

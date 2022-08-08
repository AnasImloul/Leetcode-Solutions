class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int oddSum = 0, evenSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                int left = i==0?INT_MAX:nums[i-1];
                int right = i==n-1?INT_MAX:nums[i+1];
                evenSum += max(nums[i]-min(left,right)+1,0);
            }else{
                int left = i==0?INT_MAX:nums[i-1];
                int right = i==n-1?INT_MAX:nums[i+1];
                oddSum += max(nums[i]-min(left,right)+1,0);
            }
        }
        return min(evenSum,oddSum);
    }
};

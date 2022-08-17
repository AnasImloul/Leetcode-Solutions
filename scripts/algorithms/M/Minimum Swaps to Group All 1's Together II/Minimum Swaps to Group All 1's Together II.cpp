class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0; // total no. of ones
        for(int i=0;i<n;i++){
            if(nums[i]==1) ones++;
        }
        if(ones<=1) return 0;
        
        int k = ones; // sliding window length
        int maxOnes = 0; // maxOnes in sub array of length k 
        int cnt = 0;
        for(int i=0;i<k;i++){
            if(nums[i]==1) cnt++;
        }
        maxOnes = cnt;
        for(int i=k;i<n+k;i++){
            if(nums[i-k]==1) cnt--; // if element removing from window is 1, then decrease count.
            if(nums[i%n]==1) cnt++; // if element adding to window is 1, then increase count.
            maxOnes = max(maxOnes,cnt); // maintaing maxOnes for all sub arrays of length k.
        }
        return(k - maxOnes); // (total length of subarray - ones in the sub array found) 
    }
};

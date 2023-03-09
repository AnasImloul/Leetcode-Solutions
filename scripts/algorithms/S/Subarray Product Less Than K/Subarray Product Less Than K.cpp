class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        long prod = 1;
        int count =0; // count of subarray prod  less than k
        for(int end =0; end< nums.size(); end++){
            prod *= nums[end];
    
           while(prod >= k && start < nums.size()){
               prod = prod/nums[start];// divide product by nums at start pointer t reduce the prod
                start++;//move start pointer because no longer nums at start can give us prod < k
              }
           if(prod < k)
            count += end - start +1;
      }
    return count;
    }
};

/********************************* Solution Using HashMap / Prefix ********************/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
        unordered_map<int, int> prefixSum {{0, 1}};
        
        int sum = 0;
        int numOfSubArr = 0;
        int size = nums.size();
        
        
        for (int index = 0; index < size; index++){
            
            sum += nums[index];
            if (prefixSum.find(sum-k) != prefixSum.end()) 
                numOfSubArr += prefixSum[sum-k];
            
            prefixSum[sum]++;
        }
        
        return numOfSubArr;
    }
};


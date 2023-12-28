// Runtime: 98 ms (Top 91.78%) | Memory: 95.80 MB (Top 60.53%)

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> arr(n,0);
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]^nums[i];
        }
        int idx=0;
        int k = (1<<maximumBit) - 1;
        
        for(int i=n-1;i>=0;i--){
            int curr=k & ~(arr[i]); //invertBits(arr[i]);
            nums[idx++]=curr;
        }
        return nums;
    }
};

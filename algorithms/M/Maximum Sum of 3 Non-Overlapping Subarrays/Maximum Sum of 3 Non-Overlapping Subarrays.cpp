class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        
        for(int i=1; i<=n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        
        vector<int> left(n+1, 0);
        vector<int> leftInd(n+1, 0);
        vector<int> right(n+1, 0);
        vector<int> rightInd(n+1, 0);
        
        for(int i=k; i<=n; i++){
            left[i] = max(left[i-1], prefixSum[i]-prefixSum[i-k]);
            
            if(left[i] == left[i-1]){
                leftInd[i] = leftInd[i-1];
            }
            else{
                leftInd[i] = i;
            }
        }
        
        for(int i=n-k; i>=0; i--){
            right[i] = max(right[i+1], prefixSum[i+k]-prefixSum[i]);
            
            if(right[i] == prefixSum[i+k]-prefixSum[i]){
                rightInd[i] = i;
            }
            else{
                rightInd[i] = rightInd[i+1];
            }
        }
        
        int maxSum=0, a, b, c;
        
        for(int i=k; i<=n-2*k; i++){
            if(maxSum < left[i]+(prefixSum[i+k]-prefixSum[i])+right[i+k]){
                maxSum = left[i]+(prefixSum[i+k]-prefixSum[i])+right[i+k];
                a = leftInd[i]-k;
                b = i;
                c = rightInd[i+k];
            }
        }
        
        return {a, b, c};
    }
};

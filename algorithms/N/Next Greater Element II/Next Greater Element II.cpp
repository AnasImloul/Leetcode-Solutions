class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            int j = i + 1;
            if(j == n) j = 0;
            int next = -1;
            
            while(j != i){
                if(nums[j] > nums[i]){
                    next = nums[j];
                    break;
                }
                j++;
                if(j == n) j = 0;
            }
            res.push_back(next);
        }
        return res;
    }
};

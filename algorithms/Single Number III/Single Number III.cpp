class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        vector<int> ans;
        int xorr = 0;
        for(int i=0; i<nums.size(); i++){
            xorr = xorr xor nums[i];
        }
        int count  = 0;
        while(xorr){
            if(xorr & 1){
                break;
            }
            count++;
            xorr = xorr >> 1;
        }
        int xorr1 = 0;
        int xorr2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] & (1 << count)){
                xorr1 = xorr1 xor nums[i];
            }
            else{
                xorr2 = xorr2 xor nums[i];
            }
        }
        ans.push_back(xorr1);
        ans.push_back(xorr2);
        return ans;
    }
};

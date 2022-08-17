class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int t = 33;
        while(t--){
            int flag = false;
            for(int i = 0; i<nums.size(); i++){
                if(nums[i]%2) ans++;
                nums[i]/=2;
                if(nums[i]!=0) flag = true;
            }
			
            if(!flag) break;
            ans++;
        }
        return ans;
    }
};

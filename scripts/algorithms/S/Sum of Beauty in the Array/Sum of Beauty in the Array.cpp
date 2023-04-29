class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>right;
        vector<int>left;
        int low=nums[0];
        for(int i=0;i<nums.size();i++){
            
            left.push_back(low);
            low=max(low,nums[i]);
        }
        low=nums[n-1];
        for(int i=n-1;i>=0;i--){
            
            right.push_back(low);
            low=min(low,nums[i]);
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>left[i] && nums[i]<right[i]){
                ans+=2;
            }
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                ans+=1;
            }
            else{
                ans+=0;
            }
        }
        return ans;
        
    }
};
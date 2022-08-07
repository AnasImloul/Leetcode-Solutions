class Solution {
public:
    
    //Brute Force
    vector<int> rotate(vector<int>&nums , int k){
        int n = nums.size();
        vector<int>temp;
        for(int i = n-k ; i <n ; i++){
            temp.push_back(nums[i]);
        }
        
        for(int i = 0 ; i < n-k ; i++){
            temp.push_back(nums[i]);
        }
        
        return temp;
        
    }
    
    
    int Sum(vector<int>&nums , int n){
        int ans = 0;
        
        for(int i = 0 ; i < n ; i ++){
            ans += (nums[i] * i);
        }
        
        return ans;
        
        
    }
    int maxRotateFunction(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            vector<int>temp = rotate(nums,i);
            ans = max(ans , Sum(temp , n));
        }
        
        return ans;
    }
    
    //Optimized Approach
    
     int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0),curr=0,n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            curr+=(i*nums[i]); 
        }
        ans=curr; 
        for(int i=n-1;i>=0;i--){
            curr+=sum-(n*nums[i]);
            ans=max(curr,ans);
        }
        return ans;
    }
};

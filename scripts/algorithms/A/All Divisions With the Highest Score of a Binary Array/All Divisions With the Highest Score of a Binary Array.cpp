class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+1),right(n+1);
        left[0]=0;
        right[n]=0;
        
        for(int i=1;i<n+1;i++){
            if(nums[i-1]==0)
                left[i]=left[i-1]+1;
            else 
                left[i]=left[i-1];
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1)
                right[i]=right[i+1]+1;
            else 
                right[i]=right[i+1];
        }
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<n+1;i++){
            mp[left[i]+right[i]].push_back(i);
        }
        
           return mp.rbegin()->second;
    }
};

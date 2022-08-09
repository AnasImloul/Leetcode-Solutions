class Solution {
public:
    int dfs(vector<int>&nums,int ind,int arr[],int res)
    {
        if(arr[ind]==1)
            return res;
        res++;
        arr[ind]=1;
        return dfs(nums,nums[ind],arr,res);
    }
    int arrayNesting(vector<int>& nums) {
        
        int arr[nums.size()],ans=0;
        for(int i=0;i<nums.size();i++)
            arr[i]=0;
        for(int i=0;i<nums.size();i++)
        {
            int res=dfs(nums,i,arr,0);
            ans=max(res,ans);
        }
        return ans;
    }
};

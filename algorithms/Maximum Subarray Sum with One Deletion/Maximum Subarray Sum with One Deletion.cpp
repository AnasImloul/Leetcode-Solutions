class Solution {
public:
    int maximumSum(vector<int>& arr) {
         int n=arr.size();
        int ans=arr[0];
        int no_del=arr[0];
        int del=0;
        for(int i=1;i<n;i++)
        {
            del=max(no_del,del+arr[i]);
            no_del=max(arr[i],no_del+arr[i]);
            ans=max(ans,max(del,no_del));
        }
        return ans;    
    }
};
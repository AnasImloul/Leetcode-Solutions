// Runtime: 278 ms (Top 54.50%) | Memory: 77.1 MB (Top 64.88%)
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> prefix(n,INT_MAX);
        vector<int> suffix(n,INT_MAX);
        int sum=0;
        int start=0;
        for(int end=0;end<n;end++){
            sum+=arr[end];
            while(sum>target){
                sum-=arr[start++];
            }
            if(sum==target){
                prefix[end]=min(prefix[end-1>=0 ? end-1 : 0],end-start+1);
            }
            else{
                prefix[end]=prefix[end-1>=0 ? end-1 : 0];
            }
        }

        sum=0;
        start=n-1;
        for(int end=n-1;end>=0;end--){
            sum+=arr[end];
            while(sum>target){
                sum-=arr[start--];
            }
            if(sum==target){
                suffix[end]=min(suffix[end+1<n ? end+1 : n-1],start-end+1);
            }
            else{
                suffix[end]=suffix[end+1<n ? end+1 : n-1];
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(prefix[i]==INT_MAX || suffix[i+1]==INT_MAX){
                continue;
            }
            res=min(res,prefix[i]+suffix[i+1]);
        }
        return res==INT_MAX ? -1 : res;

    }
};
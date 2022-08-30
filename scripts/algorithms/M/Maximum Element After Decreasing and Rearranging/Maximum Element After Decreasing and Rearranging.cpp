// Runtime: 150 ms (Top 64.37%) | Memory: 51.4 MB (Top 22.05%)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        arr[0]=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]>1)
            {
                arr[i]=arr[i-1]+1;
            }
        }
        return arr[n-1];
    }
};
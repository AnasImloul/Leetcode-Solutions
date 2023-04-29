class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

    int n=arr.size();
    if(arr[n-1]==n)
        return n+k;
    else
    {
        int start=0;
        int end=n-1;
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if((arr[mid]-(mid+1))<k)
                start=mid+1;
            else
                end=mid-1;
        }
        return start+k;
    }

    }
};

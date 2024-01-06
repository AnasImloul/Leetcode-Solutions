// Runtime: 3 ms (Top 79.43%) | Memory: 9.90 MB (Top 63.69%)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(high-low)/2+low;
            int x=arr[mid]-mid-1;//will give no. of missing elements
            if(x>=k)
            high=mid-1;
            else
            low=mid+1;
        }
        return k+low;   
    }
};

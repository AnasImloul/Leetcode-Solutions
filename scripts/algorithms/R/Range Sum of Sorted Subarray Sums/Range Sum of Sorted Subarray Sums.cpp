class Solution 
{
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        const int m= 1e9+7; // To return ans % m
        int ans=0;  // Final Answer
        int k=1;  // For 1 based indexing
        int size= (n*(n+1))/2;  // We can form n(n+1)/2 subarrays for an array of size n
        vector<int> subsum(size+1); 
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];     // Sum of the subarray
                subsum[k++]=sum;   // Inserting the prefix sum at the index
            }
        }
        sort(subsum.begin(),subsum.end()); // Sorting the array
        for(int i=left; i<=right; i++)
        {
            ans=(ans+subsum[i])%m;   // ans modulo 10^9 +7
        }
        return ans;
    }
};

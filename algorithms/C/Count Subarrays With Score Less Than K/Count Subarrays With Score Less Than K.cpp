class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n=nums.size();
        vector<ll>v(n+1,0);
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1]+nums[i-1];
            // doing prefix sum.
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            int low=i;
            int high=n;
            int ans1=-1;
            // counting the number of sub arrays in which the current element is included by doing binary search.
			// The current element is the starting element of the subarrays we count.
            while(low<=high){
                int mid=low+(high-low)/2;
                ll sum=v[mid]-v[i-1];
                sum*=(mid-i+1);
                if(sum>=k){
                    high=mid-1;
                }
                else{
                   ans1=mid;
                   low=mid+1;
                }
            }
            if(ans1!=-1){
              ans+=(ans1-i+1);  
            }
        }
        return ans;
    }
};

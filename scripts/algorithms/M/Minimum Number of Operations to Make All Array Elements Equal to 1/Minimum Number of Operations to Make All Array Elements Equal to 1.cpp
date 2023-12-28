// Runtime: 0 ms (Top 100.0%) | Memory: 28.00 MB (Top 51.33%)

class Solution {
public:
    int gcd(int a, int b)
    {
	  if (b == 0)
	  {
	  	return a;
	  }
	  return gcd(b, a % b);
    }
    int findSmallestSubArr(vector<int> &arr, int n, int g){
        int ans=INT_MAX,gg=0;
        for(int i=0;i<n;i++){
            gg=arr[i];
            for(int j=i;j<n;j++){
                if(arr[j]%g!=0) break;
                gg=gcd(gg,arr[j]);
                if(gg==g){
                    ans=min(ans,j-i+1);
                }
            }
        }
        return ans==INT_MAX ? -1:ans;
    }
    int minOperations(vector<int>& nums) {
        int g=nums[0];
        int one=0;
        for(auto x:nums)
        {
            if(x==1) one++;
            g=gcd(g,x);
        }
        if(g>1) return -1;
        bool ok=false;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(gcd(nums[i],nums[i-1])==1){
                ok=true;
                break;
            }
        }
        if(ok) return n-one;
  
      int d= findSmallestSubArr(nums,n,1);
       int ans=d-1+n-1;
      return ans;
    }
};

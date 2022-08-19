// Runtime: 62 ms (Top 71.27%) | Memory: 22.3 MB (Top 64.84%)

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=0;
        for(int n:nums)r=max(r,n);

        int mid,s=0;
        while(l<r){
            s=0;
            mid = l+(r-l)/2;
            for(int n:nums){
                s+= n/mid + (n%mid !=0);
            }
            if(s<= threshold){
                r=mid;
            }else{
                l=mid+1;
            }

        }
        return r;
    }
};
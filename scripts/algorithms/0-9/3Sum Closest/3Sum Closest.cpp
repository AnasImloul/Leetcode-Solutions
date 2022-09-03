// Runtime: 516 ms (Top 46.24%) | Memory: 16.3 MB (Top 87.10%)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
        int n=nums.size(),ans;
        int diff=INT_MAX;
        for(int i=0;i<n-2;i++)// fixating the firstt element
        {
               int l=i+1, r= n-1;
               while(l<r)
               {
                   int sum =nums[i]+nums[l]+nums[r];
                   if(sum == target)return sum;
                   if(abs(sum-target)<diff)
                   { // updating the sum if sum so far. is closest to target
                      diff=abs(sum-target);
                      ans=sum;
                    }
                  (sum > target) ? r-- : l++;
               }
        }
        return ans;
    }
};
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int curr_max = INT_MIN, ret = 0, n = nums.size();
        int present[200001] = {0};
        for(int i=0; i<n; i++)
        {
            curr_max = max(curr_max, nums[i]);
            present[nums[i]]=1;
        }
        for(int i=1; i<=curr_max; i++)
        {
            int curr_gcd = 0;
            for(int j=i; j<=curr_max; j+=i)
            {
                if(present[j]==1)
                    curr_gcd = gcd(curr_gcd, j);
                if(curr_gcd==i)
                {
                    ret++;
                    break;
                }
            }
        }
        return ret;
    }
};

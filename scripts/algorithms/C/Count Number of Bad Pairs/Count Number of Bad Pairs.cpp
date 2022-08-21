// Runtime: 390 ms (Top 44.42%) | Memory: 83.7 MB (Top 91.38%)

class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        unordered_map<int,int> hash;
        long long goodpair_count=0;
        long long int n=nums.size();
        for(int i=0;i<nums.size();++i)
        {
            long long difference = i-nums[i];
            if(hash.count(difference)==1)
            {
                goodpair_count+= hash[difference];
                hash[difference]++;
            }
            else
                hash[difference]=1;
        }
        long long totalpair= (n*(n-1))/2;
        return totalpair-goodpair_count;
    }
};
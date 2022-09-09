// Runtime: 148 ms (Top 9.76%) | Memory: 31.7 MB (Top 49.45%)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // take an ans variable
        int ans = 0;
        // initialize a map of int, int and insert {0,1} as 0 occurs first time for sum
        unordered_map<int, int> mapp;
        mapp.insert({0,1});
        // initialize presum = 0 and remainder rem = 0 which will be used in further calculations
        int presum = 0;

        int rem = 0;

        // Logic
        /*
            1. We will traverse the entire given array/vector.
            2. While traversing we will add the element in our presum, i.e presum += nums[i] .
            3. Now we will do the % of presum and k and store it in rem that we have created.
            4. We need to take care of negative value of rem. If it is < 0, then we will add k to the remainder to make it positive.
            5. Now we will check if rem already exist in the map. If it exist then we will add it's frequency to ans variable
             and then increment rem's value in map, i.e. mapp[rem]++, else we will add it in the map.
            6. At last we will return ans.
        */

        for(int i=0; i<nums.size(); i++)
        {
            presum += nums[i];
            rem = presum % k;
            if(rem < 0)
                rem += k;

            if(mapp.find(rem) != mapp.end())
            {
                ans += mapp[rem];
                mapp[rem]++;
            }
            else
            {
                mapp.insert({rem,1});
            }
        }
        return ans;
    }
};
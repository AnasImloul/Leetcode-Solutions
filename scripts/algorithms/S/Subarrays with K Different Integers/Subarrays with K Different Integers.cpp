// Runtime: 286 ms (Top 33.47%) | Memory: 46.2 MB (Top 52.14%)
class Solution {
public:

    // function for finding the no. of subarrays which has at most k distinct integers

    int count_at_most_k(vector<int>& nums, int k)
    {
        int n = nums.size();

        int count = 0;

        unordered_map<int, int> mp;

        int left = 0;

        for(int right = 0; right < n; right++)
        {
            // increment the count of the curr element

            mp[nums[right]]++;

            // if no. of distinct elements is greater than k in a subarray

            // decrement the count from left side

            while(left <= right && mp.size() > k)
            {
                mp[nums[left]]--;

                if(mp[nums[left]] == 0)
                {
                    mp.erase(nums[left]);
                }

                left++;
            }

            // update the count

            count += right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int at_most_k = count_at_most_k(nums, k);

        int at_most_k_1 = count_at_most_k(nums, k - 1);

        // this will give the no. of subarrays which has exactly k distinct numbers

        return at_most_k - at_most_k_1;
    }
};
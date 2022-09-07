// Runtime: 354 ms (Top 21.70%) | Memory: 62.8 MB (Top 43.16%)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int max_ans = 0;
        map <int, int> mp;
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++) {

            mp[nums[i]] ++;

            while( mp.size() > 0 && abs(mp.rbegin()->first - mp.begin()->first) > limit)
            {

                if(mp[nums[j]] > 0) {
                    mp[nums[j]] --;
                }

                if(mp[nums[j]] == 0) {

                    mp.erase(nums[j]);
                }

                j++;
            }

            max_ans = max(max_ans, i - j + 1);
        }

        return max_ans;
    }
};
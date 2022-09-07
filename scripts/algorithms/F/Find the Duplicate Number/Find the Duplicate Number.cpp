// Runtime: 286 ms (Top 20.57%) | Memory: 61.3 MB (Top 61.82%)
                // Please upvote if it helps
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;

        }
        return low;
    }
    // for github repository link go to my profile.
};
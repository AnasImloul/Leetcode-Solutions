// Runtime: 135 ms (Top 66.06%) | Memory: 115.80 MB (Top 51.44%)

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        deque<int> minn, maxx; 
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        for (int right = 0; right < n; right++)
        {
            while (!maxx.empty() && nums[maxx.back()] < nums[right])  // Remove smaller elements from the maxx deque
                maxx.pop_back();
            maxx.push_back(right);  // Add the current index to the maxx deque

            while (!minn.empty() && nums[minn.back()] > nums[right])  // Remove larger elements from the minn deque
                minn.pop_back();
            minn.push_back(right);  // Add the current index to the minn deque

            while (nums[maxx.front()] - nums[minn.front()] > 2){
                if (maxx.front() < minn.front())  // Remove the leftmost maximum element if it is to the left of the minimum element
                    maxx.pop_front();
                else if (maxx.front() > minn.front())  // Remove the leftmost minimum element if it is to the left of the maximum element
                    minn.pop_front();
                else  // Remove both the leftmost maximum and minimum elements if they are at the same index
                    minn.pop_front(),
                    maxx.pop_front();
                left = max(left, min(maxx.front(), minn.front()));  // Update the left pointer to ensure the subarray has a difference of at most 2
            }
            int len = right - left + 1;  // Length of the current valid subarray
            ans += len;  // Add the length to the answer
        }
        return ans;  // Return the final answer
    }
};


// Runtime: 32 ms (Top 32.36%) | Memory: 12.4 MB (Top 70.15%)
// This Question Includes Both Binary Search And bit of Greedy Concept also.
// See We Know Ans Always Lies Between 0 and maximum element according to given question condition Because
// sum value at maximum element is same as any other element greater than it.
// So we get our sum from getval function after that you need to choose as to move forward(l = mid+1) or backward
// i.e.(h = mid-1) so if sum value we obtain is less than target then l = mid+1 why so??
// Because 2 3 5 lets suppose you are having this array if we pick 2 as mid then sum value will be 6 whereas if we pick 3 then sum value will be 8 and 10 when we pick 5 so notice that sum will increase when we increase value and
// correspondingly decrease when we decrease value...So yess This is all what we did and got Accepted.
class Solution {
public:
    int getval(int mid , vector<int>&arr)
    {
        int sum = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(arr[i] > mid)
                sum+=mid;
            else
                sum+=arr[i];
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0 , h = *max_element(arr.begin(),arr.end());
        int ans = 0, min1 = INT_MAX;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            int k = getval(mid,arr);
            if(k==target)
            {
                return mid;
            }
            else if(k<target)
            {
                l = mid+1;
            }
            else
                h = mid -1;

            int j = abs(k - target);
            if(j<min1)
            {
                min1 = j;
                ans = mid;
            }
            else if(j==min1)
            {
                ans = min(ans , mid);
            }
        }
        return ans;
    }
};
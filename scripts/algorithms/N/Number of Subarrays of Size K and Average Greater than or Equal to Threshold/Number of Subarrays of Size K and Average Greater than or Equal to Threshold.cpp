// Runtime: 62 ms (Top 83.1%) | Memory: 55.60 MB (Top 60.65%)

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int window_sum = 0;
        int count = 0;

        // step 1 : forming window sum for first window [starting at index (0) and ending at index (k - 1)]
        for(int i = 0 ; i < k ; ++i)
            window_sum += arr[i];
        
        // step 2 : loop through arr and find each window's average
        for(int i = 0 ; i < arr.size() - k + 1 ; ++i)
        {
            if(i != 0)
            {
                window_sum -= arr[i - 1];    // removing first element from prev window
                window_sum += arr[i + k - 1];// adding last + 1 elemnt in prev window
                // new window is ready
            }
            
            int window_average = window_sum / k;
            
            if(window_average >= threshold)
                count++;
        }
        
        return count;
        
    }
};

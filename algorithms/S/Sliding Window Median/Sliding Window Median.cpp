/*
    https://leetcode.com/problems/sliding-window-median/
    
    1. SOLUTION 1: Binary Search
    
    The core idea is we maintain a sorted window of elements. Initially we make the 1st window and sort all its elements.
    Then from there onwards any insertion or deletion is done by first finding the appropriate position where the element 
    exists/shoudl exist. This search is done using binary search.
    
    TC: O(klogk (Sorting) + (n - k) * (k + logk)), Binary search in window takes O(logk), but since it is array, insert or delete can take O(k)
    SC: O(k)
    
    2. SOLUTION 2: Height Balanced Tree
    
    Core idea is to use a height balanced tree to save all the elements of window. Since it is a height balanced tree, insertion and deletion takes
    logk. Now we directly want to reach the k/2 th element, then it takes O(k/2). So we need to optimize the mid point fetch.
    
    Initially when the 1st window is built, we find the middle element with O(k/2). Then from there onwards we always adjust the middle position
    by +1 or -1. Since only one element is either added or deleted at a time, so we can move the median left or right based on the situation.
    Eg: [1,2,3,4,5,6,7], median = 4
    
    if we add one element say 9
    [1,2,3,4,5,6,7,9], then check (9 < median): this means 1 extra element on right, don't move and wait to see what happens on deletion
    
    Similarly, now if 2 is deleted, we can just check (2 <= median(4)): this means there will be one less element on left.
    So move median to right by 1. If say an element on right like 7 was deleted, we would have not moved and hence the mid ptr would be 
    at its correct position.
    
    
        (1st window insertion) + remaining_windows * (delete element + add element + get middle)
    TC: O(klogk + (n-k) * (logk + logk + 1)) 
        ~O(klogk + (n-k)*logk) ~O(nlogk)
    SC: O(k)
*/
class Solution {
public:
    ///////////////////// SOLUTION 1: Binary Search
    vector<double> binarySearchSol(vector<int>& nums, int k) {
        vector<double> medians;
        vector<int> window;
        // K is over the size of array
        if(k > nums.size())
            return medians;
        
        int i = 0;
        // add the elements of 1st window
        while(i < k) {
            window.emplace_back(nums[i]);
            ++i;
        }
        
        // sort the window
        sort(window.begin(), window.end());
        // get the median of 1st window
        double median = k % 2 ? window[k / 2] : (double) ((double)window[k/2 - 1] + window[k/2]) / 2;
        medians.emplace_back(median);
        
        for(; i < nums.size(); i++) {
            // search the position of 1st element of the last window using binary search
            auto it = lower_bound(window.begin(), window.end(), nums[i - k]);
            window.erase(it);
            // find the position to insert the new element for the current window
            it = lower_bound(window.begin(), window.end(), nums[i]);
            window.insert(it, nums[i]);
            // Since the window is sorted, we can directly compute the median
            double median = k % 2 ? window[k / 2] : (double) ((double)window[k/2 - 1] + window[k/2]) / 2;
            medians.emplace_back(median);
        }
        return medians;
    }
    
    //////////////////////////// SOLUTION 2: Height Balanced Tree
    vector<double> treeSol(vector<int>& nums, int k) {
        multiset<int> elements;
        vector<double> medians;
        
        int i = 0;
        // process the 1st window
        while(i < k) {
            elements.insert(nums[i]);
            ++i;
        }
        
        // median of 1st window
        auto mid = next(elements.begin(), k / 2);
        double median = k % 2 ? *mid : ((double)*mid + *prev(mid)) / 2;
        medians.emplace_back(median);
        
        for(; i < nums.size(); i++) {
            // insert last element of current window
            elements.insert(nums[i]);
            // If the number lies on the left, left side will have 1 more element.
            // So shift left by 1 pos
            if(nums[i] < *mid)
                --mid;
            
            // remove 1st element of last window
            auto delete_pos = elements.find(nums[i - k]);
            // If the element to be deleted in [first : mid], then right will have extra element
            // so move the mid to right by 1
            // NOTE: We insert the new element and then delete previous element because, if the window has just one element
            // then deleting first will make mid point to invalid position. But inserting first will ensure that there is an 
            // element to point to
            if(nums[i-k] <= *mid)
                ++mid;
            elements.erase(delete_pos);
            
            double median = k % 2 ? *mid : ((double)*mid + *prev(mid)) / 2;
            medians.emplace_back(median);
        }
        
        return medians;
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // return binarySearchSol(nums, k);
        return treeSol(nums, k);
    }
};

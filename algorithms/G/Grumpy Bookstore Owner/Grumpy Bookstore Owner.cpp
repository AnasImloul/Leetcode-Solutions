/*
    https://leetcode.com/problems/grumpy-bookstore-owner/
    
    TC: O(N)
    SC: O(1)
    
    Looking at the problem, main thing to find is the window where the minutes should
    be used so that the owner is not grumpy and max customers in that window can be satisifed.
    
    Find the window with most no. of satisfied customers given the owner was originally grumpy but
    now has become not grumpy.
    Since the owner can only be not grumpy for minutes duration, this sets our window size as well.
    So with 'minutes' window size, find the max window.
    
    Then add the max window value with the normal satisfied customers.
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // Tracks the max window where being not grumpy will add most customers and current grumpy window customers
        int max_grumpy_window = 0, grumpy_window = 0;
        int curr = 0, n = customers.size();
        // Total satisifed customers when owner is not grumpy
        int satisfied_cx = 0;
        // net effective duration of not being grumpy
        minutes = min(minutes, n);
        
        // process the 1st window
        while(curr < minutes) {
            satisfied_cx += (!grumpy[curr] ? customers[curr] : 0);
            grumpy_window += (grumpy[curr] ? customers[curr] : 0);
            ++curr;
        }
        
        max_grumpy_window = max(max_grumpy_window, grumpy_window);
        // process the remaining windows
        while(curr < n) {
            // Remove the 1st element of last window
            grumpy_window -= (grumpy[curr - minutes] ? customers[curr - minutes] : 0);
            // Add the latest element of current window
            grumpy_window += (grumpy[curr] ? customers[curr] : 0);
            max_grumpy_window = max(max_grumpy_window, grumpy_window);
            
            satisfied_cx += (!grumpy[curr] ? customers[curr] : 0);
            ++curr;
        }
        
        return satisfied_cx + max_grumpy_window;
    }
};

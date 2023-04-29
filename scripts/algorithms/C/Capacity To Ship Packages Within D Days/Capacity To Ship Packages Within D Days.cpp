class Solution {
public:
    // function to check if it is possible to ship all the items within the given number of days using a given weight capacity
    bool isPossible(int cp, vector<int>& weights, int days)
    {
        int d = 1;
        int cw = 0;
        // iterate through the weights and check if it is possible to ship all the items
        for (auto x : weights) {
            if (x + cw <= cp) {
                // if the current weight can be added to the current capacity, add it
                cw += x;
            } else {
                // if not, increment the number of days required for shipping and start a new shipment
                d++;
                cw = x;
                if (x > cp) {
                    // if the current weight is greater than the current capacity, it is impossible to ship all the items
                    return false;
                }
            }
        }
        // check if it is possible to ship all the items within the given number of days
        return d <= days;
    }
    
    // function to find the minimum weight capacity required to ship all the items within the given number of days
    int shipWithinDays(vector<int>& weights, int days)
    {
        // initialize the search range for the weight capacity
        int s = 1;
        int e = 1E9;
        int ans = -1;
        
        // perform binary search on the weight capacity range
        while (s <= e) {
            // set the mid-point of the range as the current weight capacity
            int mid = (s + e) / 2;
            
            // check if it is possible to ship all the items within the given number of days using the current weight capacity
            bool ok = isPossible(mid, weights, days);
            
            // if it is possible to ship all the items within the given number of days using the current weight capacity,
            // set the current weight capacity as the new answer and reduce the upper bound of the weight capacity range
            if (ok) {
                ans = mid;
                e = mid - 1;
            } else {
                // if it is not possible to ship all the items within the given number of days using the current weight capacity,
                // increase the lower bound of the weight capacity range
                s = mid + 1;
            }
        }
        
        // return the minimum weight capacity required to ship all the items within the given number of days
        return ans;
    }
};

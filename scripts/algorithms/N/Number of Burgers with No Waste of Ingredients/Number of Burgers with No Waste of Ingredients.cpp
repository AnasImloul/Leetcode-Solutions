// Runtime: 13 ms (Top 17.35%) | Memory: 7.1 MB (Top 91.58%)
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // Observation
        // Total Number of Burgers is Equal to Number of cheeseSlices
        // Try to make 1 --> cheeseSlices Amount of Jumbo Burgers and
        // remaining will be Small Burger
        vector <int> ans;
        if(tomatoSlices == 0 and cheeseSlices == 0) {
            ans.push_back(0), ans.push_back(0);
            return ans;
        }
        // Do Binary Search to Get Ideal Division.
        int low = 0, high = cheeseSlices;
        while(low < high) {
            int mid = (low + high) / 2;
            int jumbo = mid, small = cheeseSlices - mid;
            // Jumbo needs 4 tomatoes per burger
            // Small needs 2 tomatoes per burger
            int needJumboTom = jumbo * 4;
            int needSmallTom = small * 2;
            // Should Add Upto tomatoSlices
            if(needJumboTom + needSmallTom == tomatoSlices) {
                ans.push_back(jumbo), ans.push_back(small);
                break;
            } else if(needJumboTom + needSmallTom < tomatoSlices) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return ans;
    }
};
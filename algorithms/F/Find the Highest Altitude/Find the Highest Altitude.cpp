class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt=0;
        int curr_alt=0;
        for(int i=0;i<gain.size();i++){
            curr_alt+=gain[i]; 
            max_alt=max(curr_alt, max_alt);
        }
        return max_alt;
    }
};

//TC: O(n), SC: O(1)

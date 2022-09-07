// Runtime: 260 ms (Top 5.36%) | Memory: 37.1 MB (Top 100.00%)
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int sum = 0;
        for (int i=ages.size()-1; i>=0; i--) {
            int cutoff = 0.5f * ages[i] + 7;
            int j = upper_bound(ages.begin(), ages.end(), cutoff) - ages.begin();
            int k = upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
            sum += max(0, k-j-1);
        }
        return sum;
    }
};
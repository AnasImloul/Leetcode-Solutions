// Runtime: 0 ms (Top 100.00%) | Memory: 6.3 MB (Top 62.31%)
/*
    https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

    Find the number of positions which are different.
    Now the strings can be made equal only if there are 0
    different positions or 2 different positions and there are
    chars on those positions which when swaped will make the
    strings equal.
    TC: O(N)
    SC: O(1), At most 2 values are put in the diff_pos vector
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // find the number of diff positions
        vector<int> diff_pos;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i])
                diff_pos.emplace_back(i);
            // If there are more than 2 char positions that differ,
            // the single swap op cannot anyway make the two strings equal
            if(diff_pos.size() > 2)
                return false;
        }
        // when the chars are exactly the same
        if(diff_pos.empty())
            return true;
        // only one pair of diff positions, check if swapping makes them equal
        if(diff_pos.size() == 2)
            swap(s1[diff_pos[0]], s1[diff_pos[1]]);

        return s1 == s2;
    }
};
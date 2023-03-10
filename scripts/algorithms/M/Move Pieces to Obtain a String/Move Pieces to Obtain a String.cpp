/*
    https://leetcode.com/problems/move-pieces-to-obtain-a-string/
    
    Thing to note here is the direction in which L and R can move. '_' can
    help them move. We just need to check that each L and R in start is in
    such a position from where it can match the corresponding L/R in target.
    
    Since L moves left, the position of start L should be >= target L
    Since R moves right, position of start R should be <= target R
    TC: O(m + n)
    SC: O(1)
*/
class Solution {
public:
    bool canChange(string start, string target) {
        int m = start.size(), n = target.size();
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            // skip all the _ chars
            while(i < m && start[i] == '_')
                ++i;
            while(j < n && target[j] == '_')
                ++j;
            // Either or both have reached the end
            if(i == m || j == n)
                break;
            // if the current chars are diff, not possible
            if(start[i] != target[j])
                return false;
            // L can only move left, if it is already behind it can't reach target L ahead
            if(start[i] == 'L' && i < j)
                return false;
            // R can only move right, if it alraedy ahead, it can't reach target R behind
            if(start[i] == 'R' && i > j)
                return false;
            ++i, ++j;
        }
        // In case some _ are left, skip them
        while(i < m && start[i] == '_')
            ++i;
        while(j < n && target[j] == '_')
            ++j;
        // Both the strings should not be pointing to any L or R
        return (i == m && j == n);
    }
};
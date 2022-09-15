// Runtime: 1 ms (Top 65.91%) | Memory: 42.9 MB (Top 74.91%)
class Solution {
    // Declare Global Variable ans to 0
    int ans = 0;
    // Depth First Search Function
    public int dfs(TreeNode root) {
        if(root == null) return 0;
        // recursive call for left height
        int lh = dfs(root.left);
        // recursive call for right height
        int rh = dfs(root.right);

        // update ans
        ans = Math.max(ans, lh + rh);

        // return max value
        return Math.max(lh, rh) + 1;
    }

    // Diameter of Binary Tree Function
    public int diameterOfBinaryTree(TreeNode root) {
        // Call dfs Function
        dfs(root);
        return ans;
    }
}

// Output -
/*
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
*/

// Time & Space Complexity -
/*
Time - O(n)
Space - O(n)
*/
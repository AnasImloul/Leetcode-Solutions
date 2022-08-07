class Solution {
    // Utility Function of RightSideView
    public void rightView(TreeNode curr, List<Integer> list, int level) {
        // if, current is null, return
        if(curr == null) {
            return;
        }
        
        // if, level = list size
        // add current val to list
        if(level == list.size()) {
            list.add(curr.val);
        }
        
        // recursive call for right side view
        rightView(curr.right, list, level + 1);
        // recursive call for left side view
        rightView(curr.left, list, level + 1);
    }
    
    // Binary Tree Right Side View Function
    public List<Integer> rightSideView(TreeNode root) {
        // create a list
        List<Integer> result = new ArrayList<>();
        // call right view function
        rightView(root, result, 0);
        return result;
    }
}

// Output -
/*
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/

// Time & Space Complexity -
/*
Time - O(n)
Space - O(h) h = height of binary tree
*/

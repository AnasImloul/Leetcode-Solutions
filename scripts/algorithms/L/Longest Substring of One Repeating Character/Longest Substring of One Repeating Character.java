// Runtime: 87 ms (Top 83.33%) | Memory: 76.70 MB (Top 22.22%)

class Solution {
    class TreeNode {
        //range
        int start;
        int end;
        
        //conti left char
        char leftChar;
        int leftCharLen;
        
        //conti right char
        char rightChar;
        int rightCharLen;
        
        int max;
        
        TreeNode left;
        TreeNode right;
        
        TreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            left = null;
            right = null;
        }
    }

    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        char[] sChar = s.toCharArray();
        char[] qChar = queryCharacters.toCharArray();
        
        TreeNode root = buildTree(sChar, 0, sChar.length - 1);
        
        int[] result = new int[qChar.length];
        
        for (int i = 0; i < qChar.length; i++) {
            updateTree(root, queryIndices[i], qChar[i]);
            result[i] = root.max;
        }
        return result;
    }
    
    private TreeNode buildTree(char[] s, int from, int to) {
        if (from > to) return null;
        TreeNode root = new TreeNode(from, to);
        if (from == to) {
            root.max = 1;
            root.rightChar = root.leftChar = s[from];
            root.leftCharLen = root.rightCharLen = 1;
            return root;
        }
        
        int middle = from + (to - from) / 2;
        
        root.left = buildTree(s, from, middle);
        root.right = buildTree(s, middle + 1, to);
        
        updateNode(root);
        return root;
        
    }
    
    private void updateTree(TreeNode root, int index, char c) {
        if (root == null || root.start > index || root.end < index) {
            return;
        }
        if (root.start == index && root.end == index) {
            root.leftChar = root.rightChar = c;
            return;
        }
        updateTree(root.left, index, c);
        updateTree(root.right, index, c);
        
        updateNode(root);
        
    }
    
    private void updateNode(TreeNode root) {
        if (root == null) return;
        root.leftChar = root.left.leftChar;
        root.leftCharLen = root.left.leftCharLen;
        root.rightChar = root.right.rightChar;
        root.rightCharLen = root.right.rightCharLen;
        root.max = Math.max(root.left.max, root.right.max);
        if (root.left.rightChar == root.right.leftChar) {
            int len = root.left.rightCharLen + root.right.leftCharLen;
            if (root.left.leftChar == root.left.rightChar && root.left.leftCharLen == root.left.end - root.left.start + 1) {
                root.leftCharLen = len;
            }
            if (root.right.leftChar == root.right.rightChar && root.right.leftCharLen == root.right.end - root.right.start + 1) {
                root.rightCharLen = len;
            }
            root.max = Math.max(root.max, len);
        }
    }
}

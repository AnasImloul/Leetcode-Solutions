// Runtime: 19 ms (Top 20.53%) | Memory: 72.3 MB (Top 15.91%)

class Solution {
    Map<Integer, Integer> map = new HashMap<>();

    public void go(TreeNode root, int level) {
        if(root == null) return;
        if(map.containsKey(level)) {
            map.put(level, map.get(level) + root.val);
        }
        else {
            map.put(level, root.val);
        }

        go(root.left, level+1);
        go(root.right, level+1);
    }
    public int maxLevelSum(TreeNode root) {
        go(root, 0);
        int max = Integer.MIN_VALUE, ind = -1;
        for (var i : map.entrySet()) {
            if(max < i.getValue()) {
                max = i.getValue();
                ind = i.getKey();
            }
        }
        return ind+1;
    }
}
// Runtime: 3 ms (Top 94.64%) | Memory: 42.3 MB (Top 95.72%)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {

    private static class MNode {
        TreeNode Node;
        int hDist;
        int level;
        MNode(TreeNode node, int hd, int l) {
            Node = node;
            hDist = hd;
            level = l;
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Map<Integer, PriorityQueue<MNode>> map = new TreeMap<>();
        Queue<MNode> q = new LinkedList<>();

        q.add(new MNode(root, 0, 0));

        while(!q.isEmpty()) {

            MNode curr = q.poll();
            if(map.containsKey(curr.hDist))
                  map.get(curr.hDist).add(curr);

            else {
                PriorityQueue<MNode> pq = new PriorityQueue<>
                    ((a,b) -> (a.level == b.level)? a.Node.val - b.Node.val: a.level - b.level);
                pq.add(curr);
                map.put(curr.hDist, pq);
            }

            if(curr.Node.left != null)
                q.add(new MNode(curr.Node.left, curr.hDist -1, curr.level + 1));

            if(curr.Node.right != null)
                q.add(new MNode(curr.Node.right, curr.hDist +1, curr.level + 1));
        }

        List<List<Integer>> ans = new ArrayList<>();
        for(Integer key: map.keySet()) {
            List<Integer> temp = new ArrayList<>();
            while(!map.get(key).isEmpty()) { temp.add(map.get(key).poll().Node.val); }
            ans.add(new ArrayList<>(temp));
        }

        return ans;

    }

}
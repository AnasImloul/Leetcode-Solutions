// Runtime: 7 ms (Top 66.25%) | Memory: 45 MB (Top 29.77%)
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        HashMap<Long, Integer> hm = new HashMap<>();
        //hm.put(0L,1); ---> can use this to handle initial condition if c_sum == target sum

        int res = solve(hm, root, targetSum, 0);

        return res;
    }

    public int solve(HashMap<Long, Integer> hm, TreeNode node, long tgt, long c_sum) {

        if(node == null)
            return 0;

        c_sum += node.val;

        int res = 0;

        if(c_sum == tgt) //--> either this condition or the above commented condition.
            res++;

        if(hm.containsKey(c_sum-tgt)){
            res += hm.get(c_sum-tgt);
        }

        hm.put(c_sum, hm.getOrDefault(c_sum,0)+1);

        int left = solve(hm, node.left, tgt, c_sum);
        int right = solve(hm, node.right, tgt, c_sum);

        res += (left+right);

        hm.put(c_sum, hm.getOrDefault(c_sum,0)-1); //remove the calculated cumulative sum

        return res;

    }

}

// Runtime: 1 ms (Top 100.00%) | Memory: 43.9 MB (Top 94.53%)
class Solution {
    List<TreeNode>[] memo;
    public List<TreeNode> allPossibleFBT(int n) {
        memo = new ArrayList[n+1];
        return dp(n);
    }

    public List<TreeNode> dp(int n){
        if(n==0 || n==2){
            return new ArrayList<TreeNode>();
        }
        if(n==1){
            List<TreeNode> temp = new ArrayList<>();
            temp.add(new TreeNode(0));
            return temp;
        }
        List<TreeNode> res = new ArrayList<>();
        for(int i=1;i<n-1;i=i+2){
            List<TreeNode> right;
            List<TreeNode> left;
            if(memo[i]!=null) right = memo[i];
            else right = dp(i);
            if(memo[n-1-i]!=null) left = memo[n-1-i];
            else left = dp(n-1-i);

            for(TreeNode l : left){
                for(TreeNode r : right){
                    TreeNode temp = new TreeNode(0);
                    temp.left=l;
                    temp.right=r;
                    res.add(temp);
                }
            }
         }
        memo[n] = res;
        return res;

    }
}
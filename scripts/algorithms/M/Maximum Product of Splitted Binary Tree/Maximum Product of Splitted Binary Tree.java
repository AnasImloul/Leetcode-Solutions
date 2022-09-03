// Runtime: 12 ms (Top 82.12%) | Memory: 70.1 MB (Top 38.32%)
class Solution {
    public void findMaxSum(TreeNode node,long sum[]){
        if(node==null) return ;

        findMaxSum(node.left,sum);
        findMaxSum(node.right,sum);

        sum[0]+=node.val;

    }

    public long findProd(TreeNode node,long sum[],long []max){
        if(node==null) return 0;

        long left=findProd(node.left, sum, max);
        long right=findProd(node.right,sum,max);

        long val=left+right+node.val;

        max[0]=Math.max(max[0],val*(sum[0]-val));

        return val;
    }
    public int maxProduct(TreeNode root) {

        long max[]=new long[1];
        long sum[]=new long[1];

        findMaxSum(root,sum);

       long n= findProd(root,sum,max);

        return (int)(max[0]%((int)1e9+7));
    }
}
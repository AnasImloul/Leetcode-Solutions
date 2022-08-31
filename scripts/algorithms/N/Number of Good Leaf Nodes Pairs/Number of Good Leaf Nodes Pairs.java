// Runtime: 86 ms (Top 15.89%) | Memory: 53.6 MB (Top 51.73%)
class Solution {
    static int res;
    public int countPairs(TreeNode root, int distance) {
        res=0;
        rec(root,distance);
        return res;
    }
    static List<Integer> rec(TreeNode root,int dist){
        if(root==null){
            return new LinkedList<Integer>();
        }
        List<Integer> left=rec(root.left,dist);
        List<Integer> right=rec(root.right,dist);
        if(left.size()==0&&right.size()==0){
            List<Integer> temp=new LinkedList<>();
            temp.add(1);
            return temp;
        }
        for(int i:left){
            for(int j:right){
                if(i+j<=dist){
                    res++;
                }
            }
        }
        List<Integer> temp=new LinkedList<>();
        for(int i:left){
            temp.add(i+1);
        }
        for(int i:right){
            temp.add(i+1);
        }
        return temp;
    }
}
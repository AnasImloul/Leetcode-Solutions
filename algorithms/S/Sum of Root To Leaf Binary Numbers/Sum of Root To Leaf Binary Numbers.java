class Solution {
    List<String> l = new ArrayList<>();
    public int sumRootToLeaf(TreeNode root) {
        func(root,"");
        int sum=0;
        for(int i=0;i<l.size();i++){
            sum+=func2(l.get(i));
        }
        return sum;
    }
    public void func(TreeNode root,String str){
        if(root.right==null && root.left==null){
            str+=root.val;
            l.add(str);
            return;
        }
        str+=root.val;
        if(root.right!=null){func(root.right,str);}
        if(root.left!=null){func(root.left,str);}
    }
    public int func2(String s){
        int temp = 0;
        for(int i=0;i<s.length();i++){
            temp+=((int)s.charAt(i)-48)*Math.pow(2,s.length()-1-i);
        }
        return temp;
    }
}

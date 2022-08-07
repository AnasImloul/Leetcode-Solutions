public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String data="";
        Queue<TreeNode> q=new LinkedList<>();
        if(root!=null)
        q.add(root);
        else
         return "";
        data=Integer.toString(root.val)+"e";
        while(!q.isEmpty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode node=q.poll();
                if(node.left!=null)
                {
                    data=data+Integer.toString(node.left.val)+"e";
                    q.add(node.left);
                }
                else
                    data=data+"N"+"e";
                if(node.right!=null)
                {
                    data=data+Integer.toString(node.right.val)+"e";
                    q.add(node.right);
                }
                else
                    data=data+"N"+"e";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.length()==0)
            return null;
        int i=0;
        String s="";
        while(data.charAt(i)!='e')
            s=s+data.charAt(i++);
        int d=Integer.parseInt(s);
        TreeNode root=new TreeNode(d);
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        while(i<data.length() && !q.isEmpty())
        {
            int size=q.size();
            for(int j=0;j<size;j++)
            {
                s="";
                i++;
                TreeNode node=q.poll();
                while(data.charAt(i)!='e')
                   s=s+data.charAt(i++);
                if(s.equals("N"))
                    node.left=null;
                else
                {
                    TreeNode l=new TreeNode(Integer.parseInt(s));
                    node.left=l;
                    q.add(l);
                }
                s="";
                i++;
                while(data.charAt(i)!='e')
                   s=s+data.charAt(i++);
                if(s.equals("N"))
                    node.right=null;
                else
                {
                    TreeNode r=new TreeNode(Integer.parseInt(s));
                    node.right=r;
                    q.add(r);
                }
            }
        }
        return root;
        
    }
}

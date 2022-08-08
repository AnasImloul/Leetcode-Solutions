class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        HashMap<TreeNode,TreeNode> map=new HashMap<>();
        get_parent(root,map);
        Queue<TreeNode> q=new LinkedList<>();
        q.add(target);
        int distance=0;
        HashSet<TreeNode> visited=new HashSet<>();
        visited.add(target);
        while(!q.isEmpty())
        {
            if(distance==k)
                break;
            distance++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode current=q.poll();
                if(current.left!=null && !visited.contains(current.left))
                {
                    q.add(current.left);
                    visited.add(current.left);
                }
                if(current.right!=null && !visited.contains(current.right))
                {
                    q.add(current.right);
                    visited.add(current.right);
                }
                if(map.containsKey(current) && !visited.contains(map.get(current)))
                {
                    q.add(map.get(current));
                    visited.add(map.get(current));
                }
                
            }
        }
        List<Integer> ans=new ArrayList<>();
        while(!q.isEmpty())
            ans.add(q.poll().val);
        return ans;
        
    }
    public void get_parent(TreeNode root,HashMap<TreeNode,TreeNode> map)
    {
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode current=q.poll();
                if(current.left!=null)
                {
                    map.put(current.left,current);
                    q.add(current.left);
                }
                if(current.right!=null)
                {
                    map.put(current.right,current);
                    q.add(current.right);
                }
            }
        }
    }
}

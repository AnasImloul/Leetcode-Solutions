class Solution {
    
        public TreeNode sortedListToBST(ListNode head) {
            
            ListNode tmp = head;
            ArrayList<Integer> treelist = new ArrayList<>();
            
            while(tmp != null) {
                treelist.add(tmp.val);
                tmp = tmp.next;
            }
            
            return createTree(treelist, 0, treelist.size()-1);
        }
    
        public TreeNode createTree(ArrayList<Integer> treelist, int start, int end) {
            
            if(start > end)
                return null;
            
            int mid = start + (end-start)/2;
            
            TreeNode node = new TreeNode(treelist.get(mid));//getNode(treelist.get(mid));
            
            node.left = createTree(treelist, start, mid-1);
            node.right = createTree(treelist, mid+1, end);
            return node;
        }
}

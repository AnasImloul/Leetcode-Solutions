var lowestCommonAncestor = function(root, p, q) {
    while(root){
        if(p.val>root.val && q.val>root.val){
            root=root.right
        }else if(p.val<root.val && q.val<root.val){
            root=root.left
        }else{
            return root
        }
    }
}

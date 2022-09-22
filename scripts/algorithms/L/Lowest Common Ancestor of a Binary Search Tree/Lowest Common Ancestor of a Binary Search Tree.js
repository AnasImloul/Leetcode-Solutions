// Runtime: 138 ms (Top 36.23%) | Memory: 52 MB (Top 81.19%)
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
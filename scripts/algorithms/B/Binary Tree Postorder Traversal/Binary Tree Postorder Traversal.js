// Runtime: 72 ms (Top 78.56%) | Memory: 42.1 MB (Top 54.23%)
class Pair{
    constructor(node, state){
        this.node = node;
        this.state = state;
    }
}
var postorderTraversal = function(root) {
    let ans = [];
    let st = []; // stack
    root != null && st.push(new Pair(root, 1));

    while(st.length > 0){
        let top = st[st.length - 1];

        if(top.state == 1){

            top.state++;
            if(top.node.left != null){
                st.push(new Pair(top.node.left, 1))
            }
        } else if(top.state == 2){
            top.state++;
            if(top.node.right != null){
                st.push(new Pair(top.node.right, 1))
            }
        } else{
            ans.push(top.node.val);
            st.pop();
        }
    }
    return ans;
};
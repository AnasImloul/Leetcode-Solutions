/**
 * @param {number[]} arr
 * @return {number}
 */
var oddEvenJumps = function(arr) {
    let result = 0;
    const len = arr.length
    const map = {} // { value: index }
    const memo = new Array(2).fill(null).map(i => new Array(len).fill(false))
    
    // Build a BST to maintain logN search/Insert
    function treeNode(value) {
        this.val = value;
        this.left = null;
        this.right = null;
    }
    
    const root = new TreeNode(arr[len - 1])
    
    function InsertToBST(val) {
        function dfs(node){
            if(node.val < val) {
                if(!node.right) node.right = new TreeNode(val);
                else dfs(node.right);
            }
            if(node.val > val) {
                if(!node.left) node.left = new TreeNode(val);
                else dfs(node.left);
            }
        }
        
        dfs(root);
    }
    
    
    
    
    memo[0][len - 1] = memo[1][len - 1] = true;
    map[arr[len - 1]] = len - 1;
    
    //memo[0] odd jumps
    //memo[1] even jumps
    
    function getNextBig(base) { // odd jump
        if(map[base] !== undefined) {
            return base
        }
        let result = Infinity
        function dfs(node) {
            if(!node) return;
            
            if(node.val > base && node.val < result) {
                result = node.val;
                dfs(node.left)
            }
            
            if(node.val < base) {
                dfs(node.right);
            }
        }
        
        dfs(root)
        
        return result === Infinity ? false : result;
    }
    
    function getNextSmall(base) { //even jump
        if(map[base] !== undefined) {
            return base
        }
        let result = -Infinity
        function dfs(node) {
            if(!node) return;
            
            if(node.val < base && node.val > result) {
                result = node.val;
                dfs(node.right)
            }
            
            if(node.val > base) {
                dfs(node.left);
            }
        }
        
        dfs(root)
        
        return result === -Infinity ? false : result;
    }
    
    for(let i = len - 2; i >= 0; i--) {
        let nextBig = getNextBig(arr[i])
        let nextSmall = getNextSmall(arr[i])
        
        memo[0][i] = nextBig ? memo[1][map[nextBig]] : nextBig;
        memo[1][i] = nextSmall ? memo[0][map[nextSmall]] : nextSmall;
        map[arr[i]] = i;
        InsertToBST(arr[i])
    }

    return memo[0].filter(boo => boo).length
    
};

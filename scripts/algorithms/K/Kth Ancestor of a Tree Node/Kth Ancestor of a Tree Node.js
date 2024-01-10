// Runtime: 354 ms (Top 80.0%) | Memory: 113.40 MB (Top 40.0%)

/**
 * @param {number} n
 * @param {number[]} parent
 */


let par;
var TreeAncestor = function(n, parent) {
  let p = new Array(n);
    for(let i=0;i<n;i++){
           p[i] = new Array(20);
       }
    
        for(let i=0;i<n;i++){
            p[i][0] = parent[i];
        }
    
    for(let j=1;j<20;j++){
        for(let i=0;i<n;i++){
            if(p[i][j-1]==-1){
                p[i][j]= -1;
            }
            else{
                p[i][j] = p[p[i][j-1]][j-1];
            }
        
        }
    }
    par = p;
}
/** 
 * @param {number} node 
 * @param {number} k
 * @return {number}
 */
TreeAncestor.prototype.getKthAncestor = function(node, k) {
    
        for(let i=0;i<20;i++){
            if((k>>i)&1){
                node = par[node][i];
                if(node==-1){
                    return -1;
                }
            }
        }
    return node;
    
};

/** 
 * Your TreeAncestor object will be instantiated and called as such:
 * var obj = new TreeAncestor(n, parent)
 * var param_1 = obj.getKthAncestor(node,k)
 */


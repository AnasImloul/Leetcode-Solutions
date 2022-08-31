// Runtime: 470 ms (Top 40.74%) | Memory: 79.4 MB (Top 70.37%)
/**
 * @param {number} n
 * @param {number[][]} relations
 * @param {number[]} time
 * @return {number}
 */
var minimumTime = function(n, relations, time) {
    /*
    Approach: We can create reverse edges for relation.
&nbsp; &nbsp; Then longest path(by weightage of time for each node) from the node will be the minimum time to finish that course(node)
&nbsp; &nbsp; Now we can use simple DFS to find the longest path for each node.
&nbsp; &nbsp; The node containing the longest path will be course to finish the last.We can also use memo to save the longest path from node, so when we reach to this node, we need not to calculate the longest path again.&nbsp;
    */
    let edges={};
    for(let i=0;i<relations.length;i++){
        if(edges[relations[i][1]]===undefined){
            edges[relations[i][1]] = [];
        }
        edges[relations[i][1]].push(relations[i][0]);
    }

    let max=0,timeRequired,memo={};
    for(let i=1;i<=n;i++){
        timeRequired = longestPath(i);
        max = Math.max(max,timeRequired);
    }
    return max;
     function longestPath(node){
         if(memo[node]!==undefined){
             return memo[node];
         }
        let len,max=0;
         if(edges[node]!==undefined){
             for(let i=0;i<edges[node].length;i++){
                 len = longestPath(edges[node][i]);
                 max = Math.max(max,len);
             }
         }
         memo[node] = time[node-1]+max;//use memo to save the longest path from node, so when we reach to this node, we need not to calculate the longest path again
         return memo[node];
    }

};
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findSmallestSetOfVertices = function(n, edges) {
    let indegree=[];
    for(let i=0;i<n;i++){
        indegree.push(0);
    }
    let ans=[];
    for( const arr of edges ){
        indegree[arr[1]]++;
    }
    for(let i=0;i<n;i++){
        if(indegree[i]==0){
            ans.push(i);
        }
    }
    return ans;
};

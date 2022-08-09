    var cnvrtAdjLst = (mat) => {//converts the list of edges to adjacency list
    let map = new Map();
    for(let i=0; i<mat.length; i++){
        let [p,c] = mat[i];
        if(map[p]===undefined) map[p] = [c];
        else map[p].push(c);

        if(map[c]===undefined) map[c] = [p];
        else map[c].push(p);
    }
    return map;
}
var minTime = function(n, edges, hasApple) {
    let adjList = cnvrtAdjLst(edges);//convert to adjacency list for undirected graph
    let visited = new Set();// visited set for checking trivial loop
    let dfsForApples = (src, len) => {
        visited.add(src);// add root to visited set, as we start exploring the subtree
        let lengthFromNow = 0;//total length of path visited by each child, 0 if no child has apple
        for(let i in adjList[src]){
            if(!visited.has(adjList[src][i])){
                lengthFromNow += dfsForApples(adjList[src][i],len+1);// add child path length to total length
            }

        }
        if(lengthFromNow>0){
            //if there is an apple present in the subtree
            return lengthFromNow + 2;
        }
        else if(hasApple[src]){
            //if there is no apple in subtree but apple is present on the root node
            return 2;
        }
        else{
            // if no apple is present in subtree
            return 0;
        }
    }
    visited.add(0);
    let res = dfsForApples(0,0);
    return res?res-2:0;//check if the root node itself has an apple or no apple is present
};
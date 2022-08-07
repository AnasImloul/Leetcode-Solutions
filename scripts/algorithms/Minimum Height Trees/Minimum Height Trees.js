var findMinHeightTrees = function(n, edges) {
  
    //edge case
    if(n <=0) return [];
    if(n === 1) return [0]
  
  
    let graph ={}
    let indegree  = Array(n).fill(0)
    let leaves = []
    // build graph
    
    for(let [v,e] of edges){
      //as this is undirected graph we will build indegree for both e and v
      if(!(v in graph)) graph[v] = [];
      if(!(e in graph)) graph[e] = [];
      graph[v].push(e)
      graph[e].push(v)
      indegree[v]++
      indegree[e]++
    }
  
  
  // get all nodes with indegree 1
    for(let i =0; i<indegree.length; i++){
      if(indegree[i] === 1) leaves.push(i)
    }
  
  
    let total  = n;
  
    while(total > 2){
      let size = leaves.length
      // as we are removing nodes from our  total
      total -= size;
      
      for(let i =0 ; i<size; i++){
        let vertex = leaves.shift()
        for(let edge of  graph[vertex] ){
          indegree[edge]--
          if(indegree[edge] === 1) leaves.push(edge)
        }
      }
    }
  
  return leaves;
    
};

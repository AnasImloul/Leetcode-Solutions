function dfs(edges,s=`JFK`,ans=[`JFK`]){  //run dfs, starting node being `JFK`
    if(!edges[s] || edges[s].length==0){  //if currenctly reached node has its adjacent list empty
        let isAllTravelled=1;
        Object.values(edges).forEach(ele=> {if(ele.length>0) isAllTravelled=0}) // check if every edge has been travelled i.e all adjacentLists should be empty
         if(!isAllTravelled) return false;   //returns false when there are more edges to travel , but from current node we cannot move anywhere else 
        else return  ans; // return true if from current node we cannot move anywhere else and all the edges have been travelled as well
    }
    
    let myAL= edges[s].sort();  // sort the Adjacency List  of current node lexicographically
    for(let i=0;i<myAL.length;i++){ // start by taking the lexicographically smallest node and run dfs
        ans.push(myAL[i]);  // add current node into answer array
        edges[s]= [...edges[s].slice(0,edges[s].indexOf(myAL[i])),...edges[s].slice(edges[s].indexOf(myAL[i])+1)]; // remove the currently edges travelled from adjacency List 
        let xx= dfs(edges,myAL[i],ans); //here runs the dfs
        if(!xx){ // if dfs result of current node could not travel all edges from current node
            ans.pop(); // pop out current accounted node from answer
            edges[s].push(myAL[i]);  //put back the edge into adjacency list assmuing we should not visit this edge at this point as it doesnt leads to answer from here currenlt
        }
        else return xx ; // if dfs result of current node could travel all edges from current node return the answer array
    } 
}
var findItinerary = function(tickets) {
    let edges={}; //our adjacency list
    tickets.forEach(ticket=>{
       if(!edges[ticket[0]]){
            edges[ticket[0]]=[];
        }
        edges[ticket[0]].push(ticket[1]);
    })
   
    let ans= dfs(edges); // run dfs 
    return ans;
};

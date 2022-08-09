/**
 * @param {number[][]} bombs
 * @return {number}
 */
var maximumDetonation = function(bombs) {
    if(bombs.length <= 1) return bombs.length;
    
    let adj = {}, maxSize = 0;
    const checkIfInsideRange = (x, y, center_x, center_y, radius) =>{
        return ( (x-center_x)**2 + (y-center_y)**2 <= radius**2 ) 
    }
	
	//CREATE ADJACENCY MATRIX
    for(let i = 0;i<bombs.length;i++){
        for(let j = i+1;j<bombs.length;j++){
            if(!adj[i]) adj[i] = [];
            if(!adj[j]) adj[j] = [];
            let bombOne = bombs[i];
            let bombTwo = bombs[j];
            let fir = checkIfInsideRange(bombOne[0], bombOne[1], bombTwo[0], bombTwo[1], bombOne[2]);     
            if(fir) adj[i].push(j);
            let sec = checkIfInsideRange(bombOne[0], bombOne[1], bombTwo[0], bombTwo[1], bombTwo[2]);
            if(sec) adj[j].push(i);
        }
    }
	
	//DEPTH FIRST SEARCH TO FIND ALL BOMBS TRIGGERED BY NODE
    const dfs = (node, visited)=>{
        let detonated = 1;
        visited[node] = true;
        let childs = adj[node] || []
        for(let child of childs){
            if(visited[child]) continue;
            detonated += dfs(child, visited)
        }
        maxSize = Math.max(maxSize, detonated)
        return detonated;
    }
    
    for(let i = 0 ;i<bombs.length;i++){
        dfs(i, {})
    }
    return maxSize
};

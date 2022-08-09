var catMouseGame = function(graph) {
    let n=graph.length,
        memo=[...Array(n+1)].map(d=>[...Array(n+1)].map(d=>[...Array(2*n+1)])),
        seen=[...Array(n+1)].map(d=>[...Array(n+1)].map(d=>[...Array(2)]))
    //dfs returns 0 1 2, whether the current player loses,wins, or draws respectively
    let dfs=(M,C,level)=>{
        let turn=level%2,curr=turn?C:M,draw=0,res=0
        //draw when we ve seen the state before or cycles
        if(seen[M][C][turn]!==undefined||level>=2*n) 
            return memo[M][C][level]=2 
        if(M==0)// win for mouse if it reaches the hole, loss for cat
            memo[M][C][level]=turn^1
        if(M==C)// win for cat if it reaches the mouse, loss for mouse
            memo[M][C][level]=turn 
        if(memo[M][C][level]===undefined){
            seen[M][C][turn]=0 //set this state as visited
            for(let i=0;i<graph[curr].length&&!res;i++) //traverse for the available edges
                if( !(turn&&(!graph[curr][i]))){ //The cat cant move into the hole
                    let val=turn?
                            dfs(M,graph[curr][i],level+1):
                            dfs(graph[curr][i],C,level+1)
                    if(val===2) 
                        draw=1 //set draw as an available option
                    else
                        res|=(1^val) //minimax logic, always prefer the losing state of the opponent
                }
            memo[M][C][level]=res||(2*draw) // set in this order 1->2->0 
        }
        seen[M][C][turn]=undefined;// de-set the state for the current game,as it concluded
        return memo[M][C][level]
    }
    return [2,1,0][dfs(1,2,0)] //js eye candy
};

// Runtime: 107 ms (Top 32.92%) | Memory: 43.9 MB (Top 83.84%)
function dfs(current,all,visited){
    if(visited.size==all.length){
        return true;
    }
    for(let i=0;i<all[current].length;i++){
        if(!visited.has(all[current][i])){
            visited.add(all[current][i]);
            if(dfs(all[current][i],all,visited))
                return true;
        }

    }
    return false;

}
var canVisitAllRooms = function(rooms) {
    let visited=new Set();
    visited.add(0);
    if (dfs(0,rooms,visited)) return true;
    return false;
};

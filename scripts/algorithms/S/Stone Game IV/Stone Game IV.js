var winnerSquareGame = function(n) {
    
    const map = new Map();
    map.set(0, false);
    map.set(1, true);
    
    const dfs = (num) => {
        if( map.has(num) ) return map.get(num);
        let sqRoot = Math.floor(Math.sqrt(num));
        
        for(let g=1; g<=sqRoot; g++){
            if( !dfs(num - (g*g)) ) {
                map.set(num, true);
                return true;
            }    
        }
        map.set(num, false);
        return false;
    }
    
    return dfs(n)
};

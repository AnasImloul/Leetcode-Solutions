const dist = function(from, to){
    if(from==-1) return 0; 
    const d1 = Math.abs((from.charCodeAt(0)-65)%6-(to.charCodeAt(0)-65)%6),
          d2 = Math.abs(Math.floor((from.charCodeAt(0)-65)/6)-Math.floor((to.charCodeAt(0)-65)/6));
    return d1 + d2;
}
var minimumDistance = function(word) {

    const dp = new Map();
    
    const dfs = function(i, lpos, rpos){
        if(i==word.length) 
            return 0;
        const key = [i,lpos,rpos].join(',');
        if(dp.get(key)) 
            return dp.get(key);
        dp.set(key, Math.min(dist(lpos,word[i])+dfs(i+1,word[i],rpos), dist(rpos,word[i])+dfs(i+1,lpos,word[i])));
        return dp.get(key);
    }
    return dfs(0, -1, -1);
};

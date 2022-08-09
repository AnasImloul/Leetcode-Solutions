var maxLengthBetweenEqualCharacters = function(s) {
    
    const map = new Map();
    let max=-1;
    for(let i=0;i<s.length;i++){

        if(map.has(s[i])){
            max=Math.max(max,i-(map.get(s[i])+1))
        }else{
            map.set(s[i],i)    
        }
        
    }
    return max;
};

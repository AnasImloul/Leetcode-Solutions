// Runtime: 128 ms (Top 66.24%) | Memory: 44.7 MB (Top 73.31%)
var findRelativeRanks = function(score) {
    let output=score.slice(0);
    let map={};
    score.sort((a,b)=>b-a).forEach((v,i)=>map[v]=i+1);
    for(let item in map){
        if(map[item]==1){map[item]="Gold Medal"};
        if(map[item]==2){map[item]="Silver Medal"};
        if(map[item]==3){map[item]="Bronze Medal"};
    }
    return output.map(v=>map[v]+""); // +"": num=>str.
};
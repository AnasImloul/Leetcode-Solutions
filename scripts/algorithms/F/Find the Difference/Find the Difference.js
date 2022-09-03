// Runtime: 131 ms (Top 17.65%) | Memory: 45.7 MB (Top 18.28%)
var findTheDifference = function(s, t) {
    var map = {};
    var re = "";
    for(let i = 0; i < t.length; i++){
        if(t[i] in map){
            map[t[i]] += 1;
        }else{
            map[t[i]] = 1;
        }
    }

    for(let i = 0; i < s.length; i++){
        if(s[i] in map){
            map[s[i]] -= 1;
        }
    }

    for(let [key, value] of Object.entries(map)){
        if(value > 0){
            let temp = re.concat(key);
            re = temp;
        }
    }
    return re;
};
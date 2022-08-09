var goodDaysToRobBank = function(security, time) {
    let res = [];
    if(!time){
       let i = 0;
        while(i<security.length) res.push(i), i++;
        return res;
    }
    let increasing = 0;
    let decreasing = 0;
    let set = new Set();
    for(let i = 1; i < security.length; i++){
        if(security[i]>security[i-1]) decreasing = 0;
        else decreasing++;
        if(security[i]<security[i-1]) increasing = 0;
        else increasing++;
        if(decreasing>=time) set.add(i);
        if(increasing>=time&&set.has(i-time)) res.push(i-time);
    }
    return res;
};

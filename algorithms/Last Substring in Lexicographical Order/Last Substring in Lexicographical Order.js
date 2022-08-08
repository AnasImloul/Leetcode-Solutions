var lastSubstring = function(s) { 
    let res = 0;
    for(let i = 1; i < s.length; i++){
        if(s.slice(i) > s.slice(res)) res = i;     
    };
    return s.slice(res);
};

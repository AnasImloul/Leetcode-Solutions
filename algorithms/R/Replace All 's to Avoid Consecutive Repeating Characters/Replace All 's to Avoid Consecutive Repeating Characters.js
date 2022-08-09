var modifyString = function(s) {
    let t="";
    for(let i=0; i<s.length; i++){
        if(s[i]=="?"){
            let j="a";
            while(t[i-1]==j || s[i+1]==j){j=String.fromCharCode(j.charCodeAt()+1)};
            t+=j;
        }else{
            t+=s[i];
        }
    }
    return t;
};

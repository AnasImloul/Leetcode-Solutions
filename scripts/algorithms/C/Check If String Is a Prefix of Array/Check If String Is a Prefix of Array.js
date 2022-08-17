var isPrefixString = function(s, words) {
    let str = words[0];
    if(s === words[0]){
        return true;
    }
    for(let i=1; i < words.length; i++){
        if(s === str){
            return true;
        }
        if( s.startsWith(str)){
            str += words[i]; 
            continue;       
        }else{
            return false;
        }
    }
    if(s !== str){
            return false;
        }
    return true;    
};

var strStr = function(haystack, needle) {
    
    if(needle.length == 0){
        return 0;
    }
    
    for(let i = 0; i < haystack.length; i++){
        if(haystack.indexOf(needle) == -1){
            return -1;
        }
    }
	
    return haystack.indexOf(needle);
	
};

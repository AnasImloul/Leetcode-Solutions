var countPrefixes = function(words, s) {
  
    let cont = 0;
    
    for(i = 0; i < words.length; i++){
        for(j = 1; j <= s.length; j++){
            if(words[i] == s.slice(0, j)){
                cont++;
            }
        }        
    }
     return cont;
    
};

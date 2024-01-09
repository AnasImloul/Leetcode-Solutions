// Runtime: 44 ms (Top 89.61%) | Memory: 42.10 MB (Top 16.23%)

var kthGrammar = function(N, K) {
    
    if( N == 1){
        // Base case
        return 0;
    }
    
    // General case
    if( K % 2 == 0 ){
        // even index of current level is opposite of parent level's [(K+1)//2]
        return 1 - kthGrammar( N-1, (K+1)>>1 );
        
    }else{
        // odd index of current level is the same as parent level's [(K+1)//2]
        return kthGrammar( N-1, (K+1)>>1 );
    }
    
    
};

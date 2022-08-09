var strangePrinter = function(s) {
    if(!s) return 0;

    const N = s.length;    
    const state = Array.from({length:N}, () => Array.from({length:N}));
    
    for(let i = 0; i < N; i++) {
        // Printing one character always takes one attempt
        state[i][i] = 1;
    }
    
    const search = (i,j) => {
        if(state[i][j]) return state[i][j];
        
        state[i][j] = Infinity;
        for(let k = i; k < j; k++) {
            state[i][j] = Math.min(state[i][j], search(i,k) + search(k+1,j));
        }
        if(s[i] === s[j]) state[i][j]--;
        return state[i][j];
    }
    
    return search(0, N-1);
}

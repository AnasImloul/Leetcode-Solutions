var specialArray = function(nums) {
    const freq = new Array(1001).fill(0);
    for(let n of nums)
        freq[n]++;
    
    for(let i=1000, cnt=0; i>=0; i--){
        cnt += freq[i];
        if(i==cnt) return i;
    }
    
    return -1;
};

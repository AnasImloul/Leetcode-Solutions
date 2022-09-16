// Runtime: 151 ms (Top 59.59%) | Memory: 49.8 MB (Top 86.99%)
var numberOfBeams = function(bank) {
    let before = 0,after = 0,total = 0;
    for(i=0;i<bank.length;i++){
        for(j=0;j<bank[i].length;j++){
            if(bank[i][j] === '1'){
                after ++;
            }
        }
        if(after > 0){
            if(before === 0){
                before = after;
            }else{
                total += before*after;
                before = after;
            }
        }
        after = 0;
    }
    return total
};
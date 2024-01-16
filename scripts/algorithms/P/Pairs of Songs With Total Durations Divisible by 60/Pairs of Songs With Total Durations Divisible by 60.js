// Runtime: 53 ms (Top 94.39%) | Memory: 47.10 MB (Top 9.35%)

var numPairsDivisibleBy60 = function(time) {
    let num=0;
    let arr=new Array(60).fill(0);

    for(let i of time){
        let k=i%60;

        if(k===0)
            num+=arr[k];
        else
            num+=arr[60-k];
        
        arr[k]++;
    }
    return num;
};

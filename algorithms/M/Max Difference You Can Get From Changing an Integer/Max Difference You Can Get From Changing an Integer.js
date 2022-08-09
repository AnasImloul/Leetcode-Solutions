var maxDiff = function(num) {
    let occur = undefined;
    let max = num.toString().split("");
    let min = num.toString().split("");
    for(i=0;i<max.length;i++){
        if(max[i]<9&&!occur){
            occur = max[i];
            max[i] = 9;
        }
        if(max[i]===occur) max[i] = 9;
    }
    occur = undefined;
    let zerone;
     for(i=0;i<min.length;i++){
        if(!occur&&min[i]>1){
            occur = min[i];
            if(i===0) zerone = 1;
            else zerone = 0;
            min[i] = zerone;      
        }    
        if(min[i]===occur) min[i] = zerone;
    }
    return +max.join("")-+min.join("");
};

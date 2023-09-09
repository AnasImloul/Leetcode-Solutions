// Runtime: 68 ms (Top 51.6%) | Memory: 62.02 MB (Top 6.6%)

var bestClosingTime = function(customers) {
    // Calculate prefix sums of Ys and Ns
    const prefY=[customers[0]==='N'?0:1];
    const prefN=[customers[0]==='N'?1:0];
    for(let i=1;i<customers.length;i++){
        prefY[i]=prefY[i-1]+(customers[i]==='N'?0:1);
        prefN[i]=prefN[i-1]+(customers[i]==='N'?1:0);
    }

    // Get sum of all Ys to the right, if day=0 we return amount of all Ys inclusive
    const getYSum=(day)=>day===0?prefY[prefY.length-1]:prefY[prefY.length-1]-prefY[day-1];

    // Get sum of all Ns to the left, if this is the last day we return all Ns inclsive
    const getNSum=(day)=>day===0?0:prefN[day-1];

    let penalty=Number.MAX_SAFE_INTEGER, minHour=Number.MAX_SAFE_INTEGER;
    // we iterate from right to left in order to correctly capture 
    for(let i=customers.length;i>=0;i--){
        const fee=getYSum(i)+getNSum(i);
        if(penalty>=fee){
            penalty=fee;
            minHour=i; // since we iterating from the end, we always get minimum day
        }
    }
    return minHour;
};
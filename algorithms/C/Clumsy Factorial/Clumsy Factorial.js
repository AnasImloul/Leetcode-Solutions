/**
 * @param {number} n
 * @return {number}
 */
 var clumsy = function(n) {
    let res = 0;
    let count = 0;
    let sum = n;
    let tmp = [];
    let flag = true;
    for(let i=n-1; i>=1; i--){
        if(count === 0){
            sum = sum * i;
            count ++;
        }else if(count === 1){
            sum = parseInt(sum / i);
            count ++;
        }else if(count === 2){
            if(flag){
                sum = sum + i;
            }else{
                sum = sum - i;
            }
            count ++;
        }else if(count === 3){
            flag = false;
            tmp.push(sum);
            sum = i;
            count = 0;
        }
    }
    
    tmp.push(sum);
    res = tmp[0];
    for(let i=1; i<tmp.length; i++){
        res -= tmp[i];
    }
    
    return res;
};

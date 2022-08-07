/**
 * @param {number} turnedOn
 * @return {string[]}
 */
var readBinaryWatch = function(turnedOn) {
    // _ _ _ _ 0-11 => 0000 - 1100
    // _ _ _ _ _ _ 0-59 => 111011
    
    let minutes = new Map();
    let hours = new Map();
    for(let i = 0; i < 12; i++){
        let ones = 0;
        for(let j = 0; j < 5; j++){
            ones += (i>>j) &1;
        }
        if(hours.has(ones)){
            prev = hours.get(ones);
            prev.push(i)
            hours.set(ones,prev);
        }else{
            hours.set(ones, [i]);
        }
        //0001 1
        //0010 2
        //0011 3
        //0100 4
        //0101 5
        //0110 6
        //0111 7
        //1000 8
        //1001 9
        //1010 10
        //1011 11
        
    }
    
    for(let i = 0; i < 60; i++){
        let ones = 0;
        for(let j = 0; j < 7; j++){
            ones += (i>>j) &1;
        }
        
        if(minutes.has(ones)){
            let prev = minutes.get(ones);
            prev.push(i);
            minutes.set(ones,prev)
        }else{
            minutes.set(ones,[i]);
        }
    }
    let result = [];
    for(let i = 0; i <= turnedOn; i++){
        if(hours.has(i)){
            let h = hours.get(i)
            for(let j = 0; j < h.length; j++){
                let ones = turnedOn - i;
                if(minutes.has(ones)){
                    let min = minutes.get(ones)
                    for(let k = 0; k < min.length; k++){
                        let minlen = (min[k]+"").length;
                        if(minlen == 1){
                            minlen = "0"+min[k];
                        }else{
                            minlen = min[k]
                        }
                        result.push(h[j]+":"+minlen);
                    }
                }
            }
        }
    }
    return result;
};

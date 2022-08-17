/**
 * @param {string} s
 * @return {number}
 */
var minOperations = function(s) {
    let counter1=0;
    let counter2=0;
    for(let i=0;i<s.length;i++){
        if(i%2===0){
            if(s[i]==="0"){
                counter1++;
            }
            if(s[i]==="1"){
                counter2++;
            }
        }
        if(i%2===1){
            if(s[i]==="1"){
                counter1++;
            }
            if(s[i]==="0"){
                counter2++;
            }
        }
    }
    return Math.min(counter1,counter2);
};

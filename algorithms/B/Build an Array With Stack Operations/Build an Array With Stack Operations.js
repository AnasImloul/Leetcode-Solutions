/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
    let arr = [];
    let index = 0;
    for(let i = 1; i <= target[target.length-1];i++){
        if(target[index] == i){
            arr.push('Push');
            index++;
        }else{
            arr.push('Push');
            arr.push('Pop');
        }
    }
    return arr;
};
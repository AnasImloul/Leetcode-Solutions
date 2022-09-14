// Runtime: 78 ms (Top 90.91%) | Memory: 42.4 MB (Top 65.91%)
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var maximumScore = function(a, b, c) {
    let resultArray = [];
    resultArray.push(a);
    resultArray.push(b);
    resultArray.push(c);
    resultArray.sort((a,b)=>a-b);
    let counter=0;
    while(resultArray[0]>0||resultArray[1]>0||resultArray[2]>0){
        if(resultArray[0]===0&&resultArray[1]===0){
            break;
        }
        resultArray[1]--;
        resultArray[2]--;
        counter++
        if(resultArray[1]<resultArray[0]){
            exchange(resultArray,1,0);
        }
        if(resultArray[2]<resultArray[0]){
            exchange(resultArray,2,0);
        }
    }
    if(resultArray[0]+resultArray[1]+resultArray[2]===0) return counter;
    if(resultArray[0]<0||resultArray[1]<0||resultArray[2]<0) counter--;
    return counter;

    function exchange(array, indexa,indexb){
        let temp = array[indexa];
        array[indexa] = array[indexb];
        array[indexb] = temp;
    }

};
// Runtime: 298 ms (Top 20.37%) | Memory: 77.6 MB (Top 7.41%)
/**
 * @param {string} binary
 * @return {string}
 */
var maximumBinaryString = function(binary) {
    /*
    10 -> 01 allows us to move any zero to left by one position
    00 -> 10 allows us to convert any consicutive 00 to 10
    So we can collect all the zeros together then convert them in 1 except for the rightmost 0
    We will club all the zeros togegher on the rightmost possition, to achieve the biggest value, then covert them into 1 except for the rightmost 0
    So we need to choose indexOfFirstZero as the starting possition of the group of zeros
    If there is no 0 then given string is the maximum possible string
    If there are 1 or more zeros
        Then there will be only 1 zero in the answer
        Position of this will be indexOfFirstZero in given string + countOfZeros - 1
    */
    let firstZeroIndex=-1,zeroCount=0,ans="";
    for(let i=0;i<binary.length;i++){
        if(binary[i]==='0'){
            zeroCount++;
            if(firstZeroIndex===-1){
                firstZeroIndex=i;
            }
        }
    }
    if(firstZeroIndex==-1){
        return binary;
    }
    let onlyZeroInAns = firstZeroIndex + (zeroCount-1);
    for(let i=0;i<binary.length;i++){
        if(i==onlyZeroInAns){
            ans+="0";
        }
        else{
            ans+="1";
        }
    }
    return ans;
};